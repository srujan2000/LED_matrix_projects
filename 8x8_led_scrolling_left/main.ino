#include "port.h"
 
void setup() {
  init_port();
 
 char display[56] = {0x44,0x44,0x44,0x54,0x54,0x54,0x6C,0x44,//W
                        0x00,0x00,0x78,0x84,0xF8,0x80,0x78,0x00,//e
                        0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,//l
                        0x00,0x00,0x78,0x80,0x80,0x80,0x78,0x00,//c
                        0x00,0x00,0x38,0x44,0x44,0x44,0x38,0x00,//o
                        0x00,0x00,0x00,0x14,0x2A,0x2A,0x2A,0x2A,//m
                        0x00,0x00,0x78,0x84,0xF8,0x80,0x78,0x00 //e
                        };
char d;

int s=0,val=0,j=0;
Serial.begin(9600);
while(1){
    for(int shift=0;shift<9;shift++){
      for(int k=0;k<30;k++){
        for(j=s;j<s+8;j++){
          // for(char j=0;j<48;j++){
          // outcol(display[j]<<shift);
          // outcol((display[j] | (display[j+8]>>(8-shift)& power(shift)))<<shift);
          // Serial.println(val,DEC);
          if(j<48){
          outcol((display[j]<<shift | ((display[j+8]>>(8-shift))&val)));
          }
          if(j<8){
            outrow(~(1<<j));
          }else{
            outrow(~(1<<(j%8)));
          }
          delay1();
        }
      }
      outcol(0x00);
      delay2();
      val=val+power(shift);
    }
    val=0;
    if(j>47){
      s=0;
      delay3();
    }else{
    s=j;
    }
  }
}

unsigned char power(char n){
  char p=1;
  if(n==0){
    return 1;
  }else{
    for(int i=1;i<n+1;i++){
         p= p*2;
    }
    return p;
  }
}

 void loop() {
}

