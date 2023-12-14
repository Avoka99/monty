#include "monty.h"

/**
 * queue - sets the format of the data to a queue (FIFO)
 * @stack: double pointer to the head of the stack
 * @line_number: line number in the Monty byte code file
 */
void queue(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack, *temp;

	(void)line_number;

	while (current != NULL && current->next != NULL)
		current = current->next;

	if (current != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		temp->next = NULL;
		temp->prev = current;
		current->next = temp;
	}
}
