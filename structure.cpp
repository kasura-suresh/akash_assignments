/*Author - Akash Kumar Gupta
Date - 19/02/2020
Name of The Program - Structure Storage*/

#include<iostream>
using namespace std;
struct def1
{
    short i;
    short j;
    char k;
};

struct def2
{
    short a;
    char ch;
    short b;
};

int main()
{
    cout<<sizeof(def1)<<"\n";
    cout<<sizeof(def2);
}
