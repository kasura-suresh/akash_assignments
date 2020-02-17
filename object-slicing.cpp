#include <iostream>
using namespace std;

class Base
{
protected:
	int i;
public:
	Base(int a)
	{
	    i = a;
    }
	virtual void display()
	{
	    cout << "Base class " << i << endl;
    }
};

class Derived : public Base
{
	int j;
public:
	Derived(int a, int b):Base(a)
	 {
	     j = b;
     }
	virtual void display()
	{
	    cout << "Derived class "<< i << j << endl;
    }
};

void somefunc(Base obj)
{
	obj.display();
}

int main()
{
	Base b(33);
	Derived d(45, 54);
	somefunc(b);
	somefunc(d); // Object Slicing, the member j of d is sliced off
	return 0;
}
