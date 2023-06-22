#include "sort.h"

void swap_nodes_forward(listint_t **list, listint_t **tail, listint_t **current_node);
void swap_nodes_backward(listint_t **list, listint_t **tail, listint_t **current_node);
void cocktail_sort_list(listint_t **list);

const sort_flag_t true_flag = { true };
const sort_flag_t false_flag = { false };

/**
 * swap_nodes_forward - Swaps a node in a listint_t doubly-linked list
 *                      with the node before it.
 * @list: A pointer to head of a doubly-linked list of ints.
 * @tail: A pointer to tail of the doubly-linked list.
 * @current_node: A pointer to current node being swapped.
 */
void swap_nodes_forward(listint_t **list, listint_t **tail, listint_t **current_node)
{
	listint_t *tmp = (*current_node)->next;

	if ((*current_node)->prev != NULL)
		(*current_node)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*current_node)->prev;
	(*current_node)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *current_node;
	else
		*tail = *current_node;
	(*current_node)->prev = tmp;
	tmp->next = *current_node;
	*current_node = tmp;
}

/**
 * swap_nodes_backward - Swaps a node in a listint_t doubly-linked list
 *                       with the node after it.
 * @list: A pointer to head of a doubly-linked list of ints.
 * @tail: A pointer to tail of the doubly-linked list.
 * @current_node: A pointer to current node being swapped.
 */
void swap_nodes_backward(listint_t **list, listint_t **tail, listint_t **current_node)
{
	listint_t *tmp = (*current_node)->prev;

	if ((*current_node)->next != NULL)
		(*current_node)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*current_node)->next;
	(*current_node)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *current_node;
	else
		*list = *current_node;
	(*current_node)->next = tmp;
	tmp->prev = *current_node;
	*current_node = tmp;
}

/**
 * cocktail_sort_list - Sorts a listint_t doubly-linked list of ints in
 *                      asc order using the cocktail shaker algorithm.
 * @list: A pointer to head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *current_node;
	sort_flag_t sorted_flag = false_flag;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL; tail = tail->next)
		;

	while (!sorted_flag.sorted)
	{
		sorted_flag.sorted = true_flag.sorted;

		for (current_node = *list; current_node != tail; current_node = current_node->next)
		{
			if (current_node->n > current_node->next->n)
			{
				swap_nodes_forward(list, &tail, &current_node);
				print_list((const listint_t *)*list);
				sorted_flag.sorted = false_flag.sorted;
			}
		}

		for (current_node = tail; current_node != *list; current_node = current_node->prev)
		{
			if (current_node->n < current_node->prev->n)
			{
				swap_nodes_backward(list, &tail, &current_node);
				print_list((const listint_t *)*list);
				sorted_flag.sorted = false_flag.sorted;
			}
		}
	}
}
