/*Author - Akash Kumar Gupta
Date - 20/02/2020
Name of The Program - Reverse a Linked List */

#include<stdio.h> // Header File
#include<stdlib.h> // Header File
struct linked
{
    int data;
    struct linked *next;
};
struct linked *start= NULL;

//Creation Function
struct linked *create(struct linked *start)
{
   struct linked *pptr, *ptr;
   int num;
   printf("\n Enter -1 to end");
   printf("\n Enter the data : ");
   scanf("%d", &num);
   while(num!=-1)
   {
       pptr = (struct linked *)malloc(sizeof(struct linked));
       pptr ->data=num;
       if(start==NULL)
       {
            pptr -> next = NULL;
            start = pptr;
        }
        else
        {
            ptr=start;
            while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next = pptr;
        pptr->next=NULL;
        }
        printf("\n Enter the data : ");
        scanf("%d", &num);
    }
        return start;
}
//Delete Function
struct linked *del(struct linked *start)
{
    struct linked *ptr, *prev_ptr;
    ptr=start;
    while(ptr->next!=NULL)
    {
        prev_ptr=ptr;
        ptr=ptr->next;
    }
    prev_ptr->next= NULL;
    free(ptr);
    return start;
}
// Display Function
struct linked *display(struct linked *start)
{
    struct linked *ptr = start;
    while( ptr != NULL)
    {
        printf("%d\t\n",ptr->data);
        ptr = ptr -> next;
    }
    return start;
    free(ptr);
}

struct linked* rev(struct linked* start)
{
struct linked* current = start;
struct linked* next = NULL;
struct linked* prev = NULL;
    while( current !=NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
        start= prev;

    return start;
}

// Main Function
int main()
{
    int num,ch;
    do
    {
       printf("Enter 1 To create a Linked List\n");
       printf("Enter 2 To Display a Linked List\n");
       printf("Enter 3 To Delete a Last Node from the Linked List\n");
       printf("Enter 4 To reverse\n");
       printf("press 5 to exit\n");
       printf("Enter Your Choice\n");
       scanf("%d",&num);

    switch(num)
    {
      case 1: start = create(start);
              printf("Linked List Created Successfully\n");
              break;

      case 2: start = display(start);
              break;

      case 3: start = del(start);
              break;
      case 4: start = rev(start);
              break;
    }
    }while(num!=5);
    return 0;
}
