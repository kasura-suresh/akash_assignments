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

Test ::operator --()
       {
          count = count+3;
       }
int main()
{
    Test t;
    // this calls "function void operator ++()" function
    --t;
    t.Display();
    return 0;
}
