#include "monty.h"
/**
 * _pchar - function that prints the char at the top of the stack
 * followed by a new line
 * @top: pointer
 * @line: line
 */
void _pchar(stack_t **top, unsigned int line)
{
	int c;

	if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line);
		exit(EXIT_FAILURE);
	}

	c = (*top)->n;
	if (c < 0 || c > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line);
		exit(EXIT_FAILURE);
	}

	putchar(c);
	putchar('\n');
}
/**
 * _pstr - function that prints the string starting at the top of the stack
 * @top: pointer
 * @line: line
 */
void _pstr(stack_t **top, __attribute__((unused)) unsigned int line)
{
	int s;

	if (*top == NULL)
		putchar('\n');
	while (*top != NULL)
	{
		s = (*top)->n;
		if (s <= 0 || s > 127)
			break;
		putchar(s);
		*top = (*top)->next;
	}
	putchar('\n');
}
