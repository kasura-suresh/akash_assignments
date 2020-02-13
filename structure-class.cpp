#include<iostream>
using namespace std;

struct Assign
{
public:
    int a=10;
    float b=20;
private:
    double c=30;
    long int d=40;
};

class A
{
public:
    int x=10;
private:
    double y=20;
};

int main()
{
    A obj;
    cout<<obj.x<<endl;
    //cout<<obj.y<<endl; will throw an error
    Assign A1;
    cout<< A1.a<<endl;
    cout<< A1.b<<endl;
    //cout<<A1.c<<endl; will throw an error
    //cout<<A.d<<endl; will throw an error
    return 0;
}
