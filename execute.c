#include "monty.h"

/**
 *execute - executes the opcode
 *@content: line content
 *@stack: head linked list - stack
 *@counter: line_counter
 *@file: pointer to monty file
 *Return: no return
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	/*Opcode and its corresponding function pair */
	instruction_t opst[] = {
		{ "push", f_push},
		{ "pall", f_pall},
		{ "pint", f_pint},
		{
			NULL, NULL
		}
	};
	/*Get the opcode by extracting the first token indicating the instruction */
	char *opcode = strtok(content, " \n\t");

	/*If opcode is not presented or # is found (indicating a comment), return 0 */
	if (opcode == NULL || opcode[0] == '#')
	{
		return (0);
	}
	/*Get the next token by calling strtok again */
	__line__ = strtok(NULL, " \n\t");
	/*Loop to match the opcode with the function that will be executed */
	/*Compare the first token with the instruction_t array */
	for (unsigned int i = 0; opst[i].opcode != NULL; ++i)
	{
		if (strcmp(opcode, opst[i].opcode) == 0)
		{ /*Call the stack function to perform the instruction */
			opst[i].f(stack, counter);
			return (0);
		}
	}
	/*If the file contains an unknown instruction */
	fprintf(stderr, "L%d: unknown instruction %s\n", counter, opcode);
	fclose(file);
	free(content);
	free_stack(*stack);
	exit(EXIT_FAILURE);
	return (1);
}
