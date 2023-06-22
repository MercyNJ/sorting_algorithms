#include "sort.h"

/**
 * swap_nodes - Swaps 2 nodes in a double linked lst.
 *
 * @list: Double pointer to head of list to be swapped.
 * @node1: 1st node to be swapped
 * @node2: 2nd node to be swapped
 *
 */

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
	{
		node1->prev->next = node2;
	}
	else
		*list = node2;
	if (node2->next)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node2->next = node1;
	node1->prev = node2;
}

/**
 * insertion_sort_list - Sorts double linked list in asce order.
 *
 * @list: Double pointer to list's head.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
			return;

	current = (*list)->next;
	while (current)
	{
		listint_t *temp = current;
		while (temp->prev && temp->n < temp->prev->n)
	{
		swap_nodes(&(*list), temp->prev, temp);
		print_list(*list);
	}
	current = current->next;
	}
}

