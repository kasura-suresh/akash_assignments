#include <iostream>
using namespace std;
class House{
  public:
    House()
    {
      cout<<"Small Room." <<endl;
    }
};
class Flat{
  public:
    Flat()
    {
      cout<<"Big Room." <<endl;
    }
};
class Rent:public House,public Flat
{
   public:
    Rent()
    {
        cout<<"No Room." <<endl;
    }
};
int main()
{
    Rent R1;
    return 0;
}
