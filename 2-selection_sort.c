#include "sort.h"


void simple_swp(int *first, int *second)
{
  int temp;

  temp = *first;
  *first = *second;
  *second = temp;
}

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