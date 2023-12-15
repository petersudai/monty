#include "monty.h"

/**
 * push - Pushes an element on to stack
 * @stack: Pointer to stack structure
 * @value: value to be pushed onto stack
 * @line_number: Line number in file
 */
void push(struct Stack *stack, int value, int line_number)
{
	if (stack->top == STACK_SIZE - 1)
	{
		fprintf(stderr, "L%d: Stack overflow\n", line_number);
		exit(EXIT_FAILURE);
	}
	stack->top++;
	stack->data[stack->top] = value;
}
