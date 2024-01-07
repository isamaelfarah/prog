#include <stdio.h>

// لوحة اللعب
char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

// دالة لطباعة لوحة اللعب
void printBoard() {
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

// دالة للتحقق من الفائز
int checkWin() {
    // التحقق من الصفوف والأعمدة والقطرين
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1; // فوز في الصف
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return 1; // فوز في العمود
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1; // فوز في القطر
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1; // فوز في القطر

    return 0; // لا يوجد فائز بعد
}

// دالة للتحقق من امتلاء اللوحة
int isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return 0; // اللوحة ليست ممتلئة
        }
    }
    return 1; // اللوحة ممتلئة
}

// دالة لعرض رسالة ترحيبية
void printWelcomeMessage() {
    printf("مرحبًا بك في لعبة X/O (Tic-Tac-Toe)!\n");
    printf("اللاعب 1 يستخدم X واللاعب 2 يستخدم O.\n");
    printf("تمثل الخانات على اللوحة الأرقام من 1 إلى 9.\n");
    printf("لتحديد موقع الخانة، ادخل رقم الخانة المرغوبة.\n\n");
}

int main() {
    printWelcomeMessage();

    int player = 1; // يبدأ اللاعب 1
    int choice;
    int row, col;

    do {
        printBoard();

        // الحصول على حركة اللاعب
        printf("لاعب %d، أدخل رقمًا (1-9) لوضع رمزك: ", player);
        scanf("%d", &choice);

        // تحويل الرقم إلى صف وعمود
        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        // التحقق مما إذا كانت الخلية المختارة فارغة
        if (board[row][col] == ' ') {
            if (player == 1)
                board[row][col] = 'X';
            else
                board[row][col] = 'O';

            // التحقق من وجود فائز
            if (checkWin()) {
                printBoard();
                printf("لاعب %d يفوز!\n", player);
                break;
            }

            // التحقق من التعادل
            if (isBoardFull()) {
                printBoard();
                printf("تعادل!\n");
                break;
            }

            // التبديل إلى اللاعب الآخر
            player = 3 - player;
        } else {
            printf("الخلية محجوزة بالفعل. اختر خلية أخرى.\n");
        }

    } while (1);

    return 0;
}
