#include "monty.h"
/**
 * _pchar - function that prints the char at the top of the stack
 * followed by a new line
 * @top: pointer
 * @line: line
 */
void _pchar(stack_t **top, unsigned int line)
{
	int c = (*top)->n;

	if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	if (c < 0 || c > 127)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	putchar(c);
	putchar('\n');
}
