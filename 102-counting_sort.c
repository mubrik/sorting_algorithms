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
	while (i < size)	/* get max size in array */
	{
		if (array[i] > max_n)
			max_n = array[i];
		i++;
	}
	max_n++; /* accomodating for the max num itself */
	/* alloc */
	count_l = malloc(sizeof(int) * max_n), output = malloc(sizeof(int) * size);
	if (!count_l || !output)
	{
		free(count_l), free(output);
		return;
	}
	i = 0;	/* init both to be 0's */
	while (i < (size_t) max_n || i < size)
	{
		if (i < size)
			output[i] = 0;
		if (i < (size_t) max_n)
			count_l[i] = 0;
		i++;
	}
	for (i = 0; i < size; i++)	/* start counting */
		key = array[i], count_l[key] = count_l[key] + 1;
	for (i = 1; i < (size_t) max_n; i++)	/* sum computation */
		count_l[i] = count_l[i] + count_l[i - 1];
	for (i = 0; i < (size_t) max_n; i++)	/* debug print count */
		printf("%d%s", count_l[i], i == (size_t) (max_n - 1) ? "\n" : ", ");
	for (i = 0; i < size; i++)	/* sort in output by using count and decr-- */
		key = array[i], pos = count_l[key] = count_l[key] - 1, output[pos] = key;
	for (i = 0; i < size; i++)	/* modify original */
		array[i] = output[i];
	free(count_l), free(output);	/* free */
}
