#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: double pointer to the head of the stack
 * @line_number: line number in the Monty byte code file
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *last;

	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		last = *stack;

		while (last->next != NULL)
			last = last->next;

		temp->next = NULL;
		last->next = temp;
		temp->prev = last;
	}
}
