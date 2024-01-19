#include "monty.h"

char *__line__ = NULL;
FILE *__file__ = NULL;
char *__line_content__ = NULL;
int __type__ = 0;
/**
 *main - monty code interpreter
 *@argc: number of arguments
 *@argv: monty file location
 *Return: 0 on success
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	process_file(argv[1]);
	return (0);
}
