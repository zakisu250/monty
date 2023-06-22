#include "monty.h"

/**
 * stack_free - frees a stack
 * @head: node stack
 */
void stack_free(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * pchar - prints the char at the top of the stack
 * @head: head of the stack
 * @counter: line_number
 * Return: void
 */
void pchar(stack_t **head, unsigned int counter)
{
	stack_t *hd;

	hd = *head;
	if (!hd)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(bus.file);
		free(bus.content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	if (hd->n > 127 || hd->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(bus.file);
		free(bus.content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", hd->n);
}

/**
 * pstr - prints the string starting at the top of the stack
 * @head: head of the stack
 * @counter: line_number
 * Return: void
 */
void pstr(stack_t **head, unsigned int counter)
{
	stack_t *hd;
	(void)counter;

	hd = *head;
	while (hd)
	{
		if (hd->n > 127 || hd->n <= 0)
		{
			break;
		}
		printf("%c", hd->n);
		hd = hd->next;
	}
	printf("\n");
}
