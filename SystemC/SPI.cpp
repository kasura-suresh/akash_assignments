//AUTHOR :- AKASH KUMAR GUPTA
//DATE :- 13-APR-2020
//IMPLEMENT SERIAL PERIPHERAL INTERFACE 
#include <systemc.h>
using namespace std;

struct memory{
  int*   m_arr;
  int    m_mem_size;
  
  memory(int size = 8)
  {
    m_arr = new int[size]; 
  }
};

SC_MODULE(MASTER), public memory
{
  sc_fifo<int> MOSI;
  sc_fifo<int> MISO;
  sc_out<bool> ss;
  sc_out<bool> sclk;
  int *store_write, *store_read;
  int j, value_write, value_read;

  void behavior_write()
  {
    while(true)
    {
       if(ss==0)
       {
         value_write = rand() % 5;
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
    store_write = new int[8];
    SC_THREAD(behavior_read); 
    sensitive << MISO<< ss;
    store_read = new int[8];
    
  }
};

SC_MODULE(SLAVE), public memory
{
  sc_fifo<int>MOSI;
  sc_fifo<int>MISO;
  sc_in<bool>ss;
  sc_in<bool>sclk;
   int *store_write, *store_read;
  int j, value_write, value_read;
    
  void behavior_write()
  {
    while(true)
    {
       if(ss==0)
       {
         value_write = rand() % 5;
         MISO.write(value_write);
         store_write[j] = value_write;
         m_arr[j]= value_write;
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
    store_write = new int[8];
    SC_THREAD(behavior_read)
      sensitive << MOSI << ss;
    store_read = new int[8];
    
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