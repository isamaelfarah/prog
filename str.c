#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

void displayStats(const char *text) {
    int words = 0, characters = 0, digits = 0, spaces = 0;

    for (int i = 0; i < strlen(text); i++) {
        if (isalnum(text[i])) {
            characters++;
            if (isspace(text[i + 1]) || text[i + 1] == '\0') {
                words++;
            }
        } else if (isdigit(text[i])) {
            digits++;
        } else if (isspace(text[i])) {
            spaces++;
        }
    }

    printf("Number of words: %d\n", words);
    printf("Number of characters: %d\n", characters);
    printf("Number of digits: %d\n", digits);
    printf("Number of spaces: %d\n", spaces);
}

int main() {
    char text[MAX_LENGTH];
    printf("Enter text (up to 1000 characters):\n");
    fgets(text, sizeof(text), stdin);

    // Remove trailing newline character
    size_t length = strlen(text);
    if (length > 0 && text[length - 1] == '\n') {
        text[length - 1] = '\0';
    }

    displayStats(text);

    char searchWord[50];
    printf("Enter a word to search for: ");
    scanf("%s", searchWord);

    char *foundWord = strstr(text, searchWord);

    if (foundWord != NULL) {
        printf("Word found at position: %ld\n", foundWord - text);
        printf("1. Edit the word\n");
        printf("2. Delete the word\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the new word: ");
                char newWord[50];
                scanf("%s", newWord);

            
                size_t position = foundWord - text;

                strcpy(foundWord, newWord);

            
                memmove(text + position + strlen(newWord), text + position + strlen(searchWord), strlen(foundWord + strlen(searchWord)) + 1);

                printf("Text after editing: %s\n", text);
                break;

            case 2:
       
                size_t deletePosition = foundWord - text;

           
                memmove(text + deletePosition, text + deletePosition + strlen(searchWord), strlen(foundWord + strlen(searchWord)) + 1);

                printf("Text after deleting: %s\n", text);
                break;

            default:
                printf("Invalid choice\n");
                break;
        }
    } else {
        printf("Word not found\n");
    }

    return 0;
}
