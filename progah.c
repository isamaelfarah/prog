#include <stdio.h>
#include <string.h>

int main() {
    char word[20];  // Store the user's word
    char guess[20]; // Store the guessed word
    int attempts = 0;
    int length;

    // Player one enters the word
    printf("Player 1, please enter a word: ");
    scanf("%s", word);
     printf("\033[H\033[J");
    // Calculate the length of the word
    length = strlen(word);

    // Convert the word to asterisks
    for (int i = 0; i < length; i++) {
        guess[i] = '*';
    }
    guess[length] = '\0'; // Add string terminator

    // The game loop
    while (strcmp(word, guess) != 0) {
        printf("Attempts remaining: %d\n", length - attempts);
        printf("============\n");
        printf("||%s||\n", guess);
        printf("============\n");

        char letter;
        printf("Player 2, guess a letter: ");
        scanf(" %c", &letter);

        // Check the validity of the guess
        int found = 0;
        for (int i = 0; i < length; i++) {
            if (word[i] == letter && guess[i] == '*') {
                guess[i] = letter;
                found = 1;
                break;  // Stop after finding the first occurrence
            }
        }

        // If the guess is incorrect, increase the attempts
        if (!found) {
            attempts++;
            printf("Incorrect guess. Remaining attempts: %d\n", length - attempts);
        } else {
            // Clear the terminal screen

        }

        // If attempts are exhausted
        if (attempts == length) {
            printf("Attempts exhausted. The correct word is: %s\n", word);
            break;
        }
    }

    printf("Congratulations! Player 2 guessed the word: %s\n", guess);

    return 0;
}
