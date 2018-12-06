#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;

};
struct node *newnode(int data)
{
    struct node *root=(struct node*)malloc(sizeof(struct node));
    root->data=data;
    root->left=root->right=NULL;
    return(root);
};
void inorder(struct node *root)
{
    if(root==NULL)
      return;
    inorder(root->left);
    cout<<root->data<<"  ";
    inorder(root->right);

}
void preorder(struct node *root)
{
    if(root==NULL)
        return;
    cout<<root->data<<"  ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<"  ";
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
        inorder(root);
        cout<<"\n";
        preorder(root);
        cout<<"\n";

        postorder(root);
        return 0;
}
