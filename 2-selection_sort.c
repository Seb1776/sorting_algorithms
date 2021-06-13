#include "sort.h"

/**
 * selection_sort - 'selection' Sorting Algorithm
 *
 * @array: Pointer to array
 * @size: Size of the array
 * Return: void
 *
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, k, tmp;
	int min_pos, curr_pos;

	if (array)
	{
		for (j = 0; j < size; j++)
		{
			min_pos = array[j];
			curr_pos = 0;

			for (i = j; i < size; i++)
			{
				if (min_pos > array[i])
				{
					min_pos = array[i];
					k = i;
					curr_pos = 1;
				}
			}

			if (curr_pos == 1)
			{
				tmp = array[j];
				array[j] = array[k];
				array[k] = tmp;
				print_array(array, size);
			}
		}
	}
}
