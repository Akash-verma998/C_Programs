#include <stdio.h>
#include <stdlib.h>
int search(int A[],int,int);

int main()
{
    int T,N,K,A[100],i,p;
    printf("Enter the number of text:");
    scanf("%d",&T);
    while(T!=0)
    {
    	printf("\nEnter the number of element in the array:");
        scanf("%d",&N);
        printf("\nEnter the element:");
        for(i=0;i<N;i++)
        {
            scanf("\n%d",&A[i]);
        }
        printf("\nEnter the value that to be search:");
        scanf("%d",&K);
        p=search(A,N,K);
        printf("The number is present at index=%d\n\n",p);
        T--;
    }
    return 0;
}
int search(int A[],int N,int x)
{
    int i;
    for(i=0;i<N;i++)
    {
        if(x==A[i])
            return i;
    }
    return -1;
}
