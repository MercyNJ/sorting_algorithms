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
 * heapify - Turns a binary tree to binary heap
 *
 * @array: Array to be heapified
 * @size: Size of heap
 * @i: Root index of subtree
 * @total_size: Array's total size
 */

void heapify(int *array, size_t size, int i, size_t total_size)
{
	int largest = i;
	int left_child = 2 * i + 1;
	int right_child = 2 * i + 2;

	if (left_child < (int)size && array[left_child] > array[largest])
		largest = left_child;

	if (right_child < (int)size && array[right_child] > array[largest])
		largest = right_child;

	if (largest != i)
	{
		swap_vals(&array[i], &array[largest]);
		print_array(array, total_size);
		heapify(array, size, largest, total_size);
	}
}

/**
 * heap_sort - Sorts an array of ints in asce order
 *             utilizing heap sort algorithm
 * @array: Array to be sorted
 * @size: The array size
 */

void heap_sort(int *array, size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		swap_vals(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}
