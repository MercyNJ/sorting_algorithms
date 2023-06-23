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
 * bitonic_merge - Recursive helper function for bitonic sort
 * @array: Array to be sorted
 * @low: Start index of sequence
 * @count: Num of elems to sort
 * @dir: Sorting direction - 1 ASCENDING 0 DESCENDING.
 */

void bitonic_merge(int *array, size_t low, size_t count, int dir)
{
	if (count > 1)
	{
		size_t k = count / 2;
		size_t i;

		for (i = low; i < low + k; ++i)
		{
			if ((array[i] > array[i + k]) == dir)
			{
				swap_vals(&array[i], &array[i + k]);
			}
		}
		bitonic_merge(array, low, k, dir);
		bitonic_merge(array, low + k, k, dir);
	}
}

/**
 * bitonic_sort_recursive - Bitonic sort's recursive function
 * @array: To be sorted
 * @low: Start index of sequence being orted
 * @count: Num of elems
 * @dir:  Sorting direction - 1 ASCENDING 0 DESCENDING.
 */

void bitonic_sort_recursive(int *array, size_t low, size_t count, int dir)
{
	if (count > 1)
	{
		size_t k = count / 2;

		bitonic_sort_recursive(array, low, k, 1);
		bitonic_sort_recursive(array, low + k, count - k, 0);

		bitonic_merge(array, low, count, dir);
	}
}

/**
 * bitonic_sort - Sorts array of ints using bitonic sort in asc order
 *
 * @array: Array to sort
 * @size: Array size
 */

void bitonic_sort(int *array, size_t size)
{
	/*size_t i;*/

	printf("Merging [%lu/%lu] (UP):\n", size, size);
	print_array(array, size);

	bitonic_sort_recursive(array, 0, size, 1);

	printf("Result [%lu/%lu] (UP):\n", size, size);
	print_array(array, size);
}
