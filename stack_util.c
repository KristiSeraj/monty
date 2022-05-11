#include "monty.h"
/**
 * _swap - function that swaps top two elements of stack
 * @top: pointer
 * @line: line
 */
void _swap(stack_t **top, __attribute__((unused)) unsigned int line)
{
	int tmp_num;

	if (*top == NULL || (*top)->next == NULL)
	{
		printf("L<line_number>: can't swap, stack too short\n");
		exit(EXIT_FAILURE);
	}
	tmp_num = (*top)->n;
	(*top)->n = (*top)->next->n;	
	(*top)->next->n = tmp_num;
}
void _nop(stack_t **top, unsigned int line)
{
	(void) top;
	(void) line;
}
