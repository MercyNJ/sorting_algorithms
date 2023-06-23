#include "sort.h"

/**
 * merge - Merges 2 sorted subarrays into one.
 * @array: Original array
 * @left: Left subarray
 * @left_size: Left subarray's size
 * @right: Right subarray
 * @right_size: Right subarray's size.
 *
 */

void merge(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
	size_t i, j, k;
	i = j = k = 0;

	printf("Merging...\n[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}

	while (i < left_size)
		array[k++] = left[i++];
	while (j < right_size)
		array[k++] = right[j++];

	printf("[Done]: ");
	print_array(array, left_size + right_size);
}

/**
 * merge_sort - Sorts an array of ints using
 *              merge sort algorithm.
 * @array: Array to be sorted
 * @size: Size of array
 *
 * Description: Top_down implementation of merge sort algorithm
 */

void merge_sort(int *array, size_t size)
{
	size_t i, mid, left_size, right_size;
	int *left, *right;

	if (size <= 1)
		return;

	mid = size / 2;
	left_size = mid;
	right_size = size - mid;

	left = malloc(left_size * sizeof(int));
	right = malloc(right_size * sizeof(int));

	if (left == NULL || right == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < left_size; i++)
		left[i] = array[i];

	for (i = mid; i < size; i++)
		right[i - mid] = array[i];

	merge_sort(left, left_size);
	merge_sort(right, right_size);

	merge(array, left, left_size, right, right_size);

	free(left);
	free(right);
}
