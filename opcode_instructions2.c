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

/**
 * pchar - prints the char at the top of the stack.
 * @stack: pointer to the stack
 * @line_number: current line in monty file
 *
 * Return: nothing.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (!current)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free(inst.line);
		free_s(*stack);
		fclose(inst.file);
		exit(EXIT_FAILURE);
	}

	if (current->n > 127 || current->n < 0)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free(inst.line);
		free_s(*stack);
		fclose(inst.file);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", current->n);
}

/**
 * pstr - prints the char at the top of the stack.
 * @stack: pointer to the stack
 * @line_number: current line in monty file
 *
 * Return: nothing.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void) line_number;

	while (current != NULL)
	{
		if (current->n > 127 || current->n <= 0)
			break;

		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}

/**
 * rotl - rotates the stack to the top.
 * @stack: pointer to the stack
 * @line_number: current line in monty file
 *
 * Return: nothing.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack, *last;
	(void) line_number;
    
	if (head == NULL || head->next == NULL)
		return;
    
	last = head;
	while (last->next != NULL)
		last = last->next;
    
	last->next = head;
	head->prev = last;
	head->next->prev = NULL;
	*stack = head->next;
	head->next = NULL;
}
