#include "sort.h"


/**
 * counting_sort - counting_sort
 * @array: list to sort
 * @size: size
 * Return: void
 * Description: This assumes the int in array > 0
 */
void counting_sort(int *array, size_t size)
{
	int max_n = 0, *count_l = NULL, *output = NULL, key = 0, pos = 0;
	size_t i = 0;

	/* quick check */
	if (size < 2)
		return;
	/* get max size in array */
	while (i < size)
	{
		if (array[i] > max_n)
			max_n = array[i];
		i++;
	}
	/* accomodation for the max num itself */
	max_n++;
	/* alloc */
	count_l = malloc(sizeof(int) * max_n);
	output = malloc(sizeof(int) * size);
	if (!count_l || !output)
	{
		free(count_l), free(output);
		return;
	}
	i = 0;
	/* init both to be 0's */
	while (i < (size_t) max_n || i < size)
	{
		if (i < size)
			output[i] = 0;
		if (i < (size_t) max_n)
			count_l[i] = 0;
		i++;
	}
	/* start counting */
	for (i = 0; i < size; i++)
		key = array[i], count_l[key] = count_l[key] + 1;
	/* sum computation */
	for (i = 1; i < (size_t) max_n; i++)
		count_l[i] = count_l[i] + count_l[i - 1];
	/* debug print count */
	for (i = 0; i < (size_t) max_n; i++)
		printf("%d%s", count_l[i], i == (size_t) (max_n - 1) ? "\n" : ", ");
	/* place number in output by using count and decrementing */
	for (i = 0; i < size; i++)
	{
		key = array[i], pos = count_l[key] = count_l[key] - 1;
		output[pos] = key;
	}
	/* modify original */
	for (i = 0; i < size; i++)
		array[i] = output[i];
	/* free */
	free(count_l), free(output);
}
