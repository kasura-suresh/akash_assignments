/*********************************************************
*
*To Implement Half Adder
*Author: Akash Kumar Gupta
*Date: 21/2/2020
*
*********************************************************/

#include<iostream>
using namespace std;

struct HalfAdder
{
    unsigned int sum : 1;
    unsigned int carry : 1;
    unsigned int A;
    unsigned int B;
};

unsigned int HalfAdderSum(unsigned int A,unsigned int B)
{
    return A^B;
}

unsigned int HalfAdderCarry(unsigned int A,unsigned int B)
{
    return A&B;
}

int main()
{
    struct HalfAdder Half;
    cout<<"ENTER THE VALUE"<<endl;
    cin>>Half.A;
    cout<<"ENTER THE VALUE"<<endl;
    cin>>Half.B;
    Half.sum=HalfAdderSum(Half.A,Half.B);
    Half.carry=HalfAdderCarry(Half.A,Half.B);

    cout<<"SUM: = "<<Half.sum<<endl;
    cout<<"CARRY: = "<<Half.carry<<endl;
}
