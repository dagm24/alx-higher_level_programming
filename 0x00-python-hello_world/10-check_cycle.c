#include <stdlib.h>
#include "lists.h"

/**
 * check_cycle - Checks if a singly-linked list contains a cycle.
 * @head: A singly-linked list.
 *
 * Return: If there is no cycle - 0.
 *         If there is a cycle - 1.
 */
int check_cycle(listint_t *head)
{
	listint_t *slow_ptr, *fast_ptr;

	if (head == NULL || head->next == NULL)
		return (0);
	slow_ptr = head->next;
	fast_ptr = head->next->next;
	while (slow_ptr && fast_ptr && fast_ptr->next)
	{
		if (slow_ptr == fast_ptr)
			return (1);
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;
	}
	return (0);
}
