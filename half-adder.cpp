#include<iostream>
using namespace std;

struct HalfAdder
{
    unsigned int sum : 1;
    unsigned int carry : 1;
};

union Half{
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
    union Half H;
    cout<<"ENTER THE VALUE"<<endl;
    cin>>H.A;
    cout<<"ENTER THE VALUE"<<endl;
    cin>>H.B;
    cout<<"SIZEOF STRUCTURE"<<sizeof(Half)<<endl;
    cout<<"SIZEOF UNION"<<sizeof(H)<<endl;
    Half.sum=HalfAdderSum(H.A,H.B);
    Half.carry=HalfAdderCarry(H.A,H.B);

    cout<<"SUM: = "<<Half.sum<<endl;
    cout<<"CARRY: = "<<Half.carry<<endl;
}
