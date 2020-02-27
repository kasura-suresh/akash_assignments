#include<stdio.h>

int v1[5]={1,2,3,4,5};
int v2[5]={5,4,3,2,1};

void print_vector(int * v, int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d",v[i]);
    }
    printf("\n");
}

void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
    printf("After swapping in swap: a = %d, b = %d\n", a, b);
}

void swap_ptr(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
    printf("After swapping in swap: a = %d, b = %d\n", *a, *b);
}

void add_vector(int *v1, int *v2, int** v3,int size)
{
    *v3=(int *)calloc(5,sizeof(int));
    printf("In add_vector: Allocate memory at: %d\n",*v3);
    int i;
    for(i=0;i<size;i++)
    {
        (*v3)[i]=v1[i]+v2[i];
    }
}


input: a byte of data
output : nibbles of byte are swapped
  - 2 ways:
    - bit wise operators
    - union + (struct with bit fields in it..)     struct a { char c; int i; };   struct a { char c:2; char c:3; .. }

int main()
{
    int a = 5, b = 10;
    swap(a, b);
    printf("After swapping in main: a = %d, b = %d\n", a, b);
    swap_ptr(&a, &b);
    printf("After swapping in main: a = %d, b = %d\n", a, b);

    int *v3=0;   // int a = 0;  char c = 'a';
    int** x = &v3;    // int* y = &a;  char* cptr = &c;
    print_vector(v1,5);
    print_vector(v2,5);
    add_vector(v1,v2,&v3,5);
    printf("v3 = %d\n",v3);
    print_vector(v3,5);
    return 0;
}
