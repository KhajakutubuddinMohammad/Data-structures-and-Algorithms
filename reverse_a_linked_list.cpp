#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    node(int data)
    {
        this->data=data;
        next=NULL;
    }
};
struct linkedlist
{
    node *head;
    linkedlist()
    {
        head=NULL;
    }
    void push(int data)
    {
        node *temp=new node(data);
        temp->next=head;
        head=temp;
    }
    void printList()
    {

        struct node *temp = head;
        while(temp)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    void reverse()
    {

        node *head1=NULL,*prev=NULL,*curr=head;
        while(curr)
        {
            head1=curr->next;
            curr->next=prev;
            //head1->next=curr;   //it is an error
            prev=curr;
            curr=head1;
        }
        head=prev;
    }

};
int main() {

    linkedlist ll;
    ll.push(1);
    ll.push(2);
    ll.push(3);
    cout<<"the linked list is :"<<endl;
    ll.printList();
    ll.reverse();
    cout<<endl<<"the reverse linked list is :"<<endl;
    ll.printList();
	return 0;
}
