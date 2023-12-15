#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * push - push an element on to stack
 * @stack: pointer  to the stack structure
 * @value: value to be oushed on to stack
 * @line_number: the line number in the bytecode
 */

void push(struct Stack *stack, int value, int line_number)
{
	if (stack->top == STACK_SIZE - 1)
	{
		fprintf(stderr, "L%d: Stack overflow\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		stack->data[++stack->top] = value;
	}
}

/**
 * pint - function to print value at top of stack
 * @stack: pointer to the stack structure
 * @line_number: line number in bytecode
 */

void pint(struct Stack *stack, int line_number)
{
	if (stack->top == -1)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", stack->data[stack->top]);
	}
}

/**
 * pall - prints all values on stack
 * @stack : pointer to the stack structure
 */

void pall(struct Stack *stack)
{
	int i;

	for (i = stack->top; i >= 0; i--)
	{
		printf("%d\n", stack->data[i]);
	}
}

/**
 * main - main function
 *
 * Return: void
 */

int main(void)
{
	struct Stack myStack;
	size_t i;
	int line_number;

	char *bytecode[] = { "push 1", "push 2", "pint"
		, "push 3", "pint", "pall" };

	line_number = 1;
	myStack.top = -1;
	for (i = 0; i < sizeof(bytecode) / sizeof(bytecode[0]); i++)
	{
		char opcode[10];
		int value;

		if (sscanf(bytecode[i], "%s %d", opcode, &value) == 2)
		{
			if (strcmp(opcode, "push") == 0)
				push(&myStack, value, line_number);
			else if (strcmp(opcode, "pint") == 0)
				pint(&myStack, line_number);
			else
			{
				fprintf(stderr, "L%d: Unknown opcode: %s\n", line_number, opcode);
				exit(EXIT_FAILURE);
			}
		}
		else if (strcmp(opcode, "pall") == 0)
			pall(&myStack);
		else
		{
			fprintf(stderr, "L%d: Invalid instruction: %s\n", line_number, bytecode[i]);
			exit(EXIT_FAILURE);
		}
		line_number++;
	}
	return (0);
}
