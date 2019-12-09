#include <stdio.h>
#include <stdlib.h>
int binary_search(int a[],int,int,int);

int main()
{
    int i,n,result,x,a[20];
    printf("Enter the number of element in the array:");
    scanf("%d",&n);
    printf("ENter the element :");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the number to be search:");
    scanf("%d",&x);
    result=binary_search(a,0,n-1,x);
    if(result==-1)
     	printf("Element is not present in the array ");
    else
     	printf("Element is present at index:%d",result);
    return 0;
}
int binary_search(int a[],int l,int r,int x)
{
    if(l<=r)
    {
        int mid=(l+r)/2;
        if(a[mid]==x)
            return mid;
        if(a[mid]>x)
           r=mid-1;
        else
           l=mid+1;
        binary_search(a,l,r,x);    
    }
    else
    return -1;
}
