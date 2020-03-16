/****************************************
*
*Deep Copy
*Author: Akash Kumar Gupta
*Date: 16/3/2020
*
****************************************/

#include<iostream>
using namespace std;

class deepCopy
{
private:
    int x,y,*p;
public:
    deepCopy()
    {
        x = 0;
        y = 0;
        p = new int;
    }
    void setData(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        *p = z;
    }
    void showData()
    {
        cout<<"VALUE OF X IS "<<this->x<<endl;
        cout<<"VALUE OF Y IS "<<this->y<<endl;
        cout<<"VALUE OF *P IS "<<*p<<endl;
    }
    deepCopy(deepCopy &s)
    {
        x = s.x;
        y = s.y;
        p = new int;
        *p = *(s.p);

    }
};

int main()
{
    deepCopy s;
    s.setData(5,10,15);
    deepCopy s2 = s;

    s2.showData();
}
