#include "sort.h"
/**
 * swap - function to swap elements in an array
 * @array: Pointer to array
 * @size: Size of the array
 * @left: The index to change
 * @right: The index to be changed
 * Return: void
 */
void swap(int *array, size_t size, int left, int right)
{
	int temp;

	if (array[left] != array[right])
	{
		temp = array[left];
		array[left] = array[right];
		array[right] = temp;
		/* this prints the change as the task demand */
		print_array(array, size);
	}
}
/**
 * lomuto_partition_func - Lomuto partition scheme function
 * @array: Pointer to array
 * @size: Size of the array
 * @start: Initial index
 * @end: Final index
 * Return: void
 */
int lomuto_partition_func(int *array, size_t size, size_t start, size_t end)
{
	size_t left = start, right = end, i;
	int pivot_value = array[end];

	for (i = left; i <= right; i++)
	{
		if (array[i] <= pivot_value)
		{
			/* first changes */
			swap(array, size, left, right);
			left++;
		}
	}
	/* last change */
	swap(array, size, left, right);
	return (left);
}
/**
 * my_quick_sort - personal function to do the task easy
 * @array: Pointer to array
 * @size: Size of the array
 * @start: Initial index
 * @end: Final index
 * Return: void
 */
void my_quick_sort(int *array, size_t size, size_t start, size_t end)
{
	size_t pivot_num = 0;

	if (start < end)
	{
		/* because the Lomuto algorithm require a star and end index */
		/* this function allows do the same algorithm without the */
		/* restriction of inputs given by the prototipe's task*/
		pivot_num = lomuto_partition_func(array, size, start, end);
		my_quick_sort(array, size, start, pivot_num - 1);
		my_quick_sort(array, size, pivot_num + 1, end);
	}
}
/**
 * quick_sort - function to do 'quick sort' Sorting Algorithm
 * @array: Pointer to array
 * @size: Size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
	{
		return;
	}
	my_quick_sort(array, size, 0, size - 1);
}
