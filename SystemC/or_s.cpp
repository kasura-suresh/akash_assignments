#include<systemc.h>
using namespace std;

SC_MODULE(my_or)
{
	sc_in<bool> a,b;
	sc_out<bool> y;
	
	void behavior()
	{
		y = a | b;
	}

	SC_CTOR(my_or)
	{
		SC_METHOD(behavior);
		sensitive << a << b;
	}

};

SC_MODULE(my_tb)
{
	sc_out<bool> a,b;
	sc_in<bool> y;

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

	 SC_CTOR(my_tb)
	 {
		 SC_THREAD(behavior);
	 }
};

int sc_main(int argc, char* argv[])
{
	my_tb tb1("tb1");
	my_or or1("or1");
	    
        sc_signal<bool> a, b, y;

  tb1.a(a);   
  tb1.b(b);
  tb1.y(y);

        or1.a(a);  
	or1.b(b);
	or1.y(y);
	      
	      
	       sc_start();     
       return 0;
 }
