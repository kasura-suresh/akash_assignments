/*********************************************************
*
*To Calculate the size of the array and array passing
*Author: Akash Kumar Gupta
*Date: 21/2/2020
*
*********************************************************/
#include<stdio.h>
#include<stdlib.h>
#define X sizeof(arr)/sizeof(arr[0]);

int sum(int arr[],int m);

int main()
{
    int n,i,arr[100],p;
    printf("Enter The Elements To Be Enter\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    p=sum(arr,n);
    printf("%d",p);
    return 0;
}

int sum(int arr[],int m)
{
    int i,cal=0;
    for(i=0;i<m;i++)
        cal+=arr[i];
    return cal;
}
