/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K)
{
	int i=0,j=0,size=0;
	struct node *temp,*prev;
	temp = head;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	size = i;
	
	if (head == NULL || K == 0 || K == 1 || K < 0)
		return NULL;
	else if (K > size)
		return head;
	else
	{
		prev = head;
		temp =prev->next;
		for (i = 2; i<=size; i++)
		{
			if (i%K==0)
			{
				prev->next = temp->next;
			}
			prev = temp;
			temp = temp->next;
		}
		return head;
	}
}