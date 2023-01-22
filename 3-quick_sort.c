#include "sort.h"


/**
 * partition - get partition index using lomuto scheem
 * @array: array to sort
 * @low: lower bound index
 * @high: max index
 * @size: arr size
 * Return: size_t
 * Description: This divides the array into 2 sections such that elements
 * at left of final index are smaller than array[high]/pivot
 */
ssize_t partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	/* 1st temp pivot/tracker index i, changes in loop */
	ssize_t i = low - 1, j = low;
	int pivot, tmp;
	/* lamouth scheme, last elem as 2nd pivot */
	pivot = array[high];
	while (j <= (high - 1))
	{
		/* left side of array < high (2nd) pivot */
		if (array[j] <= pivot)
		{
			i++;
			/* check if swap necessary */
			if (j != i)
			{
				tmp = array[j], array[j] = array[i], array[i] = tmp;
				print_array(array, size);
			}
		}
		j++;
	}
	/* increment and swap last tracked i index with pivot, if ! same position */
	i++;
	if (high != i)
	{
		tmp = array[high], array[high] = array[i], array[i] = tmp;
		print_array(array, size);
	}
	return (i);
}

/**
 * quick_sort_r - quick_sort recursive call
 * @array: array to sort
 * @low: lower bound index
 * @high: max index
 * @size: arr size
 * Return: works recursivel till left hand index lower than lo
 */
void quick_sort_r(int *array, ssize_t low, ssize_t high, size_t size)
{
	ssize_t part;
	/* base condition */
	if (low >= high || low < 0)
		return;
	/* get partition index to split array */
	part = partition(array, low, high, size);
	/* divide and conquer, sort left and right side */
	quick_sort_r(array, low, part - 1, size);
	quick_sort_r(array, part + 1, high, size);
}

/**
 * quick_sort - quick_sort
 * @array: array to sort
 * @size: size of array to sort
 * Return: ptr to arr or null
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick_sort_r(array, 0, size - 1, size);
}

