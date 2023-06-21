#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * push - adds a new element to the stack.
 * @stack: pointer to the stack
 * @line_number: current line in node
 *
 * Return: nothing.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = line_number;

	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pall - prints all elements in a stack.
 * @stack: pointer to the stack
 * @line_number: current line in node
 *
 * Return: nothing.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void) line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
