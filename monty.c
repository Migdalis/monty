#include "monty.h"

/**
 * main - Runs the program monty
 * @argc: Size of argv
 * @argv: Argument vector
 * Return: A exit with status or 0
 */

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (read_file(argv[1]) == 0)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
