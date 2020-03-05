/*********************************************************
*
*To Calculate the size of the array and array passing
*Author: Akash Kumar Gupta
*Date: 14/2/2020
*
*********************************************************/

#include <iostream>
using namespace std;
struct Node {
   int data;
   struct Node *next;
};
struct Node* head = NULL;

class L
{
    public:
  void insert(int new_data) {
   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
   new_node->data = new_data;
   new_node->next = head;
   head = new_node;
}
public:
void display() {
   struct Node* ptr;
   ptr = head;
   while (ptr != NULL) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
   }
}
};

int main() {
    L obj;
   obj.insert(3);
   obj.insert(1);
   obj.insert(7);
   obj.insert(2);
   obj.insert(9);
   cout<<"The linked list is: ";
   obj.display();
   return 0;
}
