#include "monty.h"
int val;
int main(int argc, char **argv)
{
	ssize_t line;
	FILE *fp;
	char *buff = NULL, *token = NULL;
	size_t length = 0;
	unsigned int line_counter = 1;
	stack_t *top = NULL;

	if (argc != 2)
		printf("error");
	fp = fopen(argv[1], "r");
	if (fp == NULL)
		printf("error");
	
	while ( (line = getline(&buff, &length, fp)) != -1)
	{
		token = strtok(buff, "\n\t\r ");
		printf("Token = %s\n", token);
		
		if (*token == '\0')
			continue;
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, "\n\t\r ");
			printf("Token 2: %s\n", token);
			val = atoi(token);
			printf("Val %d\n", val);
			_push(&top, line_counter);
		}
		if (strcmp(token, "pall") == 0)
		{
			printf("Pall success\n");
			_pall(&top, line_counter);
			printf("succes\n");
		}
		line_counter++;
	}
	fclose(fp);
	
	if (buff != NULL)
		free(buff);
	_free(top);
	return (1);
}
		

