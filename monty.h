#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100

/**
 * struct Stack - stack data structure
 * @data: array to store stack elements
 * @top: index of top element in stack
 */

struct Stack
{
	int data[STACK_SIZE];
	int top;
};

/* Function declarations */
void push(struct Stack *stack, int value, int line_number);
void pint(struct Stack *stack, int line_number);
void pall(struct Stack *stack);
void proc_inst(struct Stack *stack, const char *inst, int value, int line_num);
void read_and_process_file(const char *filename);

#endif /* MONTY_H */

