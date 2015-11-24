/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};
struct node *sort_function(struct node **sort_head,struct node *lastnode, int data, int count)
{
	int i;
	struct node *temp;
	
	for (i = 0; i < count; i++)
	{
		if (*sort_head == NULL)
		{
			temp = (struct node *)malloc(sizeof(struct node));
			temp->data = data;
			temp->next = NULL;
			lastnode = *sort_head = temp;
		}
		else
		{
			temp = (struct node *)malloc(sizeof(struct node));
			temp->data = data;
			temp->next = NULL;
			lastnode->next = temp;
			lastnode = temp;
		}
	}
	return lastnode;
}
void sll_012_sort(struct node *head)
{
	int count0=0, count1=0, count2=0,i;
	struct node *temp, *lastnode,*sort_head;
	sort_head =lastnode = NULL;
	
	temp = head;
	while (temp!= NULL)
	{
		if (temp->data == 0)
			count0++;
		else if (temp->data == 1)
			count1++;
		else
			count2++;
		temp = temp->next;
	}
	
	if (count0 > 0)
		lastnode = sort_function(&sort_head, lastnode, 0, count0);
	if(count1 > 0)
		lastnode = sort_function(&sort_head, lastnode, 1, count1);
	if (count2 > 0)
		lastnode = sort_function(&sort_head, lastnode, 2, count2);

	head->data = sort_head->data;
	head->next = sort_head->next;
}