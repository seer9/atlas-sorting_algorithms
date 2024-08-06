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


int lomuto_part(int *array, int low, int high, size_t size)
{
    int pivot, i, j;
    
    int pivot = array[high];
    int i = low;
    int j;

    
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


void sort_helper(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pivot_index = lomuto_part(array, low, high, size);
        sort_helper(array, low, pivot_index - 1, size);
        sort_helper(array, pivot_index + 1, high, size);
    }
}


void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;
    quicksort_helper(array, 0, size - 1, size);
}