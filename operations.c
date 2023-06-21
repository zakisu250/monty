#include "monty.h"

/**
 * pall - Print all list
 * @stack: Double linked list
 * @line_number: executed line
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;

	if (!temp)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * push - Insert a new value in list
 * @stack: Double linked list
 * @line_number: File line execution
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL, *tm = *stack;
	char *num;

	num = strtok(NULL, " \r\t\n");
	if (num == NULL || (_isdigit(num) != 0 && num[0] != '-'))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		frees_all();
		exit(EXIT_FAILURE);
	}
	temp = malloc(sizeof(stack_t));

	if (!temp)
	{
		fprintf(stderr, "Error: malloc failed\n");
		frees_all();
		exit(EXIT_FAILURE);
	}
	temp->n = atoi(num);

	if (var.MODE == 0 || !*stack)
	{
		temp->next = *stack;
		temp->prev = NULL;
		if (*stack)
			(*stack)->prev = temp;
		*stack = temp;
	}
	else
	{
		while (tm->next)
			tm = tm->next;
		tm->next = temp;
		temp->prev = tm;
		temp->next = NULL;
	}
}

/**
 * pint - Print last node
 * @stack: Double linked list
 * @line_number: File line execution
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
		{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		frees_all();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - Delete top of list
 * @stack: Double linked list
 * @line_number: File line execution
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack)
		{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		frees_all();
		exit(EXIT_FAILURE);
	}
	
	temp = *stack;
	*stack = temp->next;
	
	if (temp->next)
		temp->next->prev = NULL;
	free(temp);
}
