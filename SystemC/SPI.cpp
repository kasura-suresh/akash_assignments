//Author :- Akash Kumar Gupta
//Date   :- 23-Apr-2020
//To Implement Serial Peripheral Interface

#include<systemc.h>

SC_MODULE(Master)
{
  sc_fifo_in<int> data_host_master;
  sc_out<bool> MOSI;
  sc_in<bool>  MISO;
  sc_in<bool> sclk;
  sc_out<bool> ss;
  int data_read=0,i=0,k=0;
  int data=0;
  
  void MOSI_()
  {
    while(true) 
    {
       data_read = data_host_master.read();
       cout<<"Master Send Data To Slave Is : "<< data_read<< endl;
       i = 0; 
       ss.write(0);
       while(true)
       {
          if(i == 8)
             break;
          else
          {
            MOSI = data_read & 1;
            wait();
            cout << sc_time_stamp() << " in master send " << MOSI << endl;
            data_read = data_read >> 1;
            ++i;
          } 
      }
      ss.write(1);
      wait();
    }
  }
  
  void MISO_()
  {
    while (true) 
    {
      k = 0;
      while(true)
      { 
         wait();
         if(k == 8)
           break;
         else {
      		cout << sc_time_stamp() << " in master receive " << MISO << endl;
      		data = data + (MISO*pow(2,k));
          	++k;
      	 }
       }
       cout << "Data received by master from slave is ::" << data<<endl;
      data = 0;
      wait();
  	}
  }
      
  SC_CTOR(Master) 
  {
    SC_THREAD(MOSI_);
      sensitive<<sclk.pos() << data_host_master.data_written();
    dont_initialize();
    SC_THREAD(MISO_);
      sensitive << sclk.pos();
    dont_initialize();
  }
};
    
SC_MODULE(Slave)
{
  sc_fifo_in<int> data_host_slave;
  sc_in<bool> MOSI;
  sc_out<bool>  MISO;
  sc_in<bool> sclk;
  sc_in<bool> ss;
  int data_read=0,i=0,j=0;
  int data=0;
 
  
  void MISO_()
  {
    while(true) 
    {
       
       data_read = data_host_slave.read();
       cout<<"Slave Send Data To Master Is : "<< data_read<< endl;
       i = 0; 
       if(ss==1)
         wait(ss);
       while(true)
       {
          if(i == 8)
             break;
          else
          {
            MISO = data_read & 1;
            wait(sclk.posedge_event());
            cout << sc_time_stamp() << " in slave send " << MISO << endl;
            data_read = data_read >> 1;
            ++i;
          }
      }
      wait();
    }
  }
  
  void MOSI_()
  {
    while (true) 
    {
    j = 0;
    while(true)
    { 
      wait();
      if(j == 8)
        break;
      else {
      cout << sc_time_stamp() << " in slave receive " << MOSI << endl;
      data = data + (MOSI*pow(2,j));
          ++j;
      }
    }
     
    cout << "Data received by slave from master is ::" << data<<endl;
      data = 0;
      wait();
    }
  }
      
  SC_CTOR(Slave) 
  {
    SC_THREAD(MISO_);
      sensitive <<sclk.pos() << data_host_slave.data_written();
    dont_initialize();
    SC_THREAD(MOSI_);
      sensitive <<sclk.pos();
    dont_initialize(); 
  }
};
    
SC_MODULE(Host)
{
  sc_fifo_out<int> data_host_transmitter;
  sc_fifo_out<int> data_host_receiver;
  int master_data[5] = {10,14,17,19,20};
  int slave_data[5] = {12,13,11,10,9};
  
  void inputs() 
  {
    for(int j=0;j<5;j++)
    {
       data_host_transmitter.write(master_data[j]);
       wait(SC_ZERO_TIME);
       data_host_receiver.write(slave_data[j]);
       wait(50,SC_NS);
    }
  }
  SC_CTOR(Host) {
    SC_THREAD(inputs);
  }
};

int sc_main(int argc,char* argv[])
{
  sc_fifo<int> data_sent_to_transmitter;
  sc_fifo<int> data_sent_to_receiver;
  
  sc_signal<bool> MOSI;
  sc_signal<bool> MISO;
  sc_signal<bool> ss;
  sc_clock sclk("sclk",5,SC_NS);
 
  MOSI.write(1);
  MISO.write(1);
   
  Master master("master");
  Host host("host");
  Slave slave("slave");
  
  master.data_host_master(data_sent_to_transmitter);
  master.MOSI(MOSI);
  master.MISO(MISO);
  master.ss(ss);
  master.sclk(sclk);
  
  host.data_host_transmitter(data_sent_to_transmitter);
  host.data_host_receiver(data_sent_to_receiver);
  
  slave.MOSI(MOSI);
  slave.data_host_slave(data_sent_to_receiver);
  slave.MISO(MISO);
  slave.sclk(sclk);
  slave.ss(ss);
  sc_trace_file *TF = sc_create_vcd_trace_file("traces");
  
	sc_trace(TF, sclk, "sclk");
	sc_trace(TF, MOSI, "MOSI");
	sc_trace(TF, MISO, "MISO");
	sc_trace(TF, ss, "ss");
  
  sc_start(250, SC_NS);
  sc_close_vcd_trace_file(TF);
  return 0;
}