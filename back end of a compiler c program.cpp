#include <stdio.h>
#include <string.h> // Include string.h for strcmp()

// Function prototypes
int generate_code(const char *operation, int operand1, int operand2);

int main() {
    // Example arithmetic expression: 2 + 3 * 4
    int result = generate_code("+", 2, generate_code("*", 3, 4));
    printf("Result: %d\n", result);
    return 0;
}

// Code generation function
int generate_code(const char *operation, int operand1, int operand2) {
    if (strcmp(operation, "+") == 0) {
        return operand1 + operand2;
    } else if (strcmp(operation, "*") == 0) {
        return operand1 * operand2;
    } else {
        printf("Unsupported operation: %s\n", operation);
        return 0;
    }
}


OUTPUT:
Result: 14

--------------------------------
Process exited after 0.0442 seconds with return value 0
Press any key to continue . . .
