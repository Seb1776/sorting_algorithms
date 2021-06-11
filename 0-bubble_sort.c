#include "sort.h"

/**
 * bubble_sort - 'bubble sort' Sorting Algorithm
 *
 * @array: Pointer to array
 * @size: Size of the array
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	unsigned int i, j, tmp;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < (size - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
