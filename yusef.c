#include <stdio.h>

// Game board
char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

// Function to print the game board
void printBoard() {
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

// Function to check for a winner
int checkWin() {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1; // Win in row
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return 1; // Win in column
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1; // Win in diagonal
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1; // Win in diagonal

    return 0; // No winner yet
}

// Function to check if the board is full
int isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return 0; // Board is not full
        }
    }
    return 1; // Board is full
}

// Function to display a welcome message
void printWelcomeMessage() {
    printf("Welcome to the X/O (Tic-Tac-Toe) game!\n");
    printf("Player 1 uses X and Player 2 uses O.\n");
    printf("The cells on the board are numbered from 1 to 9.\n");
    printf("To choose a cell, enter the number of the desired cell.\n\n");
}

int main() {
    printWelcomeMessage();

    int player = 1; // Player 1 starts
    int choice;
    int row, col;

    do {
        printBoard();

        // Get player move
        printf("Player %d, enter a number (1-9) to place your symbol: ", player);
        scanf("%d", &choice);

        // Convert choice to row and column
        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        // Check if the chosen cell is empty
        if (board[row][col] == ' ') {
            if (player == 1)
                board[row][col] = 'X';
            else
                board[row][col] = 'O';

            // Check for a winner
            if (checkWin()) {
                printBoard();
                printf("Player %d wins!\n", player);
                break;
            }

            // Check for a tie
            if (isBoardFull()) {
                printBoard();
                printf("It's a tie!\n");
                break;
            }

            // Switch to the other player
            player = 3 - player;
        } else {
            printf("Cell already taken. Choose another.\n");
        }

    } while (1);

    return 0;
}
