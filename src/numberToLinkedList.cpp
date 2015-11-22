/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * numberToLinkedList(int N)
{
	int i, temp, *arr, length;
	struct node *head, *temp_var, *lastnode;
	lastnode = (struct node *)malloc(sizeof(struct node));
	head = NULL;

	if (N < 0)
		N = N*-1;
	if (N == 0)
	{
		head = (struct node*)malloc(sizeof(struct node));
		head->num = N;
		head->next = NULL;
		return head;
	}
	temp = N;

	for (i = 0; temp > 0; i++)
		temp = temp / 10;
	length = i;
	arr = (int *)malloc(sizeof(int)*i);
	for (i = 0; N > 0; i++)
	{
		arr[i] = N % 10;
		N = N / 10;
	}
	temp = 0;
	
	for (i = length - 1; i >= 0; i--)
	{
		if (head == NULL)
		{
			temp_var = (struct node *)malloc(sizeof(struct node));
			temp_var->num = arr[i];
			temp_var->next = NULL;			
			lastnode =head= temp_var;
		}
		else
		{			
			temp_var = (struct node *)malloc(sizeof(struct node));
			temp_var->num = arr[i];
			temp_var->next = NULL;	
			lastnode->next = temp_var;
			lastnode = temp_var;
		}
	}	
	return head;
}