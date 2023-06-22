#include "monty.h"
/**
 * rotl- rotates the stack to the top
 * @head: pointer to head
 * @counter: line_number
 * Return: void
 */
void rotl(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *head, *temp;

	if (*head == NULL || (*head)->next == NULL)
		return;
	
	temp = (*head)->next;
	temp->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = temp;
}

/**
 * rotr- rotates the stack to the bottom
 * @head: pointer to head
 * @counter: line_number
 * Return: void
 */
void rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *temp;

	temp = *head;
	if (*head == NULL || (*head)->next == NULL)
		return;
	while (temp->next)
		temp = temp->next;

	temp->next = *head;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*head)->prev = temp;
	(*head) = temp;
}

/**
 * f_stack - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.line_fi = 0;
}
