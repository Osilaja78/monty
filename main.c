#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point.
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: exit status.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		return (EXIT_FAILURE);
	}

	execute_instructions(argv[1]);

	return (EXIT_SUCCESS);
}
