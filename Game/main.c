#include <stdio.h>
//아무거나 하는거지//ddkdkdkdk//
int main(void) 
{
    int menu;

    do
    {
        printf("\n========== PROJECT-404 ==========\n");
        printf("1. 게임 시작\n");
        printf("2. 게임 설명\n");
        printf("0. 게임 종료\n");
        printf("=================================\n");
        printf("메뉴 선택: ");

        if (scanf_s("%d", &menu) != 1)
        {
            printf("숫자를 입력해야 합니다.\n");
            break;
        }

        switch (menu)
        {
        case 1:
            printf("\n게임을 시작합니다!\n");
            printf("추리 게임은 아직 개발 중입니다.\n");
            break;

        case 2:
            printf("\n단서를 조사하고 암호를 해독하는 게임입니다.\n");
            break;

        case 0:
            printf("\n게임을 종료합니다.\n");
            break;

        default:
            printf("\n올바른 메뉴 번호를 선택하세요.\n");
            break;
        }

    } while (menu != 0);

    return 0;
}