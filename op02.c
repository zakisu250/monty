#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @head: pointer to head
 * @counter: line_number
 * Return: void
 */
void add(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	hd = *head;
	tmp = hd->n + hd->next->n;
	hd->next->n = tmp;
	*head = hd->next;
	free(hd);
}

/**
 * nop - nothing
 * @head: pointer to head
 * @counter: line_number
 * Return: void
 */
void nop(stack_t **head, unsigned int counter)
{
	(void)counter;
	(void)head;
}

/**
 * sub - subtraction of top two elements of the stack
 * @head: pointer to head
 * @counter: line_number
 * Return: void
 */
void sub(stack_t **head, unsigned int counter)
{
	stack_t *tmp;
	int sus, nodes;

	tmp = *head;
	for (nodes = 0; tmp != NULL; nodes++)
		tmp = tmp->next;

	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	sus = tmp->next->n - tmp->n;
	tmp->next->n = sus;
	*head = tmp->next;
	free(tmp);
}

/**
 * div - divides the top two elements of the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void div(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
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
	tmp = hd->next->n / hd->n;
	hd->next->n = tmp;
	*head = hd->next;
	free(hd);
}

/**
 * mul - multiplies the top two elements of the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void mul(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}

	hd = *head;
	aux = hd->next->n * hd->n;
	hd->next->n = aux;
	*head = hd->next;
	free(hd);
}
