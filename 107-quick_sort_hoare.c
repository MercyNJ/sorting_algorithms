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
 * hoare_partition - Order a subpart of array of ints
 *                   according to the hoare partition scheme.
 * @array: The array of ints.
 * @size: The size of array.
 * @left: The start index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, left_index, right_index;

	pivot = array[right];
	for (left_index = left - 1, right_index = right + 1; left_index < right_index;)
	{
		do {
			left_index++;
		} while (array[left_index] < pivot);
		do {
			right_index--;
		} while (array[right_index] > pivot);

		if (left_index < right_index)
		{
			swap_vals(array + left_index, array + right_index);
			print_array(array, size);
		}
	}

	return (left_index);
}

/**
 * hoare_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int partition_index;

	if (right - left > 0)
	{
		partition_index = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, partition_index - 1);
		hoare_sort(array, size, partition_index, right);
	}
}

/**
 * quick_sort_hoare - Sort an array of intes in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
