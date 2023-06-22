#include "sort.h"

void swap_vals(int *a, int *b);
int lomuto_partition(int *array, int low, int high);
void quicksort(int *array, int low, int high);
void quick_sort(int *array, size_t size);

void swap_vals(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Uses lomuto scheme to partition array.
 *
 * @array: Array to be partitioned.
 * @low: Start index
 * @high: End index
 *
 * Return: Pivot Index.
 */

int lomuto_partition(int *array, int low, int high)
{
	int i, j, pivot;

	i = low - 1;
	pivot = array[high];

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap_vals(&array[i], &array[j]);
				print_array(array, high + 1);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		swap_vals(&array[i + 1], &array[high]);
		print_array(array, high + 1);
	}
	return (i + 1);
}

/**
 * quicksort - Sorts array in asc order using quicksort
 *             while utilizing lomuto partition scheme.
 *
 * @array: Array to be sorted.
 * @low: Start index 
 * @high: Array's ending index.
 *
 */

void quicksort(int *array, int low, int high)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high);

		quicksort(array, low, pivot_index - 1);
		quicksort(array, pivot_index + 1, high);
	}
}

/**
 * quick_sort - Wrapper funct to handle checks before using quicksort.
 *
 * @array: Array to sort
 * @size: Array size
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1);
}
