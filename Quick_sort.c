#include <stdio.h>
#include <stdlib.h>
void quicksort(int a[] ,int ,int );
void printArray(int a[] ,int );
void swap(int* ,int*);
int partition(int a[] ,int ,int);

int main()
{
    int a[50],n,i;
    printf("Enter the number of the elements in array:  ");
    scanf("%d",&n);
    printf("Enter the element of the of unsorted array:\n ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    quicksort(a,0,n-1);
    printArray(a,n);
    return 0;
}
void quicksort(int a[],int start,int end)
{
    int p;
    if(start>=end)
        return ;
    p=partition(a,start,end);
    quicksort(a,start,p-1);
    quicksort(a,p+1,end);
}
int partition(int a[],int start,int end)
{
    int pivot,p,i;
    pivot=a[end];
    p=start;
    for(i=start;i<end;i++)
    {
        if(a[i]<=pivot)
        {
            swap(&a[i],&a[p]);
             p++;
        }

    }
     swap(&a[p],&a[end]);
     return p;
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
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }

}

