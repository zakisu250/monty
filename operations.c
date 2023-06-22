#include "monty.h"

/**
 * initiate - executes the opcode
 * @stack: head linked list - stack
 * @counter: line_counter
 * @file: pointer to monty file
 * @content: line content
 * Return: no return
 */
int initiate(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opcode_list[] = {
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	{"pop", pop},
	{"swap", swap},
	{"add", add},
	{"nop", nop},
	{"sub", sub},
	{"div", f_div},
	{"mul", mul},
	{"mod", mod},
	{"pchar", pchar},
	{"pstr", pstr},
	{NULL, NULL}};
	unsigned int i = 0;
	char *op_code;

	op_code = strtok(content, " \n\t");
	if (op_code && op_code[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");

	while (opcode_list[i].opcode && op_code)
 	{
		if (strcmp(op_code, opcode_list[i].opcode) == 0)
		{
			opcode_list[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op_code && opcode_list[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op_code);
		fclose(file);
		free(content);
		stack_free(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
