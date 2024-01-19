#include "monty.h"

/**
 *addnode - add node to the head stack
 *@head: head of the stack
 *@n: new_value
 *Return: no return
 */
void addnode(stack_t **head, int n)
{
	stack_t *newNode, *temp;

	temp = *head;
	newNode = malloc(sizeof(stack_t));

	if (newNode == NULL)
	{
		fprintf(stderr, "Error: Unable to allocate memory\n");
		exit(EXIT_FAILURE);
	}

	newNode->n = n;
	newNode->next = *head;
	newNode->prev = NULL;

	if (temp != NULL)
	{
		temp->prev = newNode;
	}

	*head = newNode;
}
