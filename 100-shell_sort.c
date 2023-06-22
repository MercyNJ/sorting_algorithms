#include "sort.h"

/**
 * swap_vals - Swaps 2 ints in an array.
 * @a: The 1st int to be swapped.
 * @b: The 2nd int to be swapped.
 */

void swap_vals(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * shell_sort - Sorts array of ints in asc order
 *              utilizing knuth sequence.
 *
 * @array: Array to be sorted
 * @size: Count of elems in array
 */

void shell_sort(int *array, size_t size)
{
	size_t interval = 1;
	size_t i, j;

	while (interval < size / 3)
		interval = interval * 3 + 1;
	while (interval >= 1)
	{
		for (i = interval; i < size; i++)
		{
			for (j = i; j >= interval && array[j - interval] > array[j]; j -= interval)
			{
				swap_vals(&array[j], &array[j - interval]);
			}
		}
		interval = interval / 3;
		print_array(array, size);
	}
}
