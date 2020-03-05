/*********************************************************
*
*To Implement explicit constructor
*Author: Akash Kumar Gupta
*Date: 14/2/2020
*
*********************************************************/

#include<iostream>
using namespace std;
class Foo{
   public:
      explicit Foo(int n)
      {
          cout<<n<<endl;
      }
      explicit Foo(const char *p)
      {
          cout<<p<<endl;
      }

};

int main()
{
    //Foo myobj = 100; Gives an error
    Foo my1obj('x');
}
