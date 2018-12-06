#include<iostream>
#include<stdlib.h>
using namespace std;

//struct node *delete(struct node *,int );
struct node
{
  int key;
  struct node *left ,*right;
  int count,height;
};
struct node *newnode(int data)
{
    struct node *root=(struct node*)malloc(sizeof(struct node));
    root->left=root->right=NULL;
    root->key=data;
    root->count=1;
    root->height=1;
    return root;
};
int max(struct node *a,struct node *b)
{
    cout<<"entered into max\n";
    if(a==NULL || b==NULL)
        return 0;
    if (a==NULL)
        return b->height;
    if(b==NULL)
        return a->height;
    return (a->height>b->height) ? a->height:b->height ;
}
int getbalance(struct node *root)
{
    cout<<"entered into balance\n";
     if(root==NULL)
        return 0;

     if(root->left==NULL)
     {
        return -(root->right->height);
        cout<<"balance :left";
     }
    if(root->right==NULL)
    {
        cout<<"balance:right";
        return root->left->height;
    }
    cout<<"balance : both";
    return ((root->left->height) - (root->right->height));
}
struct node *inorder_successor(struct node *root)
{
    struct node *temp=root;

    while(temp->left!=NULL)
        temp=temp->left;
    return temp;
};
struct node *rotateleft(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    //  Update heights
    x->height = max(x->left->height, x->right->height)+1;
    y->height = max(y->left->height, y->right->height)+1;

    // Return new root
    return y;
};
struct node *rotateright(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(y->left->height,y->right->height)+1;
    x->height = max(x->left->height, x->right->height)+1;

    // Return new root
    return x;
};
struct node *insert(struct node *root,int data)
{

    if(root == NULL)
    {
        cout<<"\n"<<data<<" is entered\n"<<endl;
        return newnode(data);

    }
    if(data==root->key)
    {
        cout<<"\n entered into count\n";
        root->count+=1;
        return root;
    }
    if(data<root->key)
    {
        root->left=insert(root->left,data);
        cout<<root->left->key<<endl;
    }
    else
    {
        root->right=insert(root->right,data);
    }
    //cout<<"before max";
    root->height=max(root->left,root->right)+1;
    //cout<<"after max";
    int balance=getbalance(root);
    //cout<<"after balance";
    if(balance >1 &&  data > root->left->key)
    {
        root->left=rotateleft(root->left);
        return rotateright(root);
    }
    if(balance > 1 && data < root->left->key)
        return rotateright(root);

    if(balance <-1 && data>root->right->key)
        return rotateleft(root);

    if(balance <-1 && data<root->right->key)
    {
        root->right=rotateright(root->right);
        return rotateleft(root);
    }
    return root;

};
struct node *deleted(struct node *root,int data)
{
    cout<<"\n entered into deleted\n"<<endl;
    if(root==NULL)
        return root;

    if(data > root->key)
        root->right= deleted(root->right,data);

    else if(data < root->key)
        root->left=deleted(root->left,data);

    else
    {
        cout<<"\nroot found\n"<<endl;

        if(root->count>1)
        {
            (root->count)-=1;
            return root;
        }
        else if(root->left==NULL || root->right==NULL)
        {
            struct node *temp=root->left ? root->left:root->right;
            if(temp==NULL)
            {
                cout<<"\nleaf is deleted\n"<<endl;
                temp=root;
                root=NULL;
            }
            else
            {
                cout<<"node with one child is deleted";
               *root=*temp;

            }
            free(temp);
        }
        else
        {
            struct node *temp=inorder_successor(root->right);
            root->key=temp->key;
            root->right=deleted(root->right,temp->key);

        }
    }
    cout<<"came out";
        if(root==NULL)
        {
            cout<<"root =null";
            return root;

        }

        cout<<"before max";
        root->height=max((root->left),(root->right))+1;
        cout<<"after max";
        int balance=getbalance(root);
        cout<<"after balance";
        if(balance < -1 && getbalance(root->right) <= 0)
            return rotateleft(root);
        if(balance < -1 && getbalance(root->left) > 0)
        {
            root->right=rotateright(root->right);
            return rotateleft(root);

        }
        if(balance > 1 && getbalance(root->left) >= 0)
              return rotateright(root);
        if(balance > 1 && getbalance(root->left) < 0)
        {
            root->left=rotateleft(root->left);
            return rotateright(root);
        }


    cout<<"\nroot returned\n"<<endl;
    return root;

}
void inorder(struct node *root)
{
    if (root==NULL)
        return ;
    inorder(root->left);
    cout<<root->key<<"  "<<root->count<<endl;
    inorder(root->right);
}
int main()
{
    struct node *root=NULL;
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 9);
    root = insert(root, 7);
    root = insert(root, 17);
    cout<<"the inorder traversal of the avl tree is:"<<endl;
    inorder(root);

    root=deleted(root,10);
    cout<<"came into main";
    cout<<root->key<<"\n";
    inorder(root);
    return 0;
}
