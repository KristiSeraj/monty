#include "monty.h"
/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument values
 * Return: 0 success
 */
int main(int argc, char **argv)
{
	if (argc != 2)
		usage_error();
	open_file(argv);
	return (0);
}
