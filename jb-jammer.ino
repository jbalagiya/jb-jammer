#include <SPI.h>
#include <Wire.h>

void setup() {

  Serial.begin(9600);

  Serial.println("315Hz BOX by jay");
  Serial.println("select the frequency");
  Serial.println("1.6700 2.reset ");

}
void(* resetFunc) (void) = 0; //declare reset function

void loop(){
  start();
}

void start(){ 

  if (Serial.available() > 0) {
  int select = Serial.read();
  
   if(select == '1')
  {
  Serial.println("6700");
  fre1();
  }
  if(select == '2')
  {
  Serial.println("reset");
  fre2();
  }
  
 }
}

void fre1(){ 
   for (int i = 0; i <= 100; i++) {

    Serial.println("frequency 6700");
    Serial.println("progress cycle");
    Serial.print(i);
    Serial.println("%"); 
  }   
    tone(8, 6700);  
  
  Serial.println("1.6700 ");
  start();
}

void fre2(){
  Serial.println("resetting");
  resetFunc();  //call reset
}
 




