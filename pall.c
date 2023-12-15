#include "monty.h"

/**
 * pall - prints all values on stack
 * @stack : pointer to the stack structure
 */

void pall(struct Stack *stack)
{
	int i;

	for (i = stack->top; i >= 0; i--)
		printf("%d\n", stack->data[i]);
}
