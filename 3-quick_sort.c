#include "sort.h"
/**
 * swap - function to swap elements
 *
 * @a: Pointer to array
 * @b: Size of the array
 *
 * Return: void
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition_func - Lomuto partition scheme function
 *
 * @array: Pointer to array
 * @size: Size of the array
 * @start: Initial index
 * @end: Final index
 *
 * Return: void
 */

int lomuto_partition_func(int *array, int start, int end, size_t size)
{
	int pivot_value = array[end];
	int i = start, j;

	for (j = start; j < end; j++)
	{
		if (array[j] <= pivot_value)
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}

			i++;
		}
	}

	if (i != end)
	{
		swap(&array[i], &array[end]);
		print_array(array, size);
	}

	return (i);
}
/**
 * my_quick_sort - personal function to do the task easy
 * @array: Pointer to array
 * @size: Size of the array
 * @start: Initial index
 * @end: Final index
 * Return: void
 */
void my_quick_sort(int *array, int start, int end, size_t size)
{
	int pivot_num = 0;

	if (start < end)
	{
		pivot_num = lomuto_partition_func(array, start, end, size);
		my_quick_sort(array, start, pivot_num - 1, size);
		my_quick_sort(array, pivot_num + 1, end, size);
	}
}
/**
 * quick_sort - function to do 'quick sort' Sorting Algorithm
 *
 * @array: Pointer to array
 * @size: Size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	my_quick_sort(array, 0, size - 1, size);
}
