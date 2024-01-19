#include "monty.h"
/**
 * f_queue - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_queue(stack_t **head, unsigned int counter)
{
	(void)head;
		(void)counter;
		__type__ = 1;
}

/**
 * addqueue - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 * Return: no return
*/
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *traverser;

		new_node = malloc(sizeof(stack_t));
		if (new_node == NULL)
		{
			printf("Error\n");
			return;
		}

		new_node->n = n;
		new_node->next = NULL;

		traverser = *head;
		if (traverser)
		{
			while (traverser->next)
				traverser = traverser->next;
			new_node->prev = traverser;
			traverser->next = new_node;
		}
		else
		{
			*head = new_node;
			new_node->prev = NULL;
		}
	}
