#define  _GNU_SOURCE
#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

inst_t inst = {NULL, NULL};

/**
 * execute_instructions - main function to execute instructions.
 * @filename: name of monty file to find instructions
 *
 * Return: nothing.
 */
void execute_instructions(char *filename)
{
	FILE *file = fopen(filename, "r");
	char *line = NULL, *opcode;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number;
	stack_t *stack;
	void (*opcode_function)(stack_t **, unsigned int);

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	line_number = 0;
	stack = NULL;

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		opcode = strtok(line, " \t\n");
		if (opcode != NULL)
		{
			inst.op_code = opcode;
			inst.arg = strtok(NULL, " \t\n");
			opcode_function = find_instruction(opcode);
			if (opcode_function != NULL)
				opcode_function(&stack, line_number);
			else
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
				free(line);
				fclose(file);
				exit(EXIT_FAILURE);
			}
		}
	}
	free(line);
	fclose(file);
}

/**
 * find_instruction - finds the corresponding opcode and its funct.
 * @opcode: opcode to search for
 *
 * Return: function corresponding to the opcode, NULL if not
 * found.
 */
void (*find_instruction(char *opcode))(stack_t **, unsigned int)
{
	int i;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		/* Add more opcodes and functions here */
		{NULL, NULL}
	};

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
			return (instructions[i].f);
	}

	return (NULL);
}
