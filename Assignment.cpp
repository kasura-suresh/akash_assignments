#include<iostream>
using namespace std;

class A
{
public:
    int i;
    int d;
};

class B: public A
{
public:
    int c;

    char ch;
};

int main()
{
    B Myobj;
    cout<<" class B"  <<sizeof(B) << endl;
    cout<< " class A"<<sizeof(A) << endl;
    cout << " double " << sizeof(double) << endl;
    cout << " int " << sizeof(int) << endl;

}
