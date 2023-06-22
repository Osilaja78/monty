#define  _GNU_SOURCE
#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

inst_t inst = {NULL, NULL, NULL, NULL};

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
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	void (*opcode_function)(stack_t **, unsigned int);

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	inst.file = file;
	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		inst.line = line;
		opcode = strtok(line, " \t\n");
		if (strchr(opcode, '#') != NULL)
			continue;
		if (opcode != NULL)
		{
			inst.op_code = opcode;
			inst.arg = strtok(NULL, " \t\n");
			opcode_function = find_instruction(opcode);
			if (opcode_function != NULL)
				opcode_function(&stack, line_number);
			else
				unknown_inst_error(line_number, opcode, stack);
		}
	}
	free(line);
	free_s(stack);
	fclose(file);
}

/**
 * unknown_inst_error - orints error for unknown opcode.
 * @l: line number
 * @o: opcode
 * @s: stack
 *
 * Return: nothin.
 */
void unknown_inst_error(unsigned int l, char *o, stack_t *s)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", l, o);
	free(inst.line);
	free_s(s);
	fclose(inst.file);
	exit(EXIT_FAILURE);
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
		{"push", push}, {"pall", pall},
		{"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add},
		{"nop", nop}, {"sub", sub},
		{"div", f_div}, {"mul", mul},
		{"mod", mod}, {"pchar", pchar},
		{NULL, NULL}
	};

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
			return (instructions[i].f);
	}

	return (NULL);
}

/**
 * free_s - frees a stack.
 * @head: head of stack
 *
 * Return: nothing.
 */
void free_s(stack_t *head)
{
	stack_t *current = head;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
