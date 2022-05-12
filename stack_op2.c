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
	stack_t *tmp;

	if (*top == NULL)
	{
		putchar('\n');
		return;
	}
	tmp = *top;
	while (tmp != NULL)
	{
		s = tmp->n;
		if (s <= 0 || s > 127)
			break;
		putchar(s);
		tmp = tmp->next;
	}
	putchar('\n');
}
/**
 * _rotl - function that rotates the stack of the top
 * @top: pointer
 * @line: line
 */
void _rotl(stack_t **top, __attribute__((unused)) unsigned int line)
{
	stack_t *tmp, *new_top, *h;

	if (*top == NULL || (*top != NULL && (*top)->next == NULL))
		return;
	tmp = *top;
	h = *top;

	while (tmp->next)
		tmp = tmp->next;
	new_top = (*top)->next;
	h->next = NULL;
	h->prev = tmp;
	tmp->next = h;
	new_top->prev = NULL;
	*top = new_top;
}

