#include "sort.h"
/**
 * quick_sort_ - function to do 'quick sort' Sorting Algorithm
 * @list: Pointer to double linked list
 * @size: Size of the array
 * Return: void
 */
int partition_func(int *array, int start_num, size_t size);
void swap(int *array, size_t size, int left, int right);

void quick_sort(int *array, size_t size)
{
	size_t start_num = 0;
	int pivot_num = 0;
	if (start_num < size)
	{
		pivot_num = partition_func(array, start_num, size);
		quick_sort(array, (pivot_num - 1));
		quick_sort(array, size);
	}
	return;
		
}
int partition_func(int *array, int start_num, size_t size)
{
	int temp;
	size_t i;
	int pivot_value = array[size];
	int left = start_num;
	int right = size;

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