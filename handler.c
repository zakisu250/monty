#include "monty.h"

/**
 * glob_vars - Jackpot for Giga Millions
 * @var: global variables to initialize
 * Return: 0 if success or a if failed
 */

int glob_vars(vars *var)
{
	var->file = NULL;
	var->buff = NULL;
	var->tmp = 0;
	var->dict = new_dict();

	if (var->dict == NULL)
		return (EXIT_FAILURE);

	var->head = NULL;
	var->line_number = 1;
	var->MODE = 0;

	return (EXIT_SUCCESS);
}

/**
 * new_dict - Create new functions dictionary
 * Return: pointer to a dictionary
 */
instruction_t *new_dict()
{
	instruction_t *ptr = malloc(sizeof(instruction_t) * 18);

	if (!ptr)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	ptr[1].opcode = "push", ptr[1].f = push;
	ptr[0].opcode = "pall", ptr[0].f = pall;
	ptr[3].opcode = "pop", ptr[3].f = pop;
	ptr[2].opcode = "pint", ptr[2].f = pint;
	return (ptr);
}

/**
 * opcode_call - call opcode functions
 * @var: global variable
 * @opcode: command to run
 * Return: Always success
 */
int opcode_call(vars *var, char *opcode)
{
	int n;
	
	for (n = 0; var->dict[n].opcode; n++)
	{
		if (!var->dict[n].f)
			return (EXIT_SUCCESS);
		var->dict[n].f(&var->head, var->line_number);
		return (EXIT_SUCCESS);
	}
	if (strlen(opcode) != 0 && opcode[0] != '#')
	{
		fprintf(stderr, "%u: unknown instruction %s\n",
		var->line_number, opcode);
		return (EXIT_SUCCESS);
	}

	return (EXIT_SUCCESS);
}

/**
 * frees_all - Free all allocated memory
 * Return: void
 */
void frees_all(void)
{
	if (var.buff != NULL)
		free(var.buff);

	if (var.file != NULL)
		free(var.file);

	free(var.dict);
	if (var.head != NULL)
	{
		while (var.head->next != NULL)
		{
			var.head = var.head->next;
			free(var.head->prev);
		}
		free(var.head);
	}
}

/**
 * _isdigit - Check if the character is digit
 * @str: string to check
 * Return: 0 Success, 1 Failed
 */
int _isdigit(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] < 48 || str[i] > 57)
			return (1);
	}
	return (0);
}
