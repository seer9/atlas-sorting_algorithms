#include "sort.h"

int lomuto_part(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j, temp;
    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            if (i != j)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                print_array(array, size);
            }
        }
    }
    if (array[high] < array[i + 1])
    {
        temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;
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