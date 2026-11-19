# PROJECT-404

### 사라진 연구노트 | The Missing Research Note

![C](https://img.shields.io/badge/Language-C-A8B9CC?logo=c&logoColor=white)
![Visual Studio](https://img.shields.io/badge/IDE-Visual%20Studio-5C2D91?logo=visualstudio&logoColor=white)
![Platform](https://img.shields.io/badge/Platform-Windows-0078D4?logo=windows&logoColor=white)

**C언어로 개발한 콘솔 기반 암호·추리 어드벤처 게임**

사라진 연구노트를 찾기 위해 연구실의 단서를 조사하고, 암호를 해독하며, 마지막 선택을 통해 사건의 결말을 결정하는 게임입니다.

---

## 01. About the Game

연구실에서 중요한 연구노트가 사라졌습니다.

플레이어는 잠긴 서랍과 암호문에 남겨진 단서를 분석해 연구노트를 되찾아야 합니다.

모든 퍼즐을 해결하면 연구 결과를 공개할지, 비밀로 보관할지 결정할 수 있습니다.

## 02. Key Features

- **Console Interface** — 메뉴 선택 및 화면 전환
- **Puzzle System** — 문자열 암호와 시저 암호 해독
- **Clue Collection** — 발견한 단서 저장 및 확인
- **Hint System** — 막혔을 때 힌트 제공
- **Limited Attempts** — 퍼즐마다 오답 3회 제한
- **Multiple Endings** — 선택과 실패 여부에 따른 3가지 엔딩

## 03. How to Play

| 입력 | 기능 |
|---|---|
| `1` | 게임 시작 |
| `2` | 수집한 단서 확인 |
| `3` | 게임 설명 |
| `0` | 게임 종료 |
| `H` | 퍼즐 힌트 확인 |
| `C` | 퍼즐 진행 중 단서 확인 |

게임은 총 2개의 퍼즐로 구성되어 있으며, 각 퍼즐에서 오답이 3회 발생하면 미완성 엔딩으로 종료됩니다.

## 04. Development Environment

| 항목 | 내용 |
|---|---|
| Language | C |
| IDE | Microsoft Visual Studio |
| Platform | Windows Console |
| Version Control | Git / GitHub |
| Team | 2 Developers |

외부 게임 엔진이나 GUI 라이브러리를 사용하지 않고 C언어 기본 문법과 표준 라이브러리를 중심으로 구현했습니다.

## 05. Project Structure

| 파일 | 역할 |
|---|---|
| `Game/main.c` | 메인 메뉴 및 프로그램 흐름 |
| `Game/game.c` | 퍼즐, 단서, 힌트, 엔딩 |
| `Game/game.h` | 구조체와 함수 선언 |
| `PROJECT-404.slnx` | Visual Studio 솔루션 |
| `.gitignore` | 빌드 및 임시 파일 제외 |

## 06. Getting Started

1. GitHub 저장소를 Clone하거나 ZIP으로 다운로드합니다.
2. Visual Studio에서 `PROJECT-404.slnx`를 엽니다.
3. `Game` 프로젝트를 시작 프로젝트로 설정합니다.
4. `Ctrl + F5`를 눌러 프로그램을 실행합니다.

**Requirements:** Visual Studio 및 C++ 데스크톱 개발 도구

## 07. Development Progress

- [x] 프로젝트 기획 및 저장소 생성
- [x] 메인 메뉴 및 화면 전환
- [x] 문자열 정답 판정
- [x] 단서·힌트 시스템
- [x] 시저 암호 해독
- [x] 다중 엔딩 구현
- [x] 게임 기능 통합
- [ ] 최종 테스트 및 오류 검토
- [ ] 최종 발표 및 보고서 정리

## 08. Team & Collaboration

2인 팀으로 개발하며 GitHub를 통해 코드 변경 사항과 개발 과정을 관리합니다.

각 기능을 구현하고 테스트한 뒤 Commit 및 Push하여 공동 저장소에 반영합니다.
---

**PROJECT-404 — Find the clues. Decode the truth.**
