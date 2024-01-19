#include "monty.h"

/**
 *f_pall - prints the stack
 *@head: stack head
 *@counter: no used
 *Return: no return
 */
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *current_node;
	(void) counter;

	current_node = *head;

	while (current_node)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}
