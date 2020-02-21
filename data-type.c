#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i; // -32768 to 32767
    float f;
    char ch; // -128 to 127
    double d;
    unsigned int itr;

    printf("ENTER THE VALUE OF INT\n");
    scanf("%u",&i);
    printf("%u\n",i);

    printf("ENTER THE VALUE OF FLOAT\n");
    scanf("%f",&f);
    printf("%f\n",f);

    printf("ENTER A CHARACTER\n");
    scanf(" %c",&ch);
    printf("%c\n",ch);
    fflush(stdin);
    ch = getchar();
    putchar(ch);
    printf("\n");

    printf("ENTER THE VALUE OF DOUBLE \n");
    scanf("%lf",&d);
    printf("%lf\n", d);

    printf("ENTER THE VALUE OF UNSIGNED INT \n");
    scanf("%u",&itr);
    printf("%u\n", itr);

    return 0;
}
