#include "monty.h"
/**
 * get_op - function pointer that takes argument of function in struct
 * @token: token
 * @line: line
 */
void (*get_op(char *token, unsigned int line))(stack_t **, unsigned int)
{
	int j;
	instruction_t op[] = {
		{"push", _push},
		{"pop", _pop},
		{"pint", _pint},
		{"pall", _pall},
		{"swap", _swap},
		{"add", _add},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"nop", _nop},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL}
	};
	for (j = 0; op[j].opcode != NULL; j++)
	{
		if (strcmp(token, op[j].opcode) == 0)
			return (op[j].f);
	}
	invalid_instruction(token, line);
	return (NULL);
}
