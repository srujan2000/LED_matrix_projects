void init_port(){
  char *col2 = (char*)0x30;
  *col2 = 0xFF;

  char *col1 = (char*)0x107;
  *col1 = 0xFF;

  char *row = (char*)0x10A;
  *row = 0xFF;
}

void outrow(char data){
  char *out = (char*)0x10B;
  *out = data;
}

void outcol1(char data){
  char *out = (char*)0x108;
  *out = data;
}

void outcol2(char data){
  char *out = (char*)0x31;
  *out = data;
}

void delay1( )
{
  volatile long i;
  for(i=0; i<1000; i++);
}

void delay2( )
{
  volatile long i;
  for(i=0; i<5000; i++);
}

void delay3( )
{
  volatile long i;
  for(i=0; i<10000; i++);
}
