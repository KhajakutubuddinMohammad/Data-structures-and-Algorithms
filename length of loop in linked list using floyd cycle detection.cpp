#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int value;
    struct node *next;
};
int detectLoop(struct node *n)
{
    struct node *temp1=n;
    struct node *temp2=n;
    int count=1,flag=0;
    while(temp1!=NULL && temp2!=NULL && temp2->next!=NULL)
    {
        temp1=temp1->next;
        temp2=temp2->next->next;

        if(temp1==temp2)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
       return 0;
        while(temp2->next!=temp1)
        {
            count+=1;
            temp2=temp2->next;
        }
        return count;
}

int main() {
	//code
	struct node *head=(struct node *)malloc(sizeof(struct node));
	struct node *first=(struct node *)malloc(sizeof(struct node));
	struct node *second=(struct node *)malloc(sizeof(struct node));
	struct node *third=(struct node *)malloc(sizeof(struct node));
	struct node *four=(struct node *)malloc(sizeof(struct node));
	head->value=1;
	head->next=first;
	first->value=2;
	first->next=second;
	second->value=3;
	second->next=third;
	third->value=4;
	third->next=four;
	four->value=5;
	four->next=second;
	if(detectLoop(head))
	    printf("the number of nodes in a loop is %d\n",detectLoop(head));
	else
	   printf("there is no loop in the graph\n");
	return 0;
}

