#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 1000

int main() {
    char input[MAX_SIZE];
    int char_count = 0, word_count = 0, line_count = 0;
    int inside_word = 0; // Flag to track if currently inside a word

    printf("Enter text (Ctrl+D to end):\n");

    // Read input until EOF (Ctrl+D)
    while (fgets(input, MAX_SIZE, stdin) != NULL) {
        for (int i = 0; input[i] != '\0'; i++) {
            char_count++;

            // Increment word count when a space, tab, or newline is encountered
            if (isspace(input[i])) {
                if (inside_word) {
                    word_count++;
                    inside_word = 0;
                }
                // Increment line count when newline is encountered
                if (input[i] == '\n')
                    line_count++;
            } else {
                inside_word = 1;
            }
        }
    }

    // If the last word in the input is not followed by a space, tab, or newline
    if (inside_word)
        word_count++;

    // Increment line count to include the last line
    if (char_count > 0)
        line_count++;

    printf("Number of characters: %d\n", char_count);
    printf("Number of words: %d\n", word_count);
    printf("Number of lines: %d\n", line_count);

    return 0;
}
