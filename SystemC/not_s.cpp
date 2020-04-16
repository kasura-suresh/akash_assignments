#include<systemc.h>
using namespace std;

SC_MODULE(my_not)
{
	sc_in<bool> a;
	sc_out<bool> y;
	
	void behavior()
	{
		y = !a;
	}

	SC_CTOR(my_not)
	{
		SC_METHOD(behavior);
		sensitive << a ;
	}

};

SC_MODULE(my_tb)
{
	sc_out<bool> a;
	sc_in<bool> y;

	void behavior()
	{
		a=1;
	        wait(3, SC_NS);
                cout << "a = " << a <<", y = " << y << endl;

		a=0;
		wait(3, SC_NS);
		cout << "a = " << a  <<", y = " << y << endl;

	}

	 SC_CTOR(my_tb)
	 {
		 SC_THREAD(behavior);
	 }
};

int sc_main(int argc, char* argv[])
{
	my_tb tb1("tb1");
	my_not not1("not1");
	    
        sc_signal<bool> a, b, y;

  tb1.a(a);   
  tb1.y(y);

        not1.a(a);
	not1.y(y);
	      
	      
	       sc_start();     
       return 0;
 }
