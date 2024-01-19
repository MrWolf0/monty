#include "monty.h"
/**
 *process_file - process a file open and read
 *@filename: bytes_code file (monty)
 *Return: void
 */
void process_file(const char *filename)
{
	/* See nasser for fully explanation */
	/*This will hold the line that getline() read */
	/*Should initialize it to because getline() will use */
	/*to allocate the buffer and we will free it after finish */
	/*and to free it we should give it an initial value */
	char *line = NULL;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;
	/*Opening file with read mode */
	file = fopen(filename, "r");
	/*Assign file to the globe variable bus_file */
	/*Sharing the stream between files */
	__file__ = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		/* getline() will dynamically allocte the buffer so */
		/*there is no need to use malloc but we must free the buffer after finish */
		read_line = getline(&line, &size, file);
		/*share the every line with other functions through */
		/*bus_content which is an extern defined in monty.h*/
		__line_content__ = line;
		/*this is important to track line number for */
		/*handling error if found in unknown instruction */
		counter++;
		if (read_line > 0)
		{
			execute(line, &stack, counter, file);
		}
	}
	free_stack(stack);
	free(line);
	fclose(file);
}
