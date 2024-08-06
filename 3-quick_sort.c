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
            i++;
            if (i != j)
            {
                simple_swp(&array[i], &array[j]);
                print_array(array, size);
            }
        }
    }
    if (array[high] < array[i + 1])
    {
        simple_swp(&array[i + 1], &array[high]);
        print_array(array, size);
    }
    return i + 1;
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
  int low, high, pivot;
  
  low = 0;
  high = size - 1;

  if (low < high)
  {
    pivot = lumuto_part(array, low, high, size);
    quick_sort(array, low, pi - 1);
    quick_sort(array, pi + 1, high);
  }
}