#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 콘솔 화면 초기화
void clearScreen(void)
{
    system("cls");
}

// Enter 입력 대기
void waitForEnter(void)
{
    char input[32];

    printf("\n---------------------------------\n");
    printf("Enter를 누르면 메뉴로 돌아갑니다...");

    fgets(input, sizeof(input), stdin);
}

// 메인 메뉴 출력
void showMenu(void)
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
    char input[32];

    while (1)
    {
        // 1. 메인 화면 표시
        clearScreen();
        showMenu();

        // 2. 사용자 입력
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            break;
        }

        // 입력이 너무 길면 나머지 입력 제거
        if (strchr(input, '\n') == NULL)
        {
            int ch;

            while ((ch = getchar()) != '\n' && ch != EOF)
            {
            }

            input[0] = '\0';
        }
        else
        {
            // 입력 문자열의 줄바꿈 제거
            input[strcspn(input, "\n")] = '\0';
        }

        // 3. 선택 결과 화면으로 전환
        clearScreen();

        if (strcmp(input, "1") == 0)
        {
            printf("=================================\n");
            printf("           GAME START\n");
            printf("=================================\n\n");

            // 추후 game.c의 게임 시작 함수 연결
            printf("게임 시작 기능을 준비 중입니다.\n");
        }
        else if (strcmp(input, "2") == 0)
        {
            printf("=================================\n");
            printf("             CLUES\n");
            printf("=================================\n\n");

            // 추후 game.c의 단서 확인 함수 연결
            printf("아직 수집한 단서가 없습니다.\n");
        }
        else if (strcmp(input, "3") == 0)
        {
            printf("=================================\n");
            printf("           GAME GUIDE\n");
            printf("=================================\n\n");

            printf("[게임 설명]\n\n");
            printf("PROJECT-404: 사라진 연구노트\n\n");
            printf("1. 사건의 단서를 조사합니다.\n");
            printf("2. 숨겨진 암호를 해독합니다.\n");
            printf("3. 선택에 따라 결말이 달라집니다.\n");
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
        }

        // 4. 메뉴로 복귀
        waitForEnter();
    }

    return 0;
}