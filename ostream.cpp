/*********************************************************
*
*To Implement Ostream
*Author: Akash Kumar Gupta
*Date: 13/2/2020
*
*********************************************************/

#include <iostream>
using namespace std;

class A
{
    int num;
    friend void operator>>(A& a, istream& myin)
    {
        myin>>a.num;
    }
    friend void operator<<(A& a, ostream& myout)
    {
        myout<<a.num;
    }

};

int main()
{
    A a;
    a>>cin;
    a<<cout;
    return 0;
}

