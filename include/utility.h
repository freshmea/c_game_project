#ifndef UTILITY_H
#define UTILITY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

#define IMG_HEIGHT 7
#define IMG_WIDTH 18
#define MAX_IMAGES 16

void enableRawMode();
void disableRawMode();
void display_credits();
void display_images();

extern char images[MAX_IMAGES][IMG_HEIGHT][IMG_WIDTH + 1];
#endif
