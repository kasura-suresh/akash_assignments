/****************************************
*
*Shallow Copy
*Author: Akash Kumar Gupta
*Date: 16/3/2020
*
****************************************/

#include<iostream>
using namespace std;

class shallowCopy
{
private:
    int x,y;
public:
    shallowCopy()
    {
        x = 0;
        y = 0;
    }
    void setData(int x, int y)
    {
        this->x=x;
        this->y=y;
    }
    void showData()
    {
        cout<<"VALUE OF X"<<this->x<<endl;
        cout<<"VALUE OF Y"<<this->y<<endl;
    }
    shallowCopy(shallowCopy &s)
    {
        x=s.x;
        y=s.y;
    }
};

int main()
{
    shallowCopy s;
    s.setData(5,10);
    shallowCopy s2 = s;

    s2.showData();
}
