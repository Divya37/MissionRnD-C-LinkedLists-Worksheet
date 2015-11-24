/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>
#include<malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * sortLinkedList(struct node *head)
{

	int i = 0, *arr, j = 0, size = 0, swap_temp = 0;
	arr = (int *)malloc(sizeof(int) * 20);
	struct node *temp = head;

	if (head == NULL)
		return NULL;

	while (temp != NULL)
	{
		arr[i++] = temp->num;
		temp = temp->next;
	}
	size = i;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (arr[i] < arr[j])
			{
				swap_temp = arr[i];
				arr[i] = arr[j];
				arr[j] = swap_temp;
			}
		}
	}
	temp = head;
	for (i = 0; i < size; i++)
	{
		temp->num = arr[i];
		temp = temp->next;

	}
	return head;
}