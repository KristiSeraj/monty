#include "monty.h"
/**
 * _add - function that adds top two elements of stack
 * @top: pointer
 * @line: line
 */
void _add(stack_t **top, unsigned int line)
{
	stack_t *tmp;

	if (*top == NULL || (*top)->next == NULL)
	{
		printf("L<line_number>: can't add, stack too short\n");
		exit(EXIT_FAILURE);
	}
	tmp = (*top)->next;
	tmp->n += (*top)->n;
	_pop(top, line);
}
/**
 * _sub - function that subtract the value of top two elements of stack
 * @top: pointer
 * @line: line
 */
/* void _sub(stack_t **top, unsigned int line); */
/**
 * _div - function that divides the second top element by top element
 * @top: pointer
 * @line: line
 */
/* void _div(stack_t **top, unsigned int line); */
/**
 * _mul - function that multiplies top two elements of stack
 * @top: pointer
 * @line: line
 */
/* void _mul(stack_t **top, unsigned int line); */
/* void _mod(stack_t **top, unsigned int line); */
