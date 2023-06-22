#include "sort.h"

/**
 * swap_vals - Swaps 2 ints.
 *
 * @a: Pointer to 1st int to be swapped.
 * @b: Pointer to 2nd int to be swapped.
 *
 */

void swap_vals(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - Sorts array of ints in asce order.
 *
 * @array: Array to be sorted.
 * @size: Num of elements in array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}

		if (min_index != i)
		{
			swap_vals(&array[i], &array[min_index]);
			print_array(array, size);
		}
	}
}
