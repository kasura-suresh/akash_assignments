/*********************************************************
*
*To Implement stack using Linked List
*Author: Akash Kumar Gupta
*Date: 21/2/2020
*
*********************************************************/

#include <iostream>
using namespace std;
struct Node {
   int data;
   struct Node *next;
};
class Stack
{
    struct Node* top = NULL;
    public:
void push(int val) {
   struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
   newnode->data = val;
   newnode->next = top;
   top = newnode;
}
public:
void pop() {
   if(top==NULL)
      cout<<"Stack Underflow"<<endl;
   else {
      cout<<"The popped element is "<< top->data <<endl;
      top = top->next;
   }
}
public:
void display() {
   struct Node* ptr;
   if(top==NULL)
      cout<<"stack is empty";
   else {
      ptr = top;
      cout<<"Stack elements are: ";
      while (ptr != NULL) {
         cout<< ptr->data <<" ";
         ptr = ptr->next;
      }
   }
   cout<<endl;
}
};
int main() {
   int ch, val;
   Stack obj;
   cout<<"1) Push in stack"<<endl;
   cout<<"2) Pop from stack"<<endl;
   cout<<"3) Display stack"<<endl;
   cout<<"4) Exit"<<endl;
   do {
      cout<<"Enter choice: "<<endl;
      cin>>ch;
      switch(ch) {
         case 1: {
            cout<<"Enter value to be pushed:"<<endl;
            cin>>val;
            obj.push(val);
            break;
         }
         case 2: {
            obj.pop();
            break;
         }
         case 3: {
            obj.display();
            break;
         }
         case 4: {
            cout<<"Exit"<<endl;
            break;
         }
         default: {
            cout<<"Invalid Choice"<<endl;
         }
      }
   }while(ch!=4);
      return 0;
}
