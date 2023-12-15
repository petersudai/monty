#include "monty.h"

/**
 * main - main function
 * @argc: number of command line arguments
 * @argv: array of command line strings
 *
 * Return: EXIT_SUCCESS if successful, EXIT_FAILURE if error
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	read_and_process_file(argv[1]);

	return (EXIT_SUCCESS);
}
