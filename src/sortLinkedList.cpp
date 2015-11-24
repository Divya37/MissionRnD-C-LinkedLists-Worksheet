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
	struct node *temp1, *temp2, *swap_temp;
	temp1 = (struct node *)malloc(sizeof(struct node));
	temp1->num = head->num;
	temp1->next = head->next;
	temp2 = (struct node *)malloc(sizeof(struct node));
	temp2->num = head->num;
	temp2->next = head->next;
	swap_temp = (struct node *)malloc(sizeof(struct node));
	if (head == NULL)
		return NULL;
	while (temp1->next != NULL)
	{
		temp2->num = head->num;
		temp2->next = head->next;
		while (temp2->next != NULL)
		{
			if (temp1->num > temp2->num)
			{
				swap_temp->num = temp2->num;
				temp2->num = temp1->num;
				temp1->num = swap_temp->num;

			}
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}