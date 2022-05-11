#include "monty.h"
/* global variable */
int num;
/**
 * _push - function that inserts new node in the beginning of the
 * doubly linked list
 * @top: pointer
 * @line: line
 */
void _push(stack_t **top, __attribute__((unused)) unsigned int line)
{
	stack_t *new_Node = malloc(sizeof(stack_t));

	if (new_Node == NULL)
		printf("Error\n");
	new_Node->n = num;
	new_Node->prev = NULL;

	if (*top == NULL)
	{
		new_Node->next = NULL;
		*top = new_Node;
	}
	else
	{
		new_Node->next = *top;
		(*top)->prev = new_Node;
		*top = new_Node;
	}
}
/**
 * _pall - function that prints all elements in a doubly linked list
 * @top: pointer
 * @line: line
 */
void _pall(stack_t **top, __attribute__((unused)) unsigned int line)
{
	stack_t *tmp = *top;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * _pint - function that prints the value of the top element
 * @top: pointer
 * @line: line
 */
void _pint(stack_t **top, unsigned int line)
{
	if (*top != NULL)
		printf("%d\n", (*top)->n);
	else
	{
		printf("L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
}
/**
 * _pop - function that deletes the top element
 * @top: pointer
 * @line: line
 */
void _pop(stack_t **top, unsigned int line)
{
	stack_t *tmp = *top;

	if (*top == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}
	tmp = tmp->next;
	free(*top);
	*top = tmp;
}
/**
 * _free - function that frees elements of stack
 * @top: pointer
 */
void _free(stack_t *top)
{
	stack_t *tmp;

	if (top == NULL)
		return;
	while (top != NULL)
	{
		tmp = top;
		top = top->next;
		free(tmp);
	}
	free(top);
}
