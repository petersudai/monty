#include "monty.h"

/**
 * read_and_process_file - reads files and process each line as an instruction
 * @filename: name of file to read
 */
void read_and_process_file(const char *filename)
{
	struct Stack myStack;
	char line[100], opcode[10];
	FILE *file = fopen(filename, "r");
	int line_number, value;

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	myStack.top = -1;

	line_number = 1;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		if (sscanf(line, "%s %d", opcode, &value) == 2)
			proc_inst(&myStack, opcode, value, line_number);
		else
		{
			fprintf(stderr, "L%d: Invalid instruction: %s", line_number, line);
			exit(EXIT_FAILURE);
		}
		line_number++;
	}
	fclose(file);
}
