#include "sort.h"
/**
 * insertion_sort_list - function to do 'insertion sort' Sorting Algorithm
 * @list: Pointer to double linked list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *after, *before, *temp1, *temp2, *temp3, *temp4;

	/* check if the list is null or is empty or is only one element */
	if (!list || !*list || !(*list)->next)
		return;
	/* move to the end of the list */
	for (after = *list; after; after = after->next)
	{
		/* move to the begin of the list */
		for (before = after; before->prev; before = before->prev)
		{
			/* compare the pair of values */
			/* if the 1st is greater than the 2nd */
			if (before->n < before->prev->n)
			{
				temp1 = before->prev->prev;
				temp2 = before->prev;
				temp3 = before;
				temp4 = before->next;
				/* change the 1st with the 2nd */
				if (temp1)
					temp1->next = temp3;
				else
					*list = temp3;
				/* the 2nd lower now is after the 1st greater */
				temp3->next = temp2;
				temp2->next = temp4;
				/* conect the last part of the list with the pair */
				if (temp4)
					temp4->prev = temp2;
				temp2->prev = temp3;
				temp3->prev = temp1;
				before = before->next;
				print_list(*list);
			}
			/* if the 1st is lower than the 2nd */
			else
				break;
		}
	}
}
