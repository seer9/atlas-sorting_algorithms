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
 * lomuto_part - simply pivots the array
 *
 * @array: The array to be sorted
 * @low: The lower bound of the array or left
 * @high: The upper bound of the array or right
 * @size: The size of the array
 * Return: The pivot index
 */
int lomuto_part(int *array, int low, int high, size_t size)
{
    int pivot, i, j;
    
    pivot = array[high];
    i = low;
    
    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            if (i != j)
            {
                simple_swp(&array[i], &array[j]);
                print_array(array, size);
            }
            i++;
        }
    }
    if (i != high)
    {
    simple_swp(&array[i], &array[high]);
    print_array(array, size);
    }
    return (i);
}
/**
 * sort_quik - Sorts an array of integers with quick sort
 *
 * @array: The array to be sorted
 * @low: The lower bound of the array or left
 * @high: The upper bound of the array or right
 * @size: The size of the array
 */
void sort_quik(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pivot_index = lomuto_part(array, low, high, size);
        sort_quik(array, low, pivot_index - 1, size);
        sort_quik(array, pivot_index + 1, high, size);
    }
}
/**
 * quick_sort - Sorts an array of integers with sort_quik
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;
    sort_quik(array, 0, size - 1, size);
}