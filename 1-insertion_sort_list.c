#include "sort.h"

/**
 * swap_nodes - Swaps the values of two nodes
 *
 * @head: head of the list
 * @first_node: first node to be swapped
 * @second_node: second node to be swapped
 */
void swap_nodes(listint_t **head, listint_t *first_node,
listint_t *second_node)
{
	if (first_node->prev)
	{
		first_node->prev->next = second_node;
	}
	else
	{
		*head = second_node;
	}

	if (second_node->next)
	{
		second_node->next->prev = first_node;
	}
	first_node->next = second_node->next;
	second_node->prev = first_node->prev;

	first_node->prev = second_node;
	second_node->next = first_node;
}
/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *
 * @list: head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next, *temp;

	if (!list || !*list)
	{
		return;
	}

	current = (*list)->next;

	while (current)
	{
		next = current->next;
		temp = current;

		while (temp->prev && temp->prev->n > temp->n)
		{
			swap_nodes(list, temp->prev, temp);
			print_list(*list);
		}
		current = next;
	}
}
