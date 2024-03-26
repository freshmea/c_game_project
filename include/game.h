#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "utility.h"

#define IMG_HEIGHT 7
#define IMG_WIDTH 18
#define MAX_IMAGES 16
#define BOARD_SIZE 4
#define BOARD_AREA (BOARD_SIZE * BOARD_SIZE)

void initializeBoard();
void shuffleCards(int *array, int size);
void printBoard(int cursorPosition);
void processInput(int *cursorPosition, int *selectedCards, int *selectedCount);
void checkMatch(int *selectedCards, int *selectedCount);
void play_game();


#endif
