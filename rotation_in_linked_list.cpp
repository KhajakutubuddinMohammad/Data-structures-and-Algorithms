#include <iostream>
#include<stdio.h>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
void printList(struct node *n)
{
    while(n)
    {
        printf("%d ",n->data);
        n=n->next;
    }
}
void rotateList(struct node **head)
{
    struct node *temp=*head,*temp2=*head;
    while(temp->next->next)
    {
        temp=temp->next;
    }
    temp2=temp->next;
    temp->next=NULL;
    temp2->next=*head;
    *head=temp2;
}
int main() {
	struct node *head=(struct node *)malloc(sizeof(struct node));
	struct node *first=(struct node *)malloc(sizeof(struct node));
	struct node *second=(struct node *)malloc(sizeof(struct node));
	struct node *third=(struct node *)malloc(sizeof(struct node));
	head->data=1;
	head->next=first;
	first->data=2;
	first->next=second;
	second->data=3;
	second->next=third;
	third->data=4;
	third->next=NULL;
	cout<<"before rotation the list is :"<<endl;
	printList(head);
	rotateList(&head);
	cout<<endl<<"after 1 rotation the list is :"<<endl;
	printList(head);
	rotateList(&head);
	cout<<endl<<"after 2 rotation the list is :"<<endl;
	printList(head);
	return 0;
}
