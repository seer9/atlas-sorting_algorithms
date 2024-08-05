#include "sort.h"
/**
 * simple_swp - Swaps two nodes
 *
 * @first: first node to be swapped
 * @second: second node to be swapped
 */
void simple_swp(int *first, int *second)
{
	int temp;

	temp = *first;
	*first = *second;
	*second = temp;
}
/**
 * selection_sort - Sorts an array of integers with selection sort
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, pos;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < size; i++)
	{
		pos = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[pos])
				pos = j;
		}
		if (pos != i)
		{
			simple_swp(&array[i], &array[pos]);
			print_array(array, size);
		}
	}
}
