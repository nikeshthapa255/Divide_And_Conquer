#include<stdio.h>
void disp(int a[],int size)
{
int i;
for(i=0;i<size;i++)
printf("%d ",a[i]);
}
void part(int a[],int l,int h)
{
int m=(h+l)/2;
merg(a,l,m,h);
}
void merg(int a[],int l,int m,int h)
{
if ((m-l+1)>1){
part(a,l,m);}
if((h-m)>1){
part(a,m+1,h);}
int b[h-l+1];

int i=0,j=0;
int k1,k2;
k1=m-l+1;
k2=h-m;
int n=0;
while(i<k1 && j<k2)
{
if(a[l+i]<a[m+1+j])
b[n++]=a[l+i++];
else
b[n++]=a[m+1+(j++)];
}
if(i>=k1)
while(j<k2)
b[n++]=a[m+1+(j++)];
else if(j>=k2)
while(i<k1)
b[n++]=a[l+i++];
for(i=0;i<(h-l+1);i++)
a[l+i]=b[i];
}
void main()
{
int n;
printf("Enter size of array");
scanf("%d",&n);
int a[n];
printf("enter array elments");
int i;
for(i=0;i<n;i++)
scanf("%d",&a[i]);
part(a,0,n-1);
disp(a,n);
}
