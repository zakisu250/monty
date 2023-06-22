#include "monty.h"

/**
 * pall - prints all the element of the stack
 * @head: pointer to head
 * @counter: no used
 * Return: void
 */
void pall(stack_t **head, unsigned int counter)
{
	stack_t *hd;
	(void)counter;

	hd = *head;
	if (hd == NULL)
		return;
	while (hd)
	{
		printf("%d\n", hd->n);
		hd = hd->next;
	}
}

/**
 * push - add node to the stack
 * @head: pointer to head
 * @counter: line_number
 * Return: void
 */
void push(stack_t **head, unsigned int counter)
{
  int n, j = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			stack_free(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(bus.arg);
	
	if (bus.line_fi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}

/**
 * pint - prints the top element
 * @head: pointer to head
 * @counter: line_number
 * Return: void
 */
void pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * pop - delete the top element
 * @head: pointer to head
 * @counter: line_number
 * Return: void
 */
void pop(stack_t **head, unsigned int counter)
{
	stack_t *hd;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: Can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	hd = *head;
	*head = hd->next;
	free(hd);
}

/**
 * swap - adds the top two elements of the stack.
 * @head: pointer to head
 * @counter: line_number
 * Return: void
 */
void swap(stack_t **head, unsigned int counter)
{
	stack_t *hd;
	int len = 0, aux;

	hd = *head;
	while (hd)
	{
		hd = hd->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	hd = *head;
	aux = hd->n;
	hd->n = hd->next->n;
	hd->next->n = aux;
}
