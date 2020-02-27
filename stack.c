#include<stdio.h>
#include<stdlib.h>

struct linked
{
    int data;
    struct linked * next;
};

struct linked *start = NULL;

struct linked *push(struct linked *start)
{
    struct linked *ptr;
    int d_data;
    ptr=(struct linked*)malloc(sizeof(struct linked));
    scanf("%d",&d_data);
    ptr->data=d_data;
    ptr->next=start;
    start = ptr;
    return start;
}
struct linked *pop(struct linked *start)
{
    if(start==NULL)
        printf("UNDERFLOW\n");
    else
    {
        start=start->next;
        printf("Popped Successfully\n");

    }
    return start;
}
struct linked *display(struct linked *start)
{
    struct linked *ptr = start;
    if(ptr== NULL)
    {
        printf("STACK IS EMPTY\n");
    }
    while (ptr!=NULL)
    {
        printf("\n%d\n",ptr->data);
        ptr=ptr->next;
    }
     return start;
}

int main()
{
    int ch,n;
    do
    {
        printf("PRESS 1 TO PUSH\n");
        printf("PRESS 2 TO POP\n");
        printf("PRESS 3 TO DISPLAY\n");
        printf("PRESS 4 TO EXITS\n");
        printf("ENTER YOUR CHOICE\n");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:start=push(start);
               printf("Pushed Successfully\n");
               break;
        case 2:start=pop(start);
               break;
        case 3:start=display(start);
        }
    }while(ch!=4);
    return 0;
}
