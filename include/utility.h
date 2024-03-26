#ifndef UTILITY_H
#define UTILITY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

#define IMG_HEIGHT 7
#define IMG_WIDTH 18
#define MAX_IMAGES 16
#define BOARD_SIZE 4
#define BOARD_AREA (BOARD_SIZE * BOARD_SIZE)

void enableRawMode();
void disableRawMode();
void display_credits();
void display_images();

extern char images[MAX_IMAGES][IMG_HEIGHT][IMG_WIDTH + 1];
int getch();
#endif
