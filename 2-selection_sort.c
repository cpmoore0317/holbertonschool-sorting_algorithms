#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @size: Number of elements in the array
 *
 * Return: Void
 */

void selecttion_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[mid_idx])
				min_idx = j;
		}
		if (min_idx != i)
		{
			temp = array[i];
			array[i] = array[min_idx];
			array[mid_idx] = temp;

			print_array(array, size);
		}
	}
}
