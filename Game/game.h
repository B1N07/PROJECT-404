#ifndef GAME_H
#define GAME_H

#include <stddef.h>

#define MAX_CLUES 5
#define CLUE_LENGTH 100

// 게임 진행 상태 구조체
typedef struct
{
    char clues[MAX_CLUES][CLUE_LENGTH];
    int clueCount;
    int puzzle1Solved;
    int puzzle2Solved;
    int ending;
} GameState;

// 게임 관련 함수
void initGame(GameState* state);
void startGame(GameState* state);
void showClues(const GameState* state);
void showGuide(void);

// 화면 및 입력 관련 함수
void clearScreen(void);
void waitForEnter(const char* message);
int readLine(char* buffer, size_t capacity);

#endif