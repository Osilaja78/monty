#include "monty.h"
#include <stdio.h>

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

/**
 * nop - does nothing.
 * @stack: head of stack
 * @line_number: current line in monty file
 *
 * Return: nothing.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * sub - subtracts the top elem from the 2nd top elem in stack.
 * @stack: pointer to the stack
 * @line_number: current line in monty file
 *
 * Return: nothing.
 */
void sub(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free(inst.line);
		free_s(*stack);
		fclose(inst.file);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	result = current->next->n - current->n;
	current->next->n = result;
	*stack = current->next;
	free(current);
}

/**
 * div - dividess the 2nd top elem by the top elem in stack.
 * @stack: pointer to the stack
 * @line_number: current line in monty file
 *
 * Return: nothing.
 */
void f_div(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
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
	result = current->next->n / current->n;
	current->next->n = result;
	*stack = current->next;
	free(current);
}

/**
 * mul - multiplies the top elem and the 2nd top elem in stack.
 * @stack: pointer to the stack
 * @line_number: current line in monty file
 *
 * Return: nothing.
 */
void mul(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free(inst.line);
		free_s(*stack);
		fclose(inst.file);
		exit(EXIT_FAILURE);
	}

	current = *stack;
	result = current->next->n * current->n;
	current->next->n = result;
	*stack = current->next;
	free(current);
}
