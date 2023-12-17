#include "monty.h"

/**
 * push - Pushes an element on to stack
 * @stack: double Pointer to beginning of stack structure
 *
 * @line_number: Line number in file
 */

void push(stack_t **stack, unsigned int line_number)
{
	int value;
	char *token;

	token = strtok(NULL, " \t\n");

	if (!token || !is_numeric(token))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(token);
	add_node(stack, value);
}

/**
 * add_node - Adds new node with given value to stack.
 * @stack: Double pointer to the beginning of the stack.
 * @value: Value to be stored in new node.
 */
void add_node(stack_t **stack, int value)
{
	if (*stack == NULL)
	{
		*stack = create_node(value);
	}
	else
	{
		stack_t *new_node = create_node(value);

		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}

/**
 * create_node - Creates a new stack node with the given value.
 * @value: Value to be stored in the new node.
 * Return: Pointer to the newly created node.
 */
stack_t *create_node(int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = NULL;

	return (new_node);
}

/**
 * is_numeric - Checks if a string consists of numeric characters.
 * @str: The string to check.
 * Return: 1 if numeric, 0 otherwise.
 */
int is_numeric(char *str)
{
	if (!str)
		return (0);
	if (*str == '-')
		str++;

	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}

	return (1);
}
