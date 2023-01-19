#include "sort.h"

/**
  * swap_int - swaps the values of two integers.
	* @a: pointer int
	* @b: pointer int
	*/
void swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a, *a = *b, *b = tmp;
}


/**
 * bubble_sort - bubble sort
 * @array: array to sort
 * @size: size of arr
 * Return: ptr to arr or null
 */
void bubble_sort(int *array, size_t size)
{
  size_t i = 0, end = size - 1, swapped = 0;

	if (!array)
    return;
  if (size < 2)
    return;
  while (array && i <= end)
  {
    /* lst elem */
    if (i == end)
    {
      /* printf("i = %ld, end = %ld, swapped = %ld\n", i, end, swapped); */
      /* restart if a swap occured, break else */
      if (swapped)
      {
        i = 0, end--, swapped = 0;
        continue;
      }
      else
        break;
    }
    /* code */
    if (array[i] > array[i + 1])
    {
      swap_int(array + i, array + (i + 1)), swapped = 1;
      print_array(array, size);
    }
    i++;
  }

  return;
}
