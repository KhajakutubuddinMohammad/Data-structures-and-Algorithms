#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<queue>

using namespace std;


struct node
{
    int key;
    struct node *left;
    struct node *right;
};
struct node* newnode(int data)
{
    struct node *root=(struct node*)malloc(sizeof(struct node));
    root->key=data;
    root->left=NULL;
    root->right=NULL;
    return root;
};
void inorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d",root->key);
    inorder(root->right);

}
void insert(struct node *root,int key)
{
    int s;
    queue <struct node*> q;
    q.push(root);
    struct node *temp=newnode(key);
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        if(s->left==NULL)
        {
           s->left=temp;
           break;
        }
        else
            s.push(s->left);
        if(s->right==NULL)
        {
            s->right=temp;
            break;
        }
        else
        {
           s.push(s->right);
        }
    }
}
int main()
{
    struct node *root=newnode(1);
    root->left=new node(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    root->right->right=newnode(7);
    insert(root,6);
    inorder(root);
    return 0;
}
