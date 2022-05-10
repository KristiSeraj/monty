#include "monty.h"

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
