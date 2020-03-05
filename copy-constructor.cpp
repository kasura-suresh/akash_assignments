/*********************************************************
*
*To Implement Copy constructor
*Author: Akash Kumar Gupta
*Date: 13/2/2020
*
*********************************************************/

#include<iostream>
using namespace std;

class MyClass {
public:
    int i=10,a,b;
    MyClass(int x, int y)
    {
        a=x;
        b=y;
    }
    MyClass(const MyClass &p2)
    {
        a=p2.a;
        b=p2.b;
    }
     //int getX()            {  return a; }
     //int getY()            {  return b; }
 public:
    void f()
    {
        cout<<"Hello";
    }
};

int main()
{
    MyClass myobj(100,500);
    MyClass p2=myobj;
    cout<<(p2.a)<<"\n";
    cout<<(p2.b);
}
