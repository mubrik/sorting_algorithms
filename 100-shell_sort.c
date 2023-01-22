#include "sort.h"


/**
 * shell_sort - shell_sort
 * @array: array to sort
 * @size: arr size
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i = 0, j = 0;
	int tmp;
	/* increment gap to the max, kuth seq */
	while (gap < size)
		gap = (gap * 3) + 1;
	/* main loop */
	while (gap > 0)
	{
		/* loop through array, if gap/i is higher loop wont run, decr/= */
		for (i = gap; i < size; i++)
		{
			/* save vl at curr index */
			tmp = array[i];
			/* starting at the current index, check if prev gapped index val gt */
			for (j = i; (j >= gap) && (array[j - gap] > tmp); j -= gap)
				array[j] = array[j - gap];
			array[j] = tmp;
		}
		if (gap < size)
			print_array(array, size);
		/* decrement gap proper */
		gap /= 3;
	}
}
