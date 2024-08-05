#include "sort.h"

int lumuto_part(int *array, int low, int high, sizet_t size)
{
  int pivot = array[high];
  int i = low - 1;
  int j, temp;

  for (j = low; j < high; j++)
    {
      if (array[j] <= pivot)
      {
        i++;
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        print_array(array, size);
      }
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