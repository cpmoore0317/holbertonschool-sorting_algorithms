#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * using Insertion sort
 * @list: Pointer to a pointer to the beginning of the list
 *
 * Return: Void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *sorted, *temp;

	if (!list || !*list || !(*list)->next)
		return;

	sorted = (*list)->next;
	while (sorted)
	{
		current = sorted;
		sorted = sorted->next;

		while (current->prev && current->n < current->prev->n)
		{
			temp = current->prev;
			if (current->next)
				current->next->prev = temp;
			temp->next = current->next;
			current->next = temp;
			current->prev = temp->prev;
			temp->prev = current;

			if (current->prev)
				current->prev->next = current;
			else
				*list = current;

			print_list(*list);
		}
	}
}
