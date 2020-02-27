#include<iostream>
using namespace std;

union bit{
    unsigned char lb;
    unsigned char ub;
};

int main()
{
    union bit b;
    b.lb=0xab;
    cout<<hex<<int(b.lb);
	return 0;
}
