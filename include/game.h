#ifndef GAME_H
#define GAME_H

#define IMG_HEIGHT 7
#define IMG_WIDTH 18
#define MAX_IMAGES 16
#define BOARD_SIZE 4
#define BOARD_AREA (BOARD_SIZE * BOARD_SIZE)

extern char images[MAX_IMAGES][IMG_HEIGHT][IMG_WIDTH + 1];
extern int board[BOARD_AREA];
extern int revealedCards[BOARD_AREA];
extern int score;

void initializeBoard();
void shuffleCards(int *array, int size);
void printBoard(int cursorPosition);
void processInput(int* cursorPosition, int* selectedCards, int* selectedCount);
void checkMatch(int* selectedCards, int* selectedCount);
void play_game();

#endif
