#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "game.h"

// 화면 초기화
void clearScreen(void)
{
#ifdef _WIN32
    system("cls");
#else
    printf("\033[2J\033[H");
#endif
}

// 문자열 입력
int readLine(char* buffer, size_t capacity)
{
    char* newline;

    if (capacity == 0 || fgets(buffer, (int)capacity, stdin) == NULL)
    {
        return 0;
    }

    newline = strchr(buffer, '\n');

    if (newline != NULL)
    {
        *newline = '\0';
    }
    else
    {
        int ch = getchar();

        if (ch != '\n' && ch != EOF)
        {
            while ((ch = getchar()) != '\n' && ch != EOF)
            {
            }

            buffer[0] = '\0';
        }
    }

    {
        size_t length = strlen(buffer);

        if (length > 0 && buffer[length - 1] == '\r')
        {
            buffer[length - 1] = '\0';
        }
    }

    return 1;
}

// Enter 입력 대기
void waitForEnter(const char* message)
{
    char input[8];

    printf("\n---------------------------------\n");
    printf("%s", message);

    (void)readLine(input, sizeof(input));
}

// 단서 추가
static void addClue(GameState* state, const char* clue)
{
    if (state->clueCount < MAX_CLUES)
    {
        snprintf(
            state->clues[state->clueCount],
            CLUE_LENGTH,
            "%s",
            clue
        );

        state->clueCount++;
    }
}

// 게임 초기화
void initGame(GameState* state)
{
    memset(state, 0, sizeof(*state));

    addClue(
        state,
        "잠긴 서랍: 세 글자 영어 비밀번호가 필요하다."
    );
}

// 단서 목록 출력
void showClues(const GameState* state)
{
    int i;

    printf("=================================\n");
    printf("             CLUES\n");
    printf("=================================\n\n");

    if (state->clueCount == 0)
    {
        printf("아직 수집한 단서가 없습니다.\n");
        return;
    }

    for (i = 0; i < state->clueCount; i++)
    {
        printf("[%d] %s\n",
            i + 1,
            state->clues[i]);
    }
}

// 게임 설명
void showGuide(void)
{
    printf("=================================\n");
    printf("           GAME GUIDE\n");
    printf("=================================\n\n");

    printf("PROJECT-404: 사라진 연구노트\n\n");

    printf("1. 연구실에 남은 단서로 암호를 풀어야 합니다.\n");
    printf("2. 퍼즐에서 H를 입력하면 힌트를 볼 수 있습니다.\n");
    printf("3. 퍼즐에서 C를 입력하면 단서 목록을 볼 수 있습니다.\n");
    printf("4. 퍼즐마다 오답 3번이면 미완성 엔딩으로 끝납니다.\n");
    printf("5. 두 퍼즐을 모두 풀면 최종 결정을 내릴 수 있습니다.\n");
}

// 입력 문자열을 대문자로 변경
static void makeUppercase(char* text)
{
    int i;

    for (i = 0; text[i] != '\0'; i++)
    {
        text[i] = (char)toupper(
            (unsigned char)text[i]
        );
    }
}

// 시저 암호 복호화
static void decodeCaesar(
    const char* cipher,
    char* decoded,
    int shift)
{
    int i;

    for (i = 0; cipher[i] != '\0'; i++)
    {
        char ch = cipher[i];

        if (ch >= 'A' && ch <= 'Z')
        {
            decoded[i] = (char)(
                'A' + (ch - 'A' - shift + 26) % 26
                );
        }
        else
        {
            decoded[i] = ch;
        }
    }

    decoded[i] = '\0';
}

// 첫 번째 퍼즐
static int playPuzzle1(GameState* state)
{
    int wrong = 0;
    char answer[32];

    while (wrong < 3)
    {
        clearScreen();

        printf("=================================\n");
        printf("         PUZZLE 1 / 2\n");
        printf("=================================\n\n");

        printf("[잠긴 서랍]\n\n");
        printf("서랍에 적힌 문구:\n");
        printf("'열쇠'를 뜻하는 영어 단어 세 글자를 입력하라.\n\n");

        printf("오답: %d / 3\n", wrong);
        printf("정답 입력 (H: 힌트 / C: 단서): ");

        if (!readLine(answer, sizeof(answer)))
        {
            return 0;
        }

        makeUppercase(answer);

        // 힌트 확인
        if (strcmp(answer, "H") == 0)
        {
            printf("\n[힌트] K로 시작하는 단어입니다.\n");

            waitForEnter(
                "Enter를 누르면 다시 도전합니다..."
            );

            continue;
        }

        // 단서 확인
        if (strcmp(answer, "C") == 0)
        {
            clearScreen();
            showClues(state);

            waitForEnter(
                "Enter를 누르면 퍼즐로 돌아갑니다..."
            );

            continue;
        }

        // 빈 문자열 처리
        if (answer[0] == '\0')
        {
            printf("\n[!] 정답을 입력해 주세요.\n");

            waitForEnter(
                "Enter를 누르면 다시 도전합니다..."
            );

            continue;
        }

        // 정답 판정
        if (strcmp(answer, "KEY") == 0)
        {
            state->puzzle1Solved = 1;

            addClue(state, "서랍 속 암호문: QRWH");

            addClue(
                state,
                "암호문 옆 메모: 알파벳을 3칸 되돌려라."
            );

            printf("\n[정답] 잠긴 서랍이 열렸습니다!\n");
            printf("새 단서 'QRWH'와 메모를 획득했습니다.\n");

            waitForEnter(
                "Enter를 누르면 다음 퍼즐로 이동합니다..."
            );

            return 1;
        }

        // 오답 처리
        wrong++;

        printf("\n[오답] 다시 생각해 보세요. (%d / 3)\n", wrong);

        if (wrong < 3)
        {
            waitForEnter(
                "Enter를 누르면 다시 도전합니다..."
            );
        }
    }

    return 0;
}

// 두 번째 퍼즐
static int playPuzzle2(GameState* state)
{
    int wrong = 0;
    char answer[32];
    char correct[16];

    decodeCaesar("QRWH", correct, 3);

    while (wrong < 3)
    {
        clearScreen();

        printf("=================================\n");
        printf("         PUZZLE 2 / 2\n");
        printf("=================================\n\n");

        printf("[연구노트의 암호]\n\n");
        printf("발견한 암호문: QRWH\n");
        printf("규칙: 각 영문자를 알파벳 순서에서 3칸 앞으로 되돌리기\n\n");

        printf("오답: %d / 3\n", wrong);
        printf("해독한 단어 입력 (H: 힌트 / C: 단서): ");

        if (!readLine(answer, sizeof(answer)))
        {
            return 0;
        }

        makeUppercase(answer);

        // 힌트 확인
        if (strcmp(answer, "H") == 0)
        {
            printf("\n[힌트] Q는 N으로 바뀝니다.\n");

            waitForEnter(
                "Enter를 누르면 다시 도전합니다..."
            );

            continue;
        }

        // 단서 확인
        if (strcmp(answer, "C") == 0)
        {
            clearScreen();
            showClues(state);

            waitForEnter(
                "Enter를 누르면 퍼즐로 돌아갑니다..."
            );

            continue;
        }

        // 빈 문자열 처리
        if (answer[0] == '\0')
        {
            printf("\n[!] 정답을 입력해 주세요.\n");

            waitForEnter(
                "Enter를 누르면 다시 도전합니다..."
            );

            continue;
        }

        // 정답 판정
        if (strcmp(answer, correct) == 0)
        {
            state->puzzle2Solved = 1;

            addClue(
                state,
                "연구노트를 복구했다. 공개 여부를 결정해야 한다."
            );

            printf("\n[정답] 암호 해독 성공!\n");
            printf("정답은 %s입니다.\n", correct);
            printf("사라진 연구노트의 내용을 되찾았습니다.\n");

            waitForEnter(
                "Enter를 누르면 최종 선택으로 이동합니다..."
            );

            return 1;
        }

        // 오답 처리
        wrong++;

        printf("\n[오답] 다시 생각해 보세요. (%d / 3)\n", wrong);

        if (wrong < 3)
        {
            waitForEnter(
                "Enter를 누르면 다시 도전합니다..."
            );
        }
    }

    return 0;
}

// 미완성 엔딩
static void showIncompleteEnding(GameState* state)
{
    state->ending = 3;

    clearScreen();

    printf("=================================\n");
    printf("        INCOMPLETE ENDING\n");
    printf("=================================\n\n");

    printf("오답이 3회 누적되어 추적이 중단되었습니다.\n");
    printf("연구노트의 비밀은 아직 밝혀지지 않았습니다.\n");
    printf("메인 메뉴에서 다시 도전할 수 있습니다.\n");
}

// 최종 선택과 엔딩
static void chooseEnding(GameState* state)
{
    char choice[32];

    while (1)
    {
        clearScreen();

        printf("=================================\n");
        printf("          FINAL CHOICE\n");
        printf("=================================\n\n");

        printf("연구노트를 복구했습니다.\n");
        printf("이제 선택해야 합니다.\n\n");

        printf("[1] 연구 결과를 공개한다.\n");
        printf("[2] 연구 결과를 보관한다.\n\n");

        printf("선택 >> ");

        if (!readLine(choice, sizeof(choice)))
        {
            return;
        }

        if (strcmp(choice, "1") == 0 ||
            strcmp(choice, "2") == 0)
        {
            state->ending =
                (choice[0] == '1') ? 1 : 2;

            break;
        }

        printf("\n[!] 1 또는 2를 입력해 주세요.\n");

        waitForEnter(
            "Enter를 누르면 다시 선택합니다..."
        );
    }

    clearScreen();

    // 공개 엔딩
    if (state->ending == 1)
    {
        printf("=================================\n");
        printf("           PUBLIC ENDING\n");
        printf("=================================\n\n");

        printf("연구 결과가 세상에 공개되었습니다.\n");
        printf("사라진 노트의 진실도 밝혀졌습니다.\n");
    }
    // 보관 엔딩
    else
    {
        printf("=================================\n");
        printf("           SECRET ENDING\n");
        printf("=================================\n\n");

        printf("연구노트를 안전하게 보관하기로 했습니다.\n");
        printf("연구 내용은 지금은 비밀로 남습니다.\n");
    }

    printf("\n게임을 완료했습니다!\n");
}

// 전체 게임 시작
void startGame(GameState* state)
{
    // 새 게임 초기화
    initGame(state);

    clearScreen();

    printf("=================================\n");
    printf("           PROLOGUE\n");
    printf("=================================\n\n");

    printf("연구실에서 중요한 연구노트가 사라졌습니다.\n");
    printf("잠긴 서랍과 짧은 암호문이 유일한 단서입니다.\n");
    printf("단서를 모아 비밀번호를 풀고 노트를 찾아보세요.\n");

    waitForEnter(
        "Enter를 누르면 첫 번째 퍼즐을 시작합니다..."
    );

    // 첫 번째 퍼즐
    if (!playPuzzle1(state))
    {
        showIncompleteEnding(state);
        return;
    }

    // 두 번째 퍼즐
    if (!playPuzzle2(state))
    {
        showIncompleteEnding(state);
        return;
    }

    // 최종 엔딩
    chooseEnding(state);
}