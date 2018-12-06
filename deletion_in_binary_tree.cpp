#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<queue>

using namespace std;

void deletDeepest(struct node*,struct node*);
void deletion(struct node*,int );
struct node
{
    int key;
    struct node *left;
    struct node *right;
};
struct node* newnode(int data)
{
    struct node *root=new node;
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
    printf("%d  ",root->key);
    inorder(root->right);

}
void deletDeepest(struct node *root,struct node *d_node)
{
    cout<<"hii"<<endl;
    queue <struct node*> q;
    q.push(root);

    // Do level order traversal until last node
    struct node* temp;
    while(!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp->right)
        {
            if (temp->right == d_node)
            {
                temp->right = NULL;
                delete(d_node);
                return;
            }
            else
                q.push(temp->right);
        }

        if (temp->left)
        {
            if (temp->left == d_node)
            {
                temp->left=NULL;
                delete(d_node);
                return;
            }
            else
                q.push(temp->left);
        }
    }
}

void deletion(struct node *root,int data)
{
    queue<struct node*> q;
    struct node *temp1=NULL;
    struct node *s;
    q.push(root);
    while (!q.empty())
    {
      s=q.front();
      q.pop();

      if(s->key == data)
          temp1=s;

      if(root->left)
        q.push(root->left);

      if(root->right)
          q.push(root->right);

    }
    cout<<"hello";
    int x=s->key;
    deletDeepest(root,s);
    temp1->key=x;
}






int main()
{
    struct node *root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    root->right->left=newnode(6);
    root->right->right=newnode(7);
    printf("the inorder traversal of the tree before deleting is:\n");
    inorder(root);
    deletion(root,6);
    inorder(root);
    return 0;

}


