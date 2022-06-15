void init_port(void);
void outrow(char);
void outcol(char);
void delay1( void );

void init_port()
{
  char *row_port_dir  = (char *)0x10A;
  char *col_port_dir  = (char *)0x30;
  *row_port_dir = 0xFF;
  *col_port_dir = 0xFF;

}

void outrow( char out_data)
{
  volatile char *row_port_out = (char *)0x10B; 
  *row_port_out = out_data;
}

void outcol( char out_data)
{
  volatile char *col_port_out = (char *)0x31; 
  *col_port_out = out_data;
}

void delay1( void )
{
  volatile long i;
  for(i=0; i<5000; i++);
}

void delay2( void )
{
  volatile long i;
  for(i=0; i<300000; i++);
}
