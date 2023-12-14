#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = -1;  // Initialize the top of the stack

// Function to push an element onto the stack
void push(int value, int line_number) {
    if (top == STACK_SIZE - 1) {
        fprintf(stderr, "L%d: Stack overflow\n", line_number);
        exit(EXIT_FAILURE);
    } else {
        stack[++top] = value;
    }
}

// Function to print the value at the top of the stack
void pint(int line_number) {
    if (top == -1) {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    } else {
        printf("%d\n", stack[top]);
    }
}

// Function to print all values on the stack
void pall() {
    int i;
    for (i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main(int argc, char *argv[]) {
    // Read your bytecode file or commands from some source
    // For simplicity, I'm hardcoding the example bytecode
    char *bytecode[] = {
        "push 1",
        "pint",
        "push 2",
        "pint",
        "push 3",
        "pint",
        "pall"
    };

    int line_number = 1;

    // Iterate over each line in the bytecode
    for (int i = 0; i < sizeof(bytecode) / sizeof(bytecode[0]); i++) {
        char opcode[10];
        int value;

        // Parse the line (you may need a more robust parser)
        if (sscanf(bytecode[i], "%s %d", opcode, &value) == 2) {
            if (strcmp(opcode, "push") == 0) {
                push(value, line_number);
            } else if (strcmp(opcode, "pint") == 0) {
                pint(line_number);
            } else {
                fprintf(stderr, "L%d: Unknown opcode: %s\n", line_number, opcode);
                exit(EXIT_FAILURE);
            }
        } else if (strcmp(opcode, "pall") == 0) {
            pall();
        } else {
            fprintf(stderr, "L%d: Invalid instruction: %s\n", line_number, bytecode[i]);
            exit(EXIT_FAILURE);
        }

        line_number++;
    }

    return 0;
}
