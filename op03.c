#include "monty.h"

/**
 * mod - computes the remainder of the top element of the stack
 * @head: pointer to head
 * @counter: line_number
 * Return: void
 */
void mod(stack_t **head, unsigned int counter)
{
	stack_t *hd;
	int len = 0, tmp;

	hd = *head;
	while (hd)
	{
		hd = hd->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	hd = *head;
	if (hd->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	tmp = hd->next->n % hd->n;
	hd->next->n = tmp;
	*head = hd->next;
	free(hd);
}

/**
 * addnode - add node to the head stack
 * @head: head of the stack
 * @n: new node data
 * Return: void
 */
void addnode(stack_t **head, int n)
{

	stack_t *new_node, *tmp;

	tmp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (tmp)
		tmp->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

/**
 * addqueue - add node to the tail stack
 * @n: new node data
 * @head: head of the stack
 * Return: void
 */
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *tmp;

	tmp = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}

	new_node->n = n;
	new_node->next = NULL;

	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
	}
	if (!tmp)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		tmp->next = new_node;
		new_node->prev = tmp;
	}
}
