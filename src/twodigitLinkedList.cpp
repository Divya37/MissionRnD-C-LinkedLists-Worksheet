/*
OVERVIEW:  Given a single linked list (two digits as a node).Convert that to number


INPUTS:  SLL head pointer

OUTPUT: Create a number from the linked list given ,In each node there are two numbers ,digit1 and digit1 ,
So if the nodes are 12->34->56->78 , Final number would be 12345678 ( Integer)

ERROR CASES:

NOTES: Only Postive Numbers
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int digit1;
	int digit2;
	struct node *next;
};

int convert_sll_2digit_to_int(struct node *head)
{
	int num = 0, count = 0;
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->digit1 = head->digit1;
	temp->digit2 = head->digit2;
	temp->next = head->next;
	//if (temp->digit1 == 0 && temp->digit2 == 0)
	//	return 0;
	while (temp!= NULL)
	{
		num = num * 10 + temp->digit1;
		num = num * 10 + temp->digit2;
		temp = temp->next;
	} 
	
	return num;
}
