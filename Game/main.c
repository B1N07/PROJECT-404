#include <stdio.h>
#include <string.h>
#include "game.h"

// 메인 메뉴 출력
static void showMenu(void)
{
    printf("=================================\n");
    printf("          PROJECT-404\n");
    printf("         사라진 연구노트\n");
    printf("=================================\n\n");

    printf("  [1] 게임 시작\n");
    printf("  [2] 단서 확인\n");
    printf("  [3] 게임 설명\n");
    printf("  [0] 게임 종료\n\n");

    printf("---------------------------------\n");
    printf("선택 >> ");
}

int main(void)
{
    GameState state;
    char input[32];

    initGame(&state);

    while (1)
    {
        clearScreen();
        showMenu();

        if (!readLine(input, sizeof(input)))
        {
            break;
        }

        clearScreen();

        if (strcmp(input, "1") == 0)
        {
            startGame(&state);
            waitForEnter("Enter를 누르면 메인 메뉴로 돌아갑니다...");
        }
        else if (strcmp(input, "2") == 0)
        {
            showClues(&state);
            waitForEnter("Enter를 누르면 메인 메뉴로 돌아갑니다...");
        }
        else if (strcmp(input, "3") == 0)
        {
            showGuide();
            waitForEnter("Enter를 누르면 메인 메뉴로 돌아갑니다...");
        }
        else if (strcmp(input, "0") == 0)
        {
            printf("=================================\n");
            printf("           GAME OVER\n");
            printf("=================================\n\n");
            printf("게임을 종료합니다.\n");
            break;
        }
        else
        {
            printf("=================================\n");
            printf("             ERROR\n");
            printf("=================================\n\n");
            printf("[!] 올바른 메뉴 번호를 입력하세요.\n");
            waitForEnter("Enter를 누르면 메인 메뉴로 돌아갑니다...");
        }
    }

    return 0;
}