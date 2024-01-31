#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 1001

int main() {
    char input[MAX_INPUT_SIZE];
    char searchWord[50];  // Assuming maximum size for the search word
    int length, wordCount, spaceCount, lineCount, numberCount;

    // Get the text from the user
    printf("Enter the text (up to 1000 characters):\n");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Calculate statistics
    length = strlen(input);
    wordCount = spaceCount = lineCount = numberCount = 0;

    for (int i = 0; i < length; i++) {
        if (input[i] == ' ') {
            spaceCount++;
        } else if (input[i] == '\n') {
            lineCount++;
        } else if (isdigit(input[i])) {
            numberCount++;
        }
    }

    // Display statistics
    printf("\nNumber of characters: %d\n", length - 1);  // Subtract 1 to exclude the newline character
    printf("Number of words: %d\n", spaceCount + 1);
    printf("Number of spaces: %d\n", spaceCount);
    printf("Number of lines: %d\n", lineCount);
    printf("Number of numbers: %d\n", numberCount);

    // Search for a specific word
    printf("\nEnter a word to search for:\n");
    scanf("%s", searchWord);

    char *found = strstr(input, searchWord);

    if (found) {
        printf("The word \"%s\" was found at position: %ld\n", searchWord, found - input + 1);
    } else {
        printf("The word \"%s\" was not found.\n", searchWord);
    }

    // Delete a specific word
    printf("\nEnter a word to delete:\n");
    scanf("%s", searchWord);

    found = strstr(input, searchWord);

    while (found) {
        // Delete the word from the text
        memmove(found, found + strlen(searchWord), strlen(found + strlen(searchWord)) + 1);
        found = strstr(input, searchWord);
    }

    // Display the text after deletion
    printf("\nThe text after deletion:\n%s", input);

    // Edit a specific word
    printf("\nEnter a word to edit:\n");
    scanf("%s", searchWord);

    found = strstr(input, searchWord);

    if (found) {
        // Prompt for and edit the word
        printf("Enter the new word:\n");
        scanf("%s", found);
    } else {
        printf("The word \"%s\" was not found for editing.\n", searchWord);
    }

    // Display the text after editing
    printf("\nThe text after editing:\n%s", input);

    return 0;
}
