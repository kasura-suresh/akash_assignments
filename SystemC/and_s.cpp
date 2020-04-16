#include<systemc.h>
using namespace std;

SC_MODULE(my_and)
{
	sc_in<bool> a,b;
	sc_out<bool> y;
	
	void behavior()
	{
		y = a & b;
	}

	SC_CTOR(my_and)
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
	my_and and1("and1");
	    
        sc_signal<bool> a, b, y;

  tb1.a(a);   
  tb1.b(b);
  tb1.y(y);

        and1.a(a);  
	and1.b(b);
	and1.y(y);
	      
	      
	       sc_start();     
       return 0;
 }
