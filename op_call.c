#include "monty.h"

void (*get_op(char *token, __attribute__((unused)) unsigned int line))(stack_t **, unsigned int)
{
	int j;
	instruction_t op[] = {
		{"push", _push},
		{"pop", _pop},
		{"pint", _pint},
		{"pall", _pall},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}
	};
	for (j = 0; op[j].opcode != NULL; j++)
	{
		if (strcmp(token, op[j].opcode) == 0)
			return (op[j].f);
	}
	return (NULL);
}
