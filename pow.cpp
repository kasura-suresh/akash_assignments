/*********************************************************
*
*To Check whether a given number is a power of 2 or not
*Author: Akash Kumar Gupta
*Date: 19/2/2020
*
*********************************************************/

#include<stdio.h>

int power(int num)
{
    if(num &(num-1)==0)
        return 0;
    else
        return 1;
}

int main()
{
    int num,repo;
    scanf("%d",&num);
    repo=power(num);
    printf("%d",repo);
}
