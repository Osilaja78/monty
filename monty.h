#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct inst_s - variables -args, file, line content
 * @op_code: opcode
 * @arg: value
 * @file: monty filename
 * @line: line to free
 *
 * Descrption: stores instructions.
 */
typedef struct inst_s
{
	char *op_code;
	char *arg;
	FILE *file;
	char *line;
}  inst_t;

extern inst_t inst;

/* ***** OPCODE FUNCTION PROTOTYPES ***** */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

/* ***** UTILITY FUNCTIONS ***** */
void execute_instructions(char *filename);
void (*find_instruction(char *opcode))(stack_t **, unsigned int);
void free_s(stack_t *head);

#endif
