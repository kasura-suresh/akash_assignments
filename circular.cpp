#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};
struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *delete_end(struct node *);

int main()
{
	int c;
	
	while(1)
	{
		cout<<"1. Insert data\n";
		cout<<"\n2.Display the list\n";
		cout<<"\n3.Delete from end\n";
		cout<<"\n4.Exit\n";
		cout<<"\nEnter your choice:\n";
		cin>>c;
		
		switch(c){
			case 1: start = create_ll(start);
					cout<<"data inserted\n";
					break;
			case 2: display(start);
				   	break;
			case 3: delete_end(start);
					break;					
			case 4: 
					cout<<"Happy to see you again..bye \n";
					exit(0);
			
			default: cout<<"\nenter a correct choice\n";
		}
	}
	return 0;
}
struct node *create_ll(struct node *start)
{
	struct node *new_node, *ptr;
	int num;
	cout<<"Enter the data:\n";
	cin>>num;
	new_node = (struct node*)malloc(sizeof(struct node));
 	new_node -> data=num;
 	if(start == NULL)
 	{
 		new_node -> next = new_node;
 		start = new_node;
 	}
 	else
 	{ 
	 	ptr = start;
 		while(ptr -> next != start)
 			ptr = ptr -> next;
 		ptr -> next = new_node;
 		new_node -> next = start;
 	}
 	return start;
}

struct node *display(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr -> next != start)
	{
 		cout<<ptr->data<<"\t";
 		ptr = ptr -> next;
	}
		cout<<ptr->data<<"\t";
		cout<<"\n";
		return start;
}

struct node *delete_end(struct node *start)
{
	struct node *ptr, *preptr;
	ptr = start;
	while(ptr -> next != start)
	{
 		preptr = ptr;
 		ptr = ptr -> next;
	}
	preptr -> next = ptr -> next;
	free(ptr);
	return start;
}

