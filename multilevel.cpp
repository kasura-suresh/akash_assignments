/*********************************************************
*
*To Implement Multilevel program in c++
*Author: Akash Kumar Gupta
*Date: 13/2/2020
*
*********************************************************/

#include <iostream>
using namespace std;
class House{
  public:
    void Room1()
    {
      cout<<"Small Room." <<endl;
    }
};
class Flat:public House
{
  public:
    void Room2()
    {
      cout<<"Big Room." <<endl;
    }
};
class Rent:public Flat
{
   public:
    void Room3()
    {
        cout<<"No Room." <<endl;
    }
};
int main()
{
    Rent R1;
    R1.Room1();
    R1.Room2();
    R1.Room3();
    return 0;
}
