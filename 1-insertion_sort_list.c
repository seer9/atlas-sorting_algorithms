#include "sort.h"

/**
 * swap_nodes - Swaps the values of two nodes
 * @head: Pointer to the head of the list
 * @first_node: Pointer to the first node to be swapped
 * @second_node: Pointer to the second node to be swapped
 */
void swap_nodes(listint_t **head, listint_t *first_node, listint_t *second_node)
{
  if (first_node->prev)
    first_node->prev->next = second_node;
  else
    *head = second_node;

  if (second_node->next)
    second_node->next->prev = first_node;

  first_node->next = second_node->next;
  second_node->prev = first_node->prev;

  firs_node->prev = second_node;
  second_node->next = first_node;
}
/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * @list: Pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
  listint_t *current, *next;

  if (!list || !*list)
    return;

  current = *list;

  while (current->next)
    {
      next = current->next;
      if (current->n > next->n)
      {
        swap_nodes(list, current, next);
      }
      else
        current = next;
    }
}
