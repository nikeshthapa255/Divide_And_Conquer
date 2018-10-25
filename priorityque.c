#include <stdio.h>
#include <stdlib.h>
#define P printf
#define Sc scanf
int n=0;
void swap(int *a,int *b)
{
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;
}
void heapadd(int *a,int x)
{
    int i,*temp;
    int *b=(int*)malloc((n+1)*sizeof(int));
    for(i=0;i<n;i++)
    b[i]=a[i];
    b[n]=x;
    temp=a;
    a=b;
    n=n+1;
    free(temp);
}
int pop(int *a)
{
    int i;
    int x=*(a+n-1);
    int *b=(int*)malloc((n-1)*sizeof(int));
    for(i=0;i<n-1;i++)
    b[i]=a[i];
    int *temp=a;
    a=b;
    free(temp);
    n=n-1;
    return x;
}
int maximum_value(int *a)
{
    swap(a+0,a+n-1);
    int s=pop(a);
    heapify(a);
    return s;

}
int checkgarb(int a)
{
    if (a<n)
    return 0;
    return 1; 
}
//to make priority queu of whole array
void heapify(int *a)
{
    int i;
    for(i=(int)n/2;i>=0;i--)
    max_heapify(a,i);
}
void max_heapify(int *a,int i)
{
    
    if (checkgarb(2*(i+1)-1)==0 && a[i]<(a[2*(i+1)-1]))
    {
    swap(a+i,a+2*(i+1)-1);max_heapify(a,2*(i+1)-1);
    }
    if (checkgarb(2*(i+1))==0 && a[i]<(a[2*(i+1)]))
    {
    swap(a+i,a+2*(i+1));max_heapify(a,2*(i+1));
    }
}
void displayarray(int *a)
{
    int i=0;
    while(i<n)
    {
        P("%d ",*(a+i++));
    }
    P("\n");
}
//display whole heap
void displayheap(int *a)
{
    //displayarray(a,n);
    int i=0;
    for (i=0;i<(int)n/2;i++)
    {
        if (checkgarb(2*(i+1)-1)){
            P("\t \nroot:-%d\n\t right:-%d\n\n\n",a[i],a[2*(i+1)]);
            continue;}
        if (checkgarb(2*(i+1))){
            P("\t left:-%d\nroot:-%d\n\t\n\n\n",a[2*(i+1)-1],a[i]);
            continue;}
        P("\t left:-%d\nroot:-%d\n\t right:-%d\n\n\n",a[2*(i+1)-1],a[i],a[2*(i+1)]);
    }
}

void main()
{
    P("Enter size of heap");
    Sc("%d",&n);
    int *a=(int*)malloc(n*sizeof(int));
    P("enter elements of heap");
    int i;
    for(i=0;i<n;i++)
    Sc("%d",a+i);
    heapify(a);
    displayheap(a);
    heapadd(a,pop(a));
    displayheap(a);
}