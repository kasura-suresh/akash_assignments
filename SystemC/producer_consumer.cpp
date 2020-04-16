//Author :- Akash Kumar Gupta 
//Date :- 08-APR-2020
//To Implement Producer Consumer Probelem

#include<systemc.h>
using namespace std;

sc_fifo<int> packet_fifo;

SC_MODULE(Producer)
{ 
  int *store;
  int j,value;

  void behavior_write()
 {
   for(int i=0;i<10;i++)
   {
     value = rand() % 100;
     packet_fifo.write(value);
     store[j] = value;
     cout << "[" << sc_time_stamp() << "] writing to FIFO WRITE value: " << value<< endl;
     j++;
    wait(1, SC_NS);
   }
}
  
  SC_CTOR(Producer)
  {
    SC_THREAD(behavior_write); 
    store = new int[10];
    j=0;
    value = 0;
  }
  
};

SC_MODULE(Consumer)
{ 
  int *store;
  int j,value;

  void behavior_read()
 {
   for(int i=0;i<10;i++)
   {
      packet_fifo.read(value);
     store[j] = value;
     cout << "[" << sc_time_stamp() << "] writing to FIFO READ value: " << value  <<endl;
     j++;
    wait(1, SC_NS);
   }
}
  
  SC_CTOR(Consumer)
  {
    SC_THREAD(behavior_read);
    store = new int[10];
    j=0;
  }
  
};

SC_MODULE(Compare)
{
  Producer *Pro;
  Consumer *Con;
  void comparision()
  {
    int c = 0;
    for(int i=0;i<10;i++)
    {
      if(Pro->store[i]!=Con->store[i])
      {
        cout<<"FAILED"<<endl;
        c=1;
        break;
      }
    }
    if(!c)
      cout<<"PASSED!!!"<<endl;
    
  }
  
  SC_CTOR(Compare)
  {
    SC_METHOD(comparision);
  }
  
};

int sc_main(int argc, char* argv[])
{
  Producer P("Producer");
  Consumer C("Consumer");
  Compare Com("Compare");
  sc_start();
  return 0;
}
