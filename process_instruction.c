#include "monty.h"

/**
 * proc_inst - processes an individual instruction
 * @stack: pointer to the stack structure
 * @inst: opcode of instruction
 * @value: value associated with the instruction
 * @line_num: line number in file
 */

void proc_inst(struct Stack *stack, const char *inst, int value, int line_num)
{
	if (strcmp(inst, "push") == 0)
		push(stack, value, line_num);
	else if (strcmp(inst, "pint") == 0)
		pint(stack, line_num);
	else if (strcmp(inst, "pall") == 0)
		pall(stack);
	else
	{
		fprintf(stderr, "L%d: Unknown opcode: %s\n", line_num, inst);
		exit(EXIT_FAILURE);
	}
}
