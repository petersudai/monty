#include "monty.h"

/**
 * execute_instruction - Execute corresponding function for given opcode
 * @opcode: The opcode to be executed.
 * @line_number: The line number in the Monty bytecode file.
 */
void execute_instruction(char *opcode, int line_number)
{
	int i;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"nop", nop},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{NULL, NULL}};

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(&stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
