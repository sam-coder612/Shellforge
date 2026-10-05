#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *input = NULL;
    size_t size = 0;

    printf("Welcome to ShellForge!\n");

    while (1) {
        printf("ShellForge> ");
        fflush(stdout);

        ssize_t length = getline(&input, &size, stdin);

        // Ctrl+D
        if (length == -1) {
            printf("\nExiting ShellForge...\n");
            break;
        }

        // Remove newline
        if (length > 0 && input[length - 1] == '\n') {
            input[length - 1] = '\0';
        }

        // Exit command
        if (strcmp(input, "exit") == 0) {
            printf("Exiting ShellForge...\n");
            break;
        }

        printf("You entered: %s\n", input);
    }

    free(input);

    return 0;
}
