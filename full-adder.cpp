/*********************************************************
*
*To Implement Full Adder using 2 half adder
*Author: Akash Kumar Gupta
*Date: 21/2/2020
*
*********************************************************/

#include<iostream>
using namespace std;

struct HalfAdder1
{
    unsigned int sum : 1;
    unsigned int carry : 1;
    unsigned int A;
    unsigned int B;
    unsigned int C;
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
    struct HalfAdder1 Half1;
    struct HalfAdder1 Half2;
    cout<<"ENTER THE VALUE"<<endl;
    cin>>Half1.A;
    cout<<"ENTER THE VALUE"<<endl;
    cin>>Half1.B;
    cout<<"ENTER THE VALUE"<<endl;
    cin>>Half1.C;

    Half1.carry=HalfAdderCarry(Half1.A,Half1.B);
    Half1.sum=HalfAdderSum(Half1.A,Half1.B);

    Half2.sum=HalfAdderSum(Half1.sum,Half1.C);
    Half2.carry=HalfAdderCarry(Half1.sum,Half1.C);

    cout<<"SUM: = "<<Half2.sum<<endl;
    cout<<"CARRY: = "<<(Half1.carry|Half2.carry)<<endl;
}

