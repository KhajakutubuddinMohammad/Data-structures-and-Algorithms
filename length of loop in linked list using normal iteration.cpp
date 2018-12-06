
/not supporting in this compiler but correct
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
    unordered_set<node *> s;
    struct node *temp=NULL;
    int count=1;
    while(n!=NULL)
    {
        if(s.find(n)==s.end())
         {
             s.insert(n);
         }
         else
         {
             temp=n;
             break;
         }
         n=n->next;
    }
   // return 0;
    if(temp==NULL)
      return 0;
    struct node *temp1=temp;
    while(temp1->next!=temp)
    {
        count+=1;
        temp1=temp1->next;
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
