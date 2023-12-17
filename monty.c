#include "monty.h"

/**
 * main - main function
 * @argc: number of command line arguments
 * @argv: array of command line strings
 *
 * Return: EXIT_SUCCESS if successful, EXIT_FAILURE if error
 */
stack_t* stack;

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	process_file(argv[1]);
	
	free_stack();
	return (EXIT_SUCCESS);
}

/**
 * process_file - Process the Monty bytecode file.
 * @file_path: Path to the Monty bytecode file.
 */
void process_file(const char *file_path)
{
	char line[MAX_LINE_LENGTH], opcode[MAX_LINE_LENGTH];
	int line_number;
	FILE *file;

	file = fopen(file_path, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_path);
		exit(EXIT_FAILURE);
	}

	line_number = 0;

	while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
	{
		line_number++;

		if (sscanf(line, "%s", opcode) == 1)
		{
			execute_instruction(opcode, line_number);
		}
		else
		{
			fprintf(stderr, "L%d: invalid instruction format\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	fclose(file);
}

/**
 * free_stack - Frees the memory allocated for the stack.
 */
void free_stack(void)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
