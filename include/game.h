/**
 * @file game.h
 * @brief 이 파일은 게임을 실행하는 함수를 정의합니다.
 * @authors 윤현중, 홍솔아, 이진우, 송해든, 최수길
 * @date 2024-03-26
 */

#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "utility.h"
#include "db.h"

/**
 * @brief 카드를 쌍으로 배치하기 위한 초기화 로직 보드 전체 길이의 1/2 만큼의 카드쌍을 생성
 */
void initializeBoard();

/**
 * @brief 카드를 섞기 위한 로직
 */
void shuffleCards(int *array, int size);

/**
 * @brief 보드를 출력하는 함수
 */
void printBoard(int cursorPosition);

/**
 * @brief 사용자의 입력을 처리하는 함수
 */
void processInput(int *cursorPosition, int *selectedCards, int *selectedCount);

/**
 * @brief 선택된 카드가 일치하는지 확인하는 함수
 */
void checkMatch(int *selectedCards, int *selectedCount);

/**
 * @brief 게임을 실행하는 함수
 */
void play_game();

int getch();

#endif
