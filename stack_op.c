#include "monty.h"
int num;
void _push(stack_t **top, __attribute__((unused))unsigned int line)
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
	printf("val of stack %d\n", (*top)->n);
}
void _pall(stack_t **top, __attribute__((unused)) unsigned int line)
{
	stack_t *tmp = *top;

	while (tmp != NULL)
	{
		printf("Num: %d\n", tmp->n);
		tmp = tmp->next;
	}
}
void _pint(stack_t **top, __attribute__((unused)) unsigned int line)
{
	if (*top != NULL)
		printf("%d\n", (*top)->n);
	else
		printf("Error\n");
}
void _pop(stack_t **top, __attribute__((unused)) unsigned int line)
{
	stack_t *tmp = *top;

	if (*top == NULL)
		printf("Error\n");
	tmp = tmp->next;
	free(*top);
	*top = tmp;
}
