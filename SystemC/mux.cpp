#include<systemc.h>
using namespace std;

SC_MODULE(mux)
{  
  sc_in<bool> I0, I1, I2, I3, S0, S1;
  sc_out<bool> y;
 
  void behavior()
  {
       y = (!S0 & !S1 & I0) | (!S0 & S1 & I1) | (S0 & !S1 & I2) | (S0 & S1 & I3);
  }
   
  SC_CTOR(mux)
  {
    SC_METHOD(behavior);
    sensitive << I0<< I1<< I2<< I3<< S0<< S1;
  }
};

SC_MODULE(my_tb)
{
	sc_out<bool> I0, I1, I2, I3, S0, S1;
        sc_in<bool> y;

	void behavior()
	{
		I0=0;
                S0=1; S1=1;
	        wait(3, SC_NS);
                cout << "I0 = " << I0 << ", I1 = " << I1 << "I2 = " << I2 << ", I3 = " << I3  << "S0 = " << S0 << ", S1 = " << S1  <<", y = " << y << endl;

                I1=1;
		S0=0; S1=1;
		wait(3, SC_NS);
		cout << "I0 = " << I0 << ", I1 = " << I1 << "I2 = " << I2 << ", I3 = " << I3  << "S0 = " << S0 << ", S1 = " << S1  <<", y = " << y << endl;

                I2=1;
	        S0=1; S1=0;
	        wait(3, SC_NS);
	        cout << "I0 = " << I0 << ", I1 = " << I1 << "I2 = " << I2 << ", I3 = " << I3  << "S0 = " << S0 << ", S1 = " << S1  <<", y = " << y << endl;
        
                I3=0;
		S0=0; S1=0; 
		wait(3, SC_NS);
	        cout << "I0 = " << I0 << ", I1 = " << I1 << "I2 = " << I2 << ", I3 = " << I3  << "S0 = " << S0 << ", S1 = " << S1   <<", y = " << y << endl;
	}

	 SC_CTOR(my_tb)
	 {
		 SC_THREAD(behavior);
	 }
};

int sc_main(int argc, char* argv[])
{
	my_tb tb1("tb1");
	mux mux("mux");
	    
        sc_signal<bool> I0, I1, I2, I3, S0, S1, y;

  tb1.I0(I0);   
  tb1.I1(I1);
  tb1.I2(I2);
  tb1.I3(I3);
  tb1.S0(S0);
  tb1.S1(S1);
  tb1.y(y);

  mux.I0(I0);   
  mux.I1(I1);
  mux.I2(I2);
  mux.I3(I3);
  mux.S0(S0);
  mux.S1(S1);
  mux.y(y);
	      
	      
  sc_start();     
       return 0;
 }
