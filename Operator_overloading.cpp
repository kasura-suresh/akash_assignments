/*********************************************************
*
*To Implement Operator Overloading
*Author: Akash Kumar Gupta
*Date: 26/2/2020
*
*********************************************************/

#include <iostream>
using namespace std;
class Test
{
   private:
      int count;
   public:
       Test(): count(5){}

      int operator--();
       void Display()
       {
            cout<<"Count: "<<count;
       }
};

int Test ::operator --()
       {
          count = count+3;
       }
int main()
{
    Test t;
    // this calls "function void operator --()" function
    --t;
    t.Display();
    return 0;
}
