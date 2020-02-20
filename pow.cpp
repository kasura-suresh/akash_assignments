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
