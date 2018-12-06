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
void reverse(struct node **head,struct node *prev,struct node *curr)
{
    if(!curr->next)
    {
        *head=curr;
        curr->next=prev;
        return ;
    }
    struct node *temp=curr->next;
    curr->next=prev;
    prev=curr;
    curr=temp;

    reverse(head,prev,curr);

}
int main()
{
        struct node *head=(struct node *)malloc(sizeof(struct node));
        struct node *first=(struct node *)malloc(sizeof(struct node));
        struct node *second=(struct node *)malloc(sizeof(struct node));
        head->data=1;
        head->next=first;
        second->data=3;
        second->next=NULL;
        first->data=2;
        first->next=second;
        printList(head);
        reverse(&head,NULL,head);
        cout<<endl;
        printList(head);
        return 0;
}
