#include "sort.h"


/**
 * selection_sort - selection_sort
 * @array: array to sort
 * @size: size of array to sort
 * Return: ptr to arr or null
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, pos = 0;
	int sel_num, tmp;

	if (size < 2)
		return;

	while (array && i <= (size - 1))
	{
		sel_num = array[i], j = i + 1, pos = i;
		while (j <= (size - 1))
		{
			if (array[j] < sel_num)
				sel_num = array[j], pos = j;
			j++;
		}
		if (pos != i)
		{
			tmp = array[i], array[i] = sel_num, array[pos] = tmp;
			print_array(array, size);
		}
		i++;
	}
}

/**
 * selection_sort_b - selection_sort original
 * @array: array to sort
 * @size: size of array to sort
 * Return: ptr to arr or null
 */
void selection_sort_b(int *array, size_t size)
{
	size_t i = 0, j = 0;
	int sel_num, tmp;

	if (size < 2)
		return;

	while (array && i <= (size - 1))
	{
		sel_num = array[i], j = i + 1;
		while (j <= (size - 1))
		{
			if (array[j] < sel_num)
			{
				tmp = sel_num, sel_num = array[j], array[j] = tmp;
				print_array(array, size);
			}
			j++;
		}
		array[i] = sel_num, i++;
	}
}
