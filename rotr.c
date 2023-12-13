#include "monty.h"

/**
 *  * rotr - rotates the stack to the bottom
 *   * @stack: double pointer to the head of the stack
 *    * @line_number: line number in the Monty byte code file
 *     */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *last;

	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		last = *stack;
		while (last->next != NULL)
			last = last->next;

		temp = last;
		last->prev->next = NULL;
		last->prev = NULL;
		temp->next = *stack;
		(*stack)->prev = temp;
		*stack = temp;
	}
}
