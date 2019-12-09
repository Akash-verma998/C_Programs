#include <stdio.h>
#include <stdlib.h>
void bubblesort(int a[],int n);
void swap(int*,int*);
void printArray(int a[],int n);

int main()
{
    int a[5000],n,i;
    printf("Enter the number of the elements in array:  ");
    scanf("%d",&n);
    printf("Enter the element of the of unsorted array:\n ");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }

    bubblesort(a,n);
    printArray(a,n);
    return 0;
}
void bubblesort(int a[],int n)
{
    int i,j;
    for(i=2;i<=n;i++)
    {
        for(j=1;j<=(n-i+1);j++)
        {
            if(a[j]>a[j+1])
            swap(&a[j],&a[j+1]);
        }
    }
}
void swap(int *p,int *q)
{
    int temp;
    temp=*p;
    *p=*q;
    *q=temp;

}
void printArray(int a[],int n)
{
    int i;
    printf("SORTED ARRAY:\n");
    for(i=1;i<=n;i++)
    {
        printf("%d\t",a[i]);
    }
}
