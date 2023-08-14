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
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *current = (*list)->next;
	while (current != NULL)
	{
		listint_t *temp = current;
		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			if (temp->next != NULL)
				temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;

			if (temp->prev == NULL)
				*list = temp;
			else
				temp->prev->next = temp;

			print_list(*list);

			temp = temp->prev;
		}
		current = current->next;
	}
}
