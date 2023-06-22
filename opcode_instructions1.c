#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * add - adds the top two elements of a stack.
 * @stack: pointer to the stack
 * @line_number: current line in monty file
 *
 * Return: nothing.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *temp = *stack;
	int len, sum;

	while (temp != NULL)
	{
		len++;
		temp = temp->next;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free(inst.line);
		free_s(*stack);
		fclose(inst.file);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	sum = current->n + current->next->n;
	current->next->n = sum;
	*stack = current->next;
	free(current);
}
