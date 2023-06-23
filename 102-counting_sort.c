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
 * counting_sort - Sorts array of ints in asc order
 *                 using counting sort algorithm
 *
 * @array: Array of ints
 * @size: Array size
 *
 * Description: Print counting array after setup
 */

void counting_sort(int *array, size_t size)
{
	int *count_array, *sorted_array;
	int max_value;
	int i;

	if (array == NULL || size < 2)
		return;

	sorted_array = malloc(sizeof(int) * size);
	if (sorted_array == NULL)
		return;

	max_value = get_max_value(array, size);
	count_array = malloc(sizeof(int) * (max_value + 1));
	if (count_array == NULL)
	{
		free(sorted_array);
		return;
	}

	for (i = 0; i < (max_value + 1); i++)
		count_array[i] = 0;

	for (i = 0; i < (int)size; i++)
		count_array[array[i]] += 1;

	for (i = 1; i < (max_value + 1); i++)
		count_array[i] += count_array[i - 1];

	print_array(count_array, max_value + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]] -= 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = sorted_array[i];

	free(sorted_array);
	free(count_array);
}
