#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <termios.h>

#define IMG_HEIGHT 7
#define IMG_WIDTH 17
#define MAX_IMAGES 16 // 총 이미지 수

#define BOARD_SIZE 4
#define BOARD_AREA (BOARD_SIZE * BOARD_SIZE)

// 이미지 배열 대신 간단한 숫자를 사용하여 구현합니다.
int board[BOARD_AREA] = {0};
int revealedCards[BOARD_AREA] = {0}; // 카드가 뒤집혀 있는지 여부를 저장
int score = 0; // 현재 점수
struct termios orig_termios; // 원래 터미널 설정을 저장

char images[MAX_IMAGES][IMG_HEIGHT][IMG_WIDTH + 1] = {
        {
        	"|---------------|",
			"|               |",
			"|     (\\_/)     |",
			"|    (>'.'<)    |",
			"|    (\")_(\")    |",
			"|               |",
			"|---------------|"
        },
        {   
            "|---------------|",
            "|^__^           |",
            "|(oo)\\_______   |",
            "|(__)\\       )\\ |",
            "|    ||----w |  |",
            "|    ||     ||  |",
            "|---------------|"
        },
        {        
            "|---------------|",
            "|               |",
            "|     /\\_/\\     |",
            "|    ( o.o )    |",
            "|     > ^ <     |",
            "|               |",
            "|---------------|"
        },
        {
            "|---------------|",
            "|    / \\___     |",
            "|   (     @\\___ |",
            "|   /         O |",
            "|  /    (_____/ |",
            "|  /_____/   U  |",
            "|---------------|"
        },
        {     
            "|---------------|",
            "|    ,--./,-.   |",
            "|   / #      \\  |",
            "|   |        |  |",
            "|   \\        /  |",
            "|    `._,._,'   |",
            "|---------------|"
        },
        {
            "|---------------|",
            "|     \\~~~/     |",
            "|      \\ /      |",
            "|       V       |",
            "|       |       |",
            "|      ---      |",
            "|---------------|"
        },
        {
            "|---------------|",
            "|      ,-.      |",
            "|    _(*_*)_    |",
            "|   (_  o  _)   |",
            "|     / o \\     |",
            "|    (_/ \\_)    |",
            "|---------------|"
        },
		{
            "|---------------|",
			"|    .'o O'-.   |",
			"|   / O o_.-`|  |",
			"|  /O_.-'  O |  |",  
			"|  | o  o_.-`   |",
			"|  '---`        |",
			"|---------------|"
        }
};

void disableRawMode() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enableRawMode() {
    tcgetattr(STDIN_FILENO, &orig_termios);
    atexit(disableRawMode);

    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void shuffleCards(int *array, int size) {
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void initializeBoard() {
    int placements[BOARD_AREA] = {0};

    // 카드를 쌍으로 배치하기 위한 초기화
    for (int i = 0; i < BOARD_AREA / 2; i++) {
        placements[i] = i % (MAX_IMAGES / 2);
        placements[i + BOARD_AREA / 2] = i % (MAX_IMAGES / 2);
    }

    shuffleCards(placements, BOARD_AREA);

    for (int i = 0; i < BOARD_AREA; i++) {
        board[i] = placements[i];
    }
}

void printBoard(int cursorPosition) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            int cardIndex = i * BOARD_SIZE + j;
            // 카드 상단 경계 출력
            printf("------------------");
        }
        printf("+\n"); // 줄의 끝에서만 경계 닫기

        for (int k = 0; k < IMG_HEIGHT; ++k) { // 이미지 높이(7)만큼 반복
            for (int j = 0; j < BOARD_SIZE; ++j) {
                int cardIndex = i * BOARD_SIZE + j;
                if (revealedCards[cardIndex]) { // 카드가 공개된 경우
                    // 실제 이미지 데이터가 있다면 여기서 이미지 라인을 출력합니다.
                    // 예제에서는 간단한 텍스트로 대체합니다.
                        for (int m = 0; m < IMG_WIDTH+1; m++){
                            printf("%c", images[board[cardIndex]][k][m]);

                        }
                 } else if (cardIndex == cursorPosition && k == 0) { // 커서 위치의 첫 번째 라인에만 선택 표시
                     printf("     선택됨      ");
                // } else {
                //     printf("|                 "); // 공개되지 않은 카드
                // }
                } else{
                        for (int m = 0; m < IMG_WIDTH+1; m++){
                            printf("%c", images[board[cardIndex]][k][m]);

                        }
                }
            }
            printf("|\n");
        }

        for (int j = 0; j < BOARD_SIZE; ++j) {
            // 카드 하단 경계 출력
            printf("------------------");
        }
        printf("+\n");
    }
}

void processInput(int* cursorPosition, int* selectedCards, int* selectedCount) {
    char c = getchar();
    switch (c) {
        case 'w':
            if (*cursorPosition >= BOARD_SIZE) *cursorPosition -= BOARD_SIZE;
            break;
        case 's':
            if (*cursorPosition < BOARD_AREA - BOARD_SIZE) *cursorPosition += BOARD_SIZE;
            break;
        case 'a':
            if (*cursorPosition % BOARD_SIZE != 0) (*cursorPosition)--;
            break;
        case 'd':
            if (*cursorPosition % BOARD_SIZE != BOARD_SIZE - 1) (*cursorPosition)++;
            break;
        case ' ':
            if (*selectedCount < 2 && !revealedCards[*cursorPosition]) {
                selectedCards[(*selectedCount)++] = *cursorPosition;
                revealedCards[*cursorPosition] = 1;
            }
            break;
    }
}

void checkMatch(int* selectedCards, int* selectedCount) {
    if (*selectedCount == 2) {
        if (board[selectedCards[0]] == board[selectedCards[1]]) {
            score++;
            printf("Match found! Score: %d\n", score);
        } else {
            revealedCards[selectedCards[0]] = 0;
            revealedCards[selectedCards[1]] = 0;
            printf("No match. Try again.\n");
        }
        *selectedCount = 0;
        sleep(1);
        // 사용자가 결과를 볼 수 있도록 잠시 대기
    }
}

int display_menu() {
    int menu;

    system("clear");
    
    printf("같은 그림 찾기 게임\n");
    printf("===================\n");
    printf("     게임 메뉴\n");
    printf("===================\n");
    printf("1. 게임 시작\n");
    printf("2. 사진 체크\n");
    printf("3. 크레딧\n");
    printf("4. 게임 종료\n");

    scanf("%d", &menu);
    return menu;
}

void display_credits() {
    printf("\033[2J\033[H"); // 화면 지우기

    printf("==\t윤현중\t\t==\n\n");
    sleep(1);

    printf("==\t홍솔아\t\t==\n\n");
    sleep(1);

    printf("==\t이진우\t\t==\n\n");
    sleep(1);

    printf("==\t송해든\t\t==\n\n");
    sleep(3);
}

void display_images() {
    printf("\033[2J\033[H"); // 화면 지우기 클리어 함수와 같음

    for (int img = 0; img < MAX_IMAGES / 2; ++img) { // 각 이미지에 대해 반복
        for (int row = 0; row < IMG_HEIGHT; ++row) { // 각 이미지의 모든 행에 대해 반복
            // 이미지의 현재 행을 출력
            printf("%s\n", images[img][row]);
        }
        printf("\n"); // 이미지 간 구분을 위해 빈 줄 추가
    }
    sleep(10); // 이미지를 잠시 표시한 후 메인 메뉴로 복귀
}


void play_game() {
    int cursorPosition = 0; // 현재 커서 위치
    int selectedCards[2]; // 선택된 카드의 인덱스
    int selectedCount = 0; // 현재 선택된 카드의 수

    enableRawMode();

    initializeBoard(); // 게임 보드 초기화
    while (score < (BOARD_AREA / 2)) { // 모든 쌍을 찾을 때까지 반복
        system("clear");
        printBoard(cursorPosition); // 현재 게임 보드 출력, 커서 위치 인자 전달
        processInput(&cursorPosition, selectedCards, &selectedCount); // 사용자 입력 처리
        if (selectedCount == 2) { // 두 카드가 모두 선택되면
            checkMatch(selectedCards, &selectedCount); // 카드가 일치하는지 확인
        }
    }

    disableRawMode();
    printf("Congratulations! You've completed the game with a score of %d.\n", score);
}

int main() {
    int choice;
    srand(time(NULL)); // 랜덤 시드 초기화

    while (1) {
        choice = display_menu();

        switch(choice) {
            case 1:
                play_game();
                break;
            case 2:
                display_images();
                break;
            case 3:
                display_credits();
                // 크레딧 보여주고 메뉴로 돌아가야 하므로, 여기에 display_menu()를 호출하지 않음
                break;
            case 4:
                printf("\033[2J\033[H");
                printf("게임을 종료합니다.\n");
                exit(0); // 프로그램 종료
            default:
                printf("잘못된 선택입니다.\n");
                sleep(1); // 잠시 대기 후 다시 메뉴를 보여줌
        }
    }

    return 0; // 실제로는 여기에 도달하지 않음
}
