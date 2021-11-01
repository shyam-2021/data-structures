#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *create(int x,struct node *l,struct node *r)
{
    struct node *t1;
    t1=(struct node *)malloc(sizeof(struct node));
    t1->data=x;
    t1->left=l;
    t1->right=r;
    return t1;
}
struct node *insert(int x,struct node *t)
{
    if(t==NULL)
    return create(x,NULL,NULL);
    else if(x<t->data)
    t->left=insert(x,t->left);
    else
    t->right=insert(x,t->right);
    return t;
} 
struct node *delete(struct node *t,int x)
{
    struct node*q;
    if(t==NULL)
    return NULL;
    if(x<t->data)
    t->left=delete(t->left,x);
    else if(x>t->data)
    t->right=delete(t->right,x);
    else
    {
        if((t->left==NULL)&&(t->right==NULL))
        return NULL;
        else if((t->left!=NULL)&&(t->right==NULL))
        return(t->left);
        else if((t->left==NULL)&&(t->right!=NULL))
        return(t->right);
        else
        {
            q=t->right;
            while(q->left!=NULL)
            q=q->left;
            t->data=q->data;
            t->right=delete(t->right,q->data);
        }
    }
    return t;
} 
int search(struct node*t,int x)
{
    if(t==NULL)
    return -1;
    if(x==t->data)
    {
        printf("\nfound:%d",t->data);
        return 1;
    } 
    else if(x<t->data)
    search(t->left,x);
    
    else
    search(t->right,x);
}
int min (struct node*t)
{
    if (t==NULL)
        return-1;
    while (t->left!=NULL)
        t=t->left;
        printf(" min:%d",t->data);
        return (t->data);
}
int max (struct node*t)
{
    if (t==NULL)
        return-1;
    while (t->right!=NULL)
        t=t->right;
        printf(" max:%d",t->data);
        return (t->data);
}
void inorder(struct node *t)
{
    if(t==NULL)
    return; 
    else
    {
        inorder(t->left);
        printf("%d...",t->data);
        inorder(t->right);
        
    }
}
void main()
{
  struct node *root=NULL;
   root=insert(43,root);
   root=insert(44,root);
   root=insert(45,root);
   root=insert(46,root);
   inorder(root);
   root=delete(root,43);
   inorder(root); 
   search(root,44);
   min(root);
   max(root);
}
