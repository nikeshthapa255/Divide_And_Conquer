#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int key;
    struct node *parent;
    struct node *left,*right;
}node; 
node *head=NULL;
void display(node *a)
{
    //in fix display ,Left - Root - Right
    if (a->left==NULL && a->right==NULL)
    {printf("%d ",a->key);
    return;}
    if(a->left!=NULL)
    display(a->left);
    printf("%d ",a->key);
    if(a->right!=NULL)
    display(a->right);
}
node* search(int k)
{
    node *temp=head;
    while (1)
    {   
        if(temp->key<=k && temp->right!=NULL)
        temp=temp->right;
        else if (temp->key>k && temp->left!=NULL)
        temp=temp->left;
        else
        break;
    }
    if (temp->key==k)
    return temp;
    return NULL;
}
void removeNhelp(node *t,node *rp)
{
    if (t->parent->key>t->key)
    {//parent is in left
        t->parent->left=rp;}
    else
    {
        //right of its parent
        t->parent->right=rp;
    }
            
}
void removeN(int k)
{
    node *t=search(k);
    if(t==NULL){
        printf("Unable to find any such key as ->%d",k);
        return ;}
    else
    {
        if(t->left==NULL && t->right==NULL){
            removeNhelp(t,NULL);
            free(t);}
        else if (t->left!=NULL && t->right!=NULL)
        {
            (t->right)->parent=t->parent;
            node *temp=t->right;
            while(1)
            {
                if(temp->left!=NULL)
                temp=temp->left;
                else
                break;
            }
            (t->left)->parent=temp;
            temp->left=t->left;
            removeNhelp(t,t->right);
            free(t);
        }
        else if(t->left!=NULL && t->right==NULL)
        {
            (t->left)->parent=t->parent;
            removeNhelp(t,t->left);
            free(t);
        }
        else if(t->left==NULL && t->right!=NULL)
        {
            (t->right)->parent=t->parent;
            removeNhelp(t,t->right);
            free(t);
        }
    }
}
void addN(node **a,node *pa,int k)
{
    node *t=(node*)malloc(sizeof(node));
    t->key=k;
    t->parent=pa;
    *a=t;
}
void addnode(int k)
{
    if (head==NULL)
    {
        printf("%d,head\n",k);
        addN(&head,NULL,k);
        return;
    }
    else{
        node *temp=head;
        while (1)
        {
            if (temp->key<=k)
            {
                if(temp->right!=NULL)
                {
                    printf("%d,head",temp->key);
                    temp=temp->right;
                } 
                else{
                    printf("%d,right\n",k);
                    addN(&(temp->right),temp,k);
                    return;
                }               
            }
            if (temp->key>k)
            {
                if(temp->left!=NULL)
                {
                    printf("%d,head",temp->key);
                    temp=temp->left;
                }
                else{
                    printf("%d,left\n",k);
                    addN(&(temp->left),temp,k);
                    return;
                }
            }
        }
    }
}
void main()
{
    int n;
    printf("Enter range of array-");
    scanf("%d",&n);
    printf("enter elements into array-");
    int i,a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    //converting an array into a BST with 1st element as pointed by head
    for(i=0;i<n;i++)
    {
        addnode(a[i]);
    }
    display(head);
}