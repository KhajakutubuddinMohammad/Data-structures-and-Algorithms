#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;
int checkpalindrome(struct node *);
stack<char> s;

struct node
{
    char data;
    struct node *next;
};
int checkpalindrome(struct node *n)
{
    struct node *head=n;
    char d;
    int flag=1;
    while(head!=NULL)
    {
        s.push(head->data);
        head=head->next;
    }
    while(n!=NULL)
    {
        d=s.top();
        if(d!=n->data)
        {
           flag=0;
           break;
        }
        s.pop();
        n=n->next;
    }
    if(flag==1)
       return 1;
    else
       return 0;
}
int main() {
    struct node *head=(struct node*)malloc(sizeof(struct node));
    struct node *first=(struct node*)malloc(sizeof(struct node));
    struct node *second=(struct node*)malloc(sizeof(struct node));
    struct node *third=(struct node*)malloc(sizeof(struct node));
    struct node *four=(struct node*)malloc(sizeof(struct node));
    head->data='R';
    head->next=first;
    first->data='A';
    first->next=second;
    second->data='D';
    second->next=third;
    third->data='A';
    third->next=four;
    four->data='R';
    four->next=NULL;
    //checkpalindrome(head);
    if(checkpalindrome(head))
        cout<<"its a palindrome"<<endl;
    else
       cout<<"its not a  palindrome"<<endl;
	return 0;
}
