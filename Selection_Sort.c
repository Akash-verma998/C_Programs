#include <stdio.h>
#include <stdlib.h>
void selectionsort(int a[],int n);
void swap(int*,int*);
void printArray(int a[],int n);

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
    printf("\nUnsorted Array: ");
    printArray(a,n);
    selectionsort(a,n);
    printf("\nSorted Array:   ");
    printArray(a,n);
    return 0;
}
void selectionsort(int a[],int n)
{
	int i,j,min;
	for(i=0;i<(n-1);i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
			    min=j;
		}
		swap(&a[i],&a[min]);
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
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

}

