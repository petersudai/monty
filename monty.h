#ifndef MONTY_H
#define MONTY_H

#define STACK_SIZE 100

/* Structure to hold stack information */
struct Stack {
    int data[STACK_SIZE];
    int top;
};

/* Function declarations */
void push(struct Stack *stack, int value, int line_number);
void pint(struct Stack *stack, int line_number);
void pall(struct Stack *stack);

#endif /* MONTY_H */

