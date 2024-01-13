#include <stdio.h>

//نمایش پورد
void displayBoard(char board[3][3]);
//برنده شدن را شك کنید
int checkWin(char board[3][3], char player);
// برابری را بررسی کنید
int checkTie(char board[3][3]);
// پخش کننده را در کادر انتخاب شده علامت گذاری کنید
void markCell(char board[3][3], int choice, char player);
// نمایش پیام خوش آمد گویی
void printWelcomeMessage();

// کدهای رنگ ANSI
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m"

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int choice;
    char currentPlayer = 'X';
    char playAgain;

    // نمایش پیام خوش آمد گویی
    printWelcomeMessage();

    do {
        do {
           //نمایش پورد
            displayBoard(board);

             // از بازیکن بخواهید شماره اسلات را وارد کند
            printf("Player %c, enter a number from 1 to 9: ", currentPlayer);
            scanf("%d", &choice);

            // شماره وارد شده را شك کنید
            if (choice < 1 || choice > 9) {
                printf("Invalid move. Choose a number between 1 and 9. Try again.\n");
                continue;
            }

            // عدد را به سطر و ستون تبدیل کنید
            int row = (choice - 1) / 3;
            int col = (choice - 1) % 3;

            // بررسی کنید که آیا مکان خالی است
            if (board[row][col] != ' ') {
                printf("Invalid move. The cell is already occupied. Try again.\n");
                continue;
            }

            // پخش کننده را در کادر انتخاب شده علامت گذاری کنید
            markCell(board, choice, currentPlayer);

            //برنده شدن را شك کنید
            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                printf("Player %c wins!\n", currentPlayer);
                break;
            }

            // برابری را بررسی کنید
            if (checkTie(board)) {
                displayBoard(board);
                printf("It's a tie!\n");
                break;
            }

            //تبديل بازیکن
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

        } while (1);  

       // از بازیکن بپرسید که آیا می خواهد دوباره بازی کند
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);

        if (playAgain != 'y' && playAgain != 'Y') {
            break; 
        }

        // هیئت بورد و بازیکنان را برای شروع یک دور جدید مجدداً آماده می کند
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = ' ';
            }
        }
        currentPlayer = 'X';

    } while (1);  
    return 0;
}

 //نمایش پورد
void displayBoard(char board[3][3]) {
    printf("-------------\n");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == 'X') {
                printf("| " RED "X" RESET " ");
            } else if (board[i][j] == 'O') {
                printf("| " BLUE "O" RESET " ");
            } else {
                printf("| %c ", board[i][j]);
            }
        }
        printf("|\n-------------\n");
    }
}

//برنده شدن را شك کنید
int checkWin(char board[3][3], char player) {
   
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    
    for (int i = 0; i < 3; ++i) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    return 0;
}

 // برابری را بررسی کنید
int checkTie(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

 // پخش کننده را در کادر انتخاب شده علامت گذاری کنید
void markCell(char board[3][3], int choice, char player) {
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;
    board[row][col] = player;
}

 // نمایش پیام خوش آمد گویی
void printWelcomeMessage() {
    printf("Welcome to the Tic-Tac-Toe game!\n");
    printf("The game was programmed with love.\n");
    printf("thes game py:"RED "ismael farah\n");
    printf("       ***   ***  \n");
    printf("      ***** ***** \n");
    printf("       *********  \n");
    printf("        *******   \n");
    printf("         *****    \n");
    printf("          ***     \n");
    printf("           *      \n");
   printf(""RESET);
    printf("Player X, your symbol is " RED "X" RESET "\n");
    printf("Player O, your symbol is " BLUE "O" RESET "\n");
    printf("To make a move, enter a number from 1 to 9, as shown below:\n");
    printf("-------------\n");
    for (int i = 1; i <= 9; i += 3) {
        printf("| %d | %d | %d |\n", i, i + 1, i + 2);
        printf("-------------\n");
    }
    printf("Let the game begin!\n");
}
