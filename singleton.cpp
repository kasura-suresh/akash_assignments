#include <iostream>
using namespace std;
class Singleton
{
    static Singleton* instance ;
    Singleton()
    {

    };
    public:
        static Singleton* getInstance()
        {
            if(instance == 0)
                {
                    instance = new Singleton();
                }
          return instance;
        }
};

Singleton* Singleton::instance = 0;

int main()
{
    //new Singleton(); // Won't work
    Singleton* s = Singleton::getInstance();
    Singleton* r = Singleton::getInstance();
    // will print the address
    cout << s <<endl;
    cout << r <<endl;
}
