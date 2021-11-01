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
void main()
{
  struct node *root=NULL;
   root=insert(43,root);
   root=insert(44,root);
   root=insert(45,root);
   root=insert(46,root);
}