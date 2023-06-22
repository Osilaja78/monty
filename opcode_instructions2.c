#include "monty.h"

/**
 * mod - gets remainder of division of 2nd top elem by top elem.
 * @stack: pointer to the stack
 * @line_number: current line in monty file
 *
 * Return: nothing.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *temp = *stack;
	int len, result;

	while (temp != NULL)
	{
		len++;
		temp = temp->next;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free(inst.line);
		free_s(*stack);
		fclose(inst.file);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	if (current->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free(inst.line);
		free_s(*stack);
		fclose(inst.file);
		exit(EXIT_FAILURE);
	}
	result = current->next->n % current->n;
	current->next->n = result;
	*stack = current->next;
	free(current);
}
