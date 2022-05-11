#include "monty.h"
int num;
int main(int argc, char **argv)
{
	void (*p_func)(stack_t **, unsigned int);
	ssize_t line;
	FILE *fp;
	char *buff = NULL, *token = NULL, command[1024];
	size_t length = 0;
	unsigned int line_counter = 1;
	stack_t *top = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((line = getline(&buff, &length, fp)) != -1)
	{
		token = strtok(buff, "\n\t\r ");

		if (*token == '\0')
			continue;
		strcpy(command, token);
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, "\n\t\r ");
			num = atoi(token);
			p_func = get_op(command, line_counter);
			p_func(&top, line_counter);
		}
		else
		{
			p_func = get_op(token, line_counter);
			p_func(&top, line_counter);
		}
		line_counter++;
	}
	fclose(fp);

	if (buff != NULL)
		free(buff);
	_free(top);
	return (0);
}
