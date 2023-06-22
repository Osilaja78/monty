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
	stack_t *new_node;
	int num;

	if (inst.arg == NULL || atoi(inst.arg) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_s(*stack);
		free(inst.line);
		fclose(inst.file);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_s(*stack);
		free(inst.line);
		fclose(inst.file);
		exit(EXIT_FAILURE);
	}

	num = atoi(inst.arg);
	new_node->n = num;

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

/**
 * pint - prints the value at the top of the stack.
 * @stack: pointer to the stack
 * @line_number: current_line in stack
 *
 * Return: nothing.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(inst.file);
		free(inst.line);
		free_s(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack.
 * @stack: pointer to the stack
 * @line_number: current_line in stack
 *
 * Return: nothing.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		fclose(inst.file);
		free(inst.line);
		free_s(*stack);
		exit(EXIT_FAILURE);
	}

	*stack = current->next;
	free(current);
}

/**
 * swap - swaps the top two elements of a stack.
 * @stack: pointer to the stack
 * @line_number: current line in monty file
 *
 * Return: nothing.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *temp = *stack;
	int len, i;

	while (temp != NULL)
	{
		len++;
		temp = temp->next;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free(inst.line);
		free_s(*stack);
		fclose(inst.file);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	i = current->n;
	current->n = current->next->n;
	current->next->n = i;
}
