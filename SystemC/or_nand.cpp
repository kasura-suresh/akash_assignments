#include<systemc.h>
using namespace std;

SC_MODULE(my_nand)
{ 
   sc_in<bool> a, b;
   sc_out<bool> y;

   void behavior()
   {
        y = !(a & b);
   }

   SC_CTOR(my_nand):a("a"), b("b"), y("y")
   { 
     SC_METHOD(behavior);
     sensitive << a << b;
    }
};

SC_MODULE(my_or_using_nand)
{ 
  sc_in<bool> a, b;
  sc_out<bool> y;
  sc_signal<bool> y1, y2;

  my_nand n1, n2, n3;

  SC_CTOR(my_or_using_nand):a("a"), b("b"), y("y"), n1("n1"), n2("n2"), n3("n3")
  {
    n1.a(a); n1.b(a); n1.y(y1);
    n2.a(b); n2.b(b); n2.y(y2);
    n3.a(y1);n3.b(y2);n3.y(y);
   }
};

SC_MODULE(my_tb)
{
	my_or_using_nand x;
	sc_signal<bool> a,b,y;

	void behavior()
	{
		a=1; b=1;
	        wait(3, SC_NS);
                cout << "a = " << a << ", b = " << b << ", y = " << y << endl;

		a=0; b=1;
		wait(3, SC_NS);
		cout << "a = " << a << ", b = " << b << ", y = " << y << endl;

	        a=1; b=0;
	        wait(3, SC_NS);
	        cout << "a = " << a << ", b = " << b << ", y = " << y << endl;

		a=0; b=0; 
		wait(3, SC_NS);
	        cout << "a = " << a << ", b = " << b << ", y = " << y << endl;
	}

	 SC_CTOR(my_tb):x("x")
	 {
                 x(a,b,y);
		 SC_THREAD(behavior);
	 }
};

int sc_main(int argc, char* argv[])
{
	my_tb tb1("tb1");
  
       sc_start();     
       return 0;
 }
