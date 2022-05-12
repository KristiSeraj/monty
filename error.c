#include "monty.h"

void usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
void file_error(char **argv)
{
	char *name = argv[1];

	fprintf(stderr, "Error: Can't open file %s\n", name);
	exit(EXIT_FAILURE);
}
void invalid_instruction(char *token, unsigned int line)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line, token);
	exit(EXIT_FAILURE);
}
