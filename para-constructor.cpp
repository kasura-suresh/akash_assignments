/*********************************************************
*
*To Implement Parameterized Constructor
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

 public:
    void f()
    {
        cout<<a<<endl;
        cout<<b;
    }
};

int main()
{
    MyClass myobj(100,500);
    myobj.f();
}

