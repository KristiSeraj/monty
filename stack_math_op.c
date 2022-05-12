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
		fprintf(stderr, "L%u: can't add, stack too short\n", line);
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
void _sub(stack_t **top, unsigned int line)
{
	stack_t *tmp;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	tmp = (*top)->next;
	tmp->n -= (*top)->n;
	_pop(top, line);
}
/**
 * _div - function that divides the second top element by top element
 * @top: pointer
 * @line: line
 */
void _div(stack_t **top, unsigned int line)
{
	stack_t *tmp;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line);
		exit(EXIT_FAILURE);
	}
	tmp = (*top)->next;
	tmp->n /= (*top)->n;
	_pop(top, line);
}
/**
 * _mul - function that multiplies top two elements of stack
 * @top: pointer
 * @line: line
 */
void _mul(stack_t **top, unsigned int line)
{
	stack_t *tmp;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	tmp = (*top)->next;
	tmp->n *= (*top)->n;
	_pop(top, line);
}
/**
 * _mod - function that computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @top: pointer
 * @line: line
 */
void _mod(stack_t **top, unsigned int line)
{

	stack_t *tmp;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line);
		exit(EXIT_FAILURE);
	}
	tmp = (*top)->next;
	tmp->n %= (*top)->n;
	_pop(top, line);
}
