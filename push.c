#include "monty.h"

/**
 *f_push - Adds a node to the stack
 *@head: Pointer to the stack head
 *@counter: Line number
 *Return: No return value
 */
void f_push(stack_t **head, unsigned int counter)
{
	int number, index = 0;

	if (__line__)
	{
		if (__line__[0] == '-')
			index++;

		while (__line__[index] != '\0')
		{
			if (__line__[index] > '9' || __line__[index] < '0')
			{
				fprintf(stderr, "L%d: usage: push integer\n", counter);
				handle_error_cleanup(*head);
			}

			index++;
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		handle_error_cleanup(*head);
	}

	number = atoi(__line__);

	if (__type__ == 0)
		addnode(head, number);
	else
		addqueue(head, number);
}

/**
 *handle_error_cleanup - Handles error, closes file and frees memory
 *@head: Pointer to the stack head
 *Return: No return value
 */
void handle_error_cleanup(stack_t *head)
{
	fclose(__file__);
	free(__line_content__);
	free_stack(head);
	exit(EXIT_FAILURE);
}
