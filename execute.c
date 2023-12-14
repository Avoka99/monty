#include "monty.h"

/**
 * execute - parse and execute Monty instructions
 * @instruction: instruction string
 * @stack: double pointer to the head of the stack
 * @line_number: line number in the Monty byte code file
 */
void execute(char *instruction, stack_t **stack, unsigned int line_number)
{
	char *opcode, *arg;
	int value;

	opcode = strtok(instruction, " \t\n");
	if (!opcode)
		return;

	if (strcmp(opcode, "push") == 0)
	{
		arg = strtok(NULL, " \t\n");
		if (!arg || !is_numeric(arg))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		value = atoi(arg);
		push(stack, value, line_number);
	}
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(stack, line_number);
	}
	else if (strcmp(opcode, "pint") == 0)
	{
		pint(stack, line_number);
	}
	else if (strcmp(opcode, "pop") == 0)
	{
		pop(stack, line_number);
	}
	else if (strcmp(opcode, "swap") == 0)
	{
		swap(stack, line_number);
	}
	else if (strcmp(opcode, "add") == 0)
	{
		add(stack, line_number);
	}
	else if (strcmp(opcode, "nop") == 0)
	{
		nop(stack, line_number);
	}
	else if (strcmp(opcode, "sub") == 0)
	{
		sub(stack, line_number);
	}
	else if (strcmp(opcode, "div") == 0)
	{
		div_op(stack, line_number);
	}
	else if (strcmp(opcode, "mul") == 0)
	{
		mul(stack, line_number);
	}
	else if (strcmp(opcode, "mod") == 0)
	{
		mod(stack, line_number);
	}
	else if (strcmp(opcode, "pchar") == 0)
	{
		pchar(stack, line_number);
	}
	else if (strcmp(opcode, "pstr") == 0)
	{
		pstr(stack, line_number);
	}
	else if (strcmp(opcode, "rotl") == 0)
	{
		rotl(stack, line_number);
	}
	else if (strcmp(opcode, "rotr") == 0)
	{
		rotr(stack, line_number);
	}
	else if (strcmp(opcode, "stack") == 0)
	{
		stack_op(stack, line_number);
	}
	else if (strcmp(opcode, "queue") == 0)
	{
		queue(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}

/**
 * is_numeric - check if a string is a numeric value
 * @str: string to check
 * Return: 1 if numeric, 0 otherwise
 */
int is_numeric(char *str)
{
	int i = 0;

	if (!str)
		return (0);

	while (str[i])
	{
		if (!isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			return (0);
		i++;
	}

	return (1);
}
