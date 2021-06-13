#include "sort.h"
/**
 * swap - function to swap elements in an array
 * @array: Pointer to double linked list
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
		print_array(array, size);
	}
}
/**
 * lomuto_partition_func - Lomuto partition scheme function
 * @array: Pointer to double linked list
 * @start_num: Initial index
 * @size: Size of the array
 * Return: void
 */
int lomuto_partition_func(int *array, int start_num, size_t size)
{
	size_t i, left = start_num, right = size;
	int pivot_value = array[size];

	for (i = 0; i <= right; i++)
	{
		if (array[i] <= pivot_value)
		{
			swap(array, size, left, right);
			left++;
		}
	}
	swap(array, size, left, right);
	return (left);
}
/**
 * quick_sort - function to do 'quick sort' Sorting Algorithm
 * @array: Pointer to array
 * @size: Size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	size_t start_num = 0;
	int pivot_num = 0;

	if (start_num < size)
	{
		pivot_num = lomuto_partition_func(array, start_num, size);
		quick_sort(array, (pivot_num - 1));
		quick_sort(array, size);
	}
}
