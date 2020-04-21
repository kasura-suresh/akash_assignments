//AUTHOR :- AKASH KUMAR GUPTA
//DATE :- 13-APR-2020
//IMPLEMENT SERIAL PERIPHERAL INTERFACE 
#include <systemc.h>
using namespace std;

struct memory{
  int m_arr[16] = {1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1};
};

SC_MODULE(MASTER), public memory
{
  sc_fifo<int> MOSI;
  sc_fifo<int> MISO;
  sc_out<bool> ss;
  sc_out<bool> sclk;
  int store_write[16], store_read[16];
  int j, value_write, value_read;

  void behavior_write()
  {
    while(true)
    {
       if(ss==0)
       {
         value_write = rand() % 2;
         MOSI.write(value_write);
         store_write[j] = value_write;
         m_arr[j]= value_write;
         cout << "[" << sc_time_stamp() << "] writing to SLAVE value: " << value_write<<endl;
         j++;
         wait();
       }
    }
  }
  void behavior_read()
  {
    while(true)
    {
       if(ss==0)
       {
         value_read = m_arr[j];
         store_write[j] = value_read;
         cout << "[" << sc_time_stamp() << "] reading from SLAVE value: " << value_read<<endl;
         j++;
         wait();
       }
    }
  }
  SC_CTOR(MASTER)
  {
    SC_THREAD(behavior_write); 
    sensitive << MOSI<< ss;
    SC_THREAD(behavior_read); 
    sensitive << MISO<< ss;
    
  }
};

SC_MODULE(SLAVE), public memory
{
  sc_fifo<int>MOSI;
  sc_fifo<int>MISO;
  sc_in<bool>ss;
  sc_in<bool>sclk;
   int store_write[16], store_read[16];
  int j, value_write, value_read;
    
  void behavior_write()
  {
    while(true)
    {
       if(ss==0)
       {
         value_write = m_arr[j];
         store_write[j] = value_write;
         cout << "[" << sc_time_stamp() << "] writing to MASTER value: " << value_write<<endl;
         j++;
         wait();
       }
    }
  }
  void behavior_read()
  {
    while(true)
    {
       if(ss==0)
       {
         value_read = m_arr[j];
         store_write[j] = value_read;
         cout << "[" << sc_time_stamp() << "] reading to MASTER value: " << value_read<<endl;
         j++;
         wait();
       }
    }
  }
  
  SC_CTOR(SLAVE)
  {
    SC_THREAD(behavior_write);
    sensitive << MISO<< ss;
    SC_THREAD(behavior_read)
      sensitive << MOSI << ss;
    
  }
  
};

int sc_main(int argc, char* argv[])
{
  MASTER mas("mas");
  SLAVE slav("slav");
 
  sc_signal<bool> ss, sclk;
  slav.ss(ss);
  mas.ss(ss);
  
  
  mas.sclk(sclk);
  slav.sclk(sclk);
  sc_start();
  return 0;
}