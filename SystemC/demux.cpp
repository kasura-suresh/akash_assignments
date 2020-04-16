#include<systemc.h>
using namespace std;

SC_MODULE(demux)
{  
  sc_in<bool> I,S0, S1;
  sc_out<bool> Y0, Y1, Y2, Y3;
 
  void behavior()
  {
    if(S0 == 0 && S1 == 0) {
      Y0 = (!S0 & !S1 & I); 
      Y1=0;Y2=0;Y3=0;
    } else if(S0 == 0 && S1 == 1) {
      Y1 = (!S0 & S1 & I); 
      Y0=0;Y2=0;Y3=0;
    } else if(S0 == 1 && S1 == 0) {
      Y2 = (S0 & !S1 & I); 
      Y0=0;Y1=0;Y3=0;
    } else if(S0 == 1 && S1 == 1) {
       Y3 = ((S0 & S1) & I);
       Y0=0;Y1=0;Y2=0;
    }
  }
   
  SC_CTOR(demux)
  {
    SC_METHOD(behavior);
    sensitive << S0<< S1 << I;
    
  }
};

SC_MODULE(my_tb)
{
	sc_out<bool> S0, S1, I;
        sc_in<bool> Y0, Y1, Y2, Y3;

	void behavior()
	{       
                I = 1; 
                S0=0; S1=0;
	        wait(3, SC_NS);
                cout << "I = " << I << ", Y0 = " << Y0 << "Y1 = " << Y1 << ", Y2 = " << Y2  << "Y3 = " << Y3 << ", S0 = " << S0  <<", S1 = " << S1 << endl;

                
		S0=0; S1=1;
		wait(3, SC_NS);
		cout << "I = " << I << ", Y0 = " << Y0 << "Y1 = " << Y1 << ", Y2 = " << Y2  << "Y3 = " << Y3 << ", S0 = " << S0  <<", S1 = " << S1 << endl;

                
	        S0=1; S1=0;
	        wait(3, SC_NS);
	        cout << "I = " << I << ", Y0 = " << Y0 << "Y1 = " << Y1 << ", Y2 = " << Y2  << "Y3 = " << Y3 << ", S0 = " << S0  <<", S1 = " << S1 << endl;
        
		S0=1; S1=1; 
		wait(3, SC_NS);
	        cout << "I = " << I << ", Y0 = " << Y0 << "Y1 = " << Y1 << ", Y2 = " << Y2  << "Y3 = " << Y3 << ", S0 = " << S0  <<", S1 = " << S1 << endl;
	}

	 SC_CTOR(my_tb)
	 {
		 SC_THREAD(behavior);
	 }
};

int sc_main(int argc, char* argv[])
{
	my_tb tb1("tb1");
	demux demux("demux");
	    
        sc_signal<bool> S0, S1, Y0, Y1, Y2, Y3, I;

  tb1.I(I); 
  tb1.Y0(Y0);  
  tb1.Y1(Y1);
  tb1.Y2(Y2);
  tb1.Y3(Y3);
  tb1.S0(S0);
  tb1.S1(S1);
  

  demux.I(I); 
  demux.Y0(Y0);	  
  demux.Y1(Y1);
  demux.Y2(Y2);
  demux.Y3(Y3);
  demux.S0(S0);
  demux.S1(S1);
        
	      
  sc_start();     
       return 0;
 }
