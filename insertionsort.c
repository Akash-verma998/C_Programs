#include <stdio.h>
#include <stdlib.h>
void insertionsort(int a[],int n);
void printArray(int a[],int n);

int main()
{
    int a[5000],n,i;
    printf("Enter the number of the elements in array:  ");
    scanf("%d",&n);
    printf("Enter the element of the of unsorted array:\n ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    insertionsort(a,n);
    printArray(a,n);
    return 0;
}
void insertionsort(int a[],int n)
{
	int i,hole,value;
   for(i=1;i<n;i++)
   { 
       value=a[i];
       hole=i;
       while(a[i-1]>value&&hole>0)
       {
       	 a[i]=a[i-1];
       	 hole=hole-1;
       	 i=i-1;
	   }
	   a[hole]=value;
   }
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

