#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h> // Include the stdlib.h header for exit()

// Function prototypes
int expression(const char **input);
int term(const char **input);
int factor(const char **input);
bool is_valid_input(const char *input);

// Global variables
const char *current_position;

// Main entry point
int main() {
    char input[100];

    printf("Enter an arithmetic expression: ");
    fgets(input, sizeof(input), stdin);

    // Check if input is valid (contains only allowed characters)
    if (!is_valid_input(input)) {
        printf("Invalid input.\n");
        return 1;
    }

    // Start parsing
    current_position = input;
    int result = expression(&current_position);
    
    // Check if the entire input has been parsed
    if (*current_position != '\0' && *current_position != '\n') {
        printf("Parsing error: Unexpected token '%c'\n", *current_position);
        return 1;
    }

    printf("Result: %d\n", result);

    return 0;
}

// Function to check if input contains only allowed characters
bool is_valid_input(const char *input) {
    while (*input != '\0' && *input != '\n') {
        if (!isdigit(*input) && *input != '+' && *input != '*' && *input != ' ') {
            return false;
        }
        input++;
    }
    return true;
}

// Recursive descent parsing functions

int expression(const char **input) {
    int result = term(input);
    while (**input == '+') {
        (*input)++;
        result += term(input);
    }
    return result;
}

int term(const char **input) {
    int result = factor(input);
    while (**input == '*') {
        (*input)++;
        result *= factor(input);
    }
    return result;
}

int factor(const char **input) {
    int result = 0;
    if (isdigit(**input)) {
        result = **input - '0';
        (*input)++;
    } else if (**input == '(') {
        (*input)++; // Move past '('
        result = expression(input);
        if (**input != ')') {
            printf("Parsing error: ')' expected.\n");
            exit(1); // Include the exit() call
        }
        (*input)++; // Move past ')'
    } else {
        printf("Parsing error: Unexpected token '%c'\n", **input);
        exit(1); // Include the exit() call
    }
    return result;
}
