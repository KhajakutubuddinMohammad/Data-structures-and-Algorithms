#include<iostream>
#include<stdio.h>
#include <stdlib.h>
#include <stack>
using namespace std;

struct node{
    char data;
    struct node *next;
};
stack<char> s;
int checkpalindrome(struct node *n)
{
     static int count=0;
     struct node *fast=n;
     struct node *slow=n;
     char d;
     while(fast!=NULL && fast->next!=NULL)
     {
         count+=1;
         slow=slow->next;
         fast=fast->next->next;
     }
     while(slow!=NULL){
         s.push(slow->data);
         slow=slow->next;
     }
     while(!s.empty() && count!=0)
     {
         d=s.top();
         if(d!=n->data)
         {
            return 0;
         }
         s.pop();
         count-=1;
         n=n->next;
     }
     return 1;
}
int main()
{
    struct node *head=(struct node *)malloc(sizeof(struct node));
    struct node *first=(struct node *)malloc(sizeof(struct node));
    struct node *second=(struct node *)malloc(sizeof(struct node));
    head->data='a';
    head->next=first;
    first->data='b';
    first->next=second;
    second->data='c';
    second->next=NULL;
    if(checkpalindrome(head)){
       cout<<"its a palindrome"<<endl;
    }
    else
       cout<<"its not a palindrome"<<endl;
    return 0;
}
