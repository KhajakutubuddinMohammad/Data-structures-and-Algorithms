#include <iostream>
#include <stdlib.h>
#include <unordered_set>
using namespace std;

struct node
{
    int value;
    struct node *next;
};
void printList(struct node *n)
{
    while(n!=NULL)
    {
        printf("%d ",n->value);
        n=n->next;
    }
}
void checkDuplicates(struct node *n)
{
      unordered_set<int> s;
      struct node *temp=n;
      struct node *n1=n;
      int d;
      s.insert(n1->value);
      n1=n1->next;
      while(n1!=NULL)
      {

          d=n1->value;
          if(s.find(d) != s.end())
          {
               temp->next=n1->next;
               n1=NULL;
               n1=temp;
          }
          else
          {
             s.insert(d);
             temp=temp->next;
          }
          n1=n1->next;
      }
}
int main() {
	struct node *first=(struct node *)malloc(sizeof(struct node));
	struct node *second=(struct node *)malloc(sizeof(struct node));
	struct node *three=(struct node *)malloc(sizeof(struct node));
	struct node *four=(struct node *)malloc(sizeof(struct node));
	struct node *five=(struct node *)malloc(sizeof(struct node));
	struct node *six=(struct node *)malloc(sizeof(struct node));
	first->value=1;
	first->next=second;
	second->value=1;
	second->next=three;
	three->value=3;
	three->next=four;
	four->value=3;
	four->next=five;
	five->value=3;
	five->next=six;
	six->value=6;
	six->next=NULL;
	checkDuplicates(first);
	printList(first);
	return 0;
}
