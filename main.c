#include "monty.h"
int main(int argc, char **argv)
{
	if (argc != 2)
		usage_error();
	open_file(argv);
	return (0);
}
