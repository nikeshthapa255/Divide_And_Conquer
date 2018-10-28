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
void addnode(int k)
{
    if (head==NULL)
    {
        printf("%d,head\n",k);
        head=(node*)malloc(sizeof(node));
        head->key=k;
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
                    node *t;
                    t=(node*)malloc(sizeof(node));
                    t->key=k;
                    t->parent=temp;
                    temp->right=t;
                    return;
                }               
            }
            if (temp->key>=k)
            {
                if(temp->left!=NULL)
                {
                    printf("%d,head",temp->key);
                    temp=temp->left;
                }
                else{
                    printf("%d,left\n",k);
                    node *t;
                    t=(node*)malloc(sizeof(node));
                    t->key=k;
                    t->parent=temp;
                    temp->left=t;
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