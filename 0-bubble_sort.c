#include "sort.h"

const sort_flag_t true_flag = { true };
const sort_flag_t false_flag = { false };

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
 * bubble_sort - Sorts an array of ints in ascending order.
 * @array: Array of ints to be sorted.
 * @size: Size of array.
 *
 * Description: Prints array after each swap.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	sort_flag_t flag;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		flag.sorted = true;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_vals(&array[j], &array[j + 1]);
				flag.sorted = false;
				print_array(array, size);
			}
		}
		if (flag.sorted)
			break;
	}
}
