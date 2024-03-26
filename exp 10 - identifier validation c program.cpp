#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isValidIdentifier(const char *identifier) {
    // Check if the identifier is not empty
    if (strlen(identifier) == 0) {
        return false;
    }

    // Check if the first character is a letter or underscore
    if (!isalpha(identifier[0]) && identifier[0] != '_') {
        return false;
    }

    // Check the rest of the characters
    for (int i = 1; i < strlen(identifier); i++) {
        // If the character is not alphanumeric or underscore, it's invalid
        if (!isalnum(identifier[i]) && identifier[i] != '_') {
            return false;
        }
    }

    // If all checks passed, the identifier is valid
    return true;
}

int main() {
    char identifier[100];
    printf("Enter an identifier: ");
    scanf("%s", identifier);

    if (isValidIdentifier(identifier)) {
        printf("Valid identifier\n");
    } else {
        printf("Invalid identifier\n");
    }

    return 0;
}


OUTPUT
Enter an identifier: devendra
Valid identifier

--------------------------------
Process exited after 6.343 seconds with return value 0
Press any key to continue . . .
