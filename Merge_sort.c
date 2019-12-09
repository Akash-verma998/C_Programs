#include <stdio.h>
#include <stdlib.h>
void mergesort(int a[] ,int );
void printArray(int a[] ,int );
void merge(int a[] ,int l[] ,int r[],int ,int);

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
    mergesort(a,n);
    printArray(a,n);
    return 0;
}
void mergesort(int a[],int n)
{
    int mid,i,*l,*r;
    if(n<2)
     return ;
     mid=n/2;
     l=(int*)malloc(mid*sizeof(int));
     r=(int*)malloc((n-mid)*sizeof(int));
     for(i=0;i<mid;i++)
        l[i]=a[i];
     for(i=mid;i<n;i++)
        r[i-mid]=a[i];
    mergesort(l,mid);
    mergesort(r,n-mid);
    merge(a,l,r,mid,n-mid);
    free(l);
    free(r);
}
void merge(int a[],int l[],int r[],int left_count ,int right_count)
{
    int i,j,k;
    i=0;
    j=0;
    k=0;
    while((i<left_count)&&(j<right_count))
    {
        if(l[i]<r[j])
        {
            a[k]=l[i];
            i++;
        }
        else
        {
            a[k]=r[j];
            j++;
        }
            k++;

    }
    while(i<left_count)
    {
        a[k]=l[i];
        i++;
        k++;
    }
    while(j<right_count)
    {
        a[k]=r[j];
        j++;
        k++;
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

