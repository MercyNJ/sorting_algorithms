#include "sort.h"

/**
 * get_max_value - Determines largest value in array of ints.
 *
 * @array: Array of ints
 * @size: Array size.
 *
 * Return: Maximum integer in array
 */

int get_max_value(int *array, int size)
{
	int max_value, i;

	for (max_value = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}
	return max_value;
}

/**
 * counting_sort - Uses counting sort on an array based on a digit
 *
 * @array: Array being sorted
 * @size: Array's no of elememts
 * @digitPosition: Current digit pos (eg 1, 10, 100, etc)
 */

void counting_sort_radix(int *array, int size, int digitPosition)
{
	int *output, *count;
	int i;
	int max = 10;

	output = malloc(sizeof(int) * size);
	count = calloc(max, sizeof(int));

	if (!output || !count)
	{
		free(output);
		free(count);
		return;
	}

	for (i = 0; i < size; i++)
		count[(array[i] / digitPosition) % 10]++;

	for (i = 1; i < max; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / digitPosition) % 10] - 1] = array[i];
		count[(array[i] / digitPosition) % 10]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];


	free(output);
	free(count);
}

/**
 * radix_sort - Sorts array of ints using Radix sort algorithm
 * @array: Array being sorted
 * @size: Num of elements in array
 */

void radix_sort(int *array, size_t size)
{
	int max_value, digitPosition;

	if (size < 2)
		return;

	max_value = get_max_value(array, size);

	for (digitPosition = 1; max_value / digitPosition > 0; digitPosition *= 10)
	{
		counting_sort_radix(array, size, digitPosition);
		print_array(array, size);
	}

}
