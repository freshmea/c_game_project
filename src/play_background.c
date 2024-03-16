#include <stdio.h>
#include <ao/ao.h>
#include <mpg123.h>
#include <pthread.h>

#define BITS 8

extern int game; // 전역 변수 0 일 때 GAME_START, 1 일 때 GAME_END

void *play_music(void *arg)
{

    mpg123_handle *mh;
    unsigned char *playbuffer;
    size_t playbuffer_size;
    size_t done;
    int err;

    int driver;
    ao_device *dev;

    ao_sample_format format;
    int channels, encoding;
    long rate;

    // Initialize libraries
    ao_initialize();
    mpg123_init();
    mh = mpg123_new(NULL, &err);
    mpg123_open(mh, "/home/aa/c_game_project/sound/bgm_tetris.mp3");
    mpg123_getformat(mh, &rate, &channels, &encoding);

    // Set the output format
    format.bits = mpg123_encsize(encoding) * BITS;
    format.rate = rate;
    format.channels = channels;
    format.byte_format = AO_FMT_NATIVE;
    format.matrix = 0;
    driver = ao_default_driver_id();

    dev = ao_open_live(driver, &format, NULL);

    // Decode and play
    playbuffer_size = mpg123_outblock(mh);
    playbuffer = (unsigned char *)malloc(playbuffer_size * sizeof(unsigned char));

    while (game != 1) // Check the value of 'game'
    {
        while (mpg123_read(mh, playbuffer, playbuffer_size, &done) == MPG123_OK)
        {
            if (game == 1) // Check the value of 'game'
            {
                break; // Stop playing music
            }
            else
            {
                ao_play(dev, playbuffer, done);
            }
        }

        mpg123_seek(mh, 0, SEEK_SET); // Reset the song to the beginning
    }

    // Clean up
    free(playbuffer);
    ao_close(dev);
    mpg123_close(mh);
    mpg123_delete(mh);
    mpg123_exit();
    ao_shutdown();

    return NULL;
}
