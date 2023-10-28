#include <SPI.h>
#include <Wire.h>

void setup() {

  Serial.begin(9600);

  Serial.println("433Hz BOX by jay");
  Serial.println("select the frequency");
  Serial.println("1.6700 \n2.10000 \n3.1000 \n4.random \n5.reset");

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
  else if(select == '2')
  {
  Serial.println("10000");
  fre2();
  }
  else if(select == '3')
  {
  Serial.println("1000");
  fre3();
  }
  else if(select == '4')
  {
  Serial.println("random");
  fre4();
  }
  else if(select == '5')
  {
  Serial.println("reset");
  fre5();
  }
 }
}

void fre1(){ 
   for (int i = 1; i <= 100; i=i+9.9) {
      for (int j = 1; j <= i; j=j+1) {
    Serial.print("#");
    }
    Serial.println("");
    Serial.print(i);
    Serial.println("%");
    Serial.println("frequency 6700");
    Serial.println("progress cycle");
     
    delay(50);
  }   
    tone(8, 6700);  
  
  Serial.println("1.6700 \n2.10000 \n3.1000 \n4.random \n5.reset");
  start();
}

void fre2(){ 
   for (int i = 1; i <= 100; i=i+9.9) {
      for (int j = 1; j <= i; j=j+1) {
    Serial.print("#");
    }
   Serial.println("");
    Serial.print(i);
    Serial.println("%");
    Serial.println("frequency 10000");
    Serial.println("progress cycle"); 
    delay(50);
  }
    tone(8, 10000);     
  Serial.println("1.6700 \n2.10000 \n3.1000 \n4.random \n5.reset");
  start();
}

void fre3(){ 
for (int i = 1; i <= 100; i=i+9.9) {
    for (int j = 1; j <= i; j=j+1) {
    Serial.print("#");
    }
    Serial.println("");
    Serial.print(i);
    Serial.println("%");
    Serial.println("frequency 1000");
    Serial.println("progress cycle"):  
    delay(50);
  }
    tone(8, 1000);        

  Serial.println("1.6700 \n2.10000 \n3.1000 \n4.random \n5.reset");
  start();
}


void fre4(){ 
  for (int i = 1; i <= 100; i=i+9.9) {
      for (int j = 1; j <= i; j=j+1) {
    Serial.print("#");
    }
    Serial.println("");
    Serial.print(i);
    Serial.println("%");
    Serial.println("frequency random");
    Serial.println("progress cycle");
    delay(50);
 
  }
    int rn = random(0, 10000);
    int rnc = random(0, 9999);
    tone(8, rn, rnc);
        
  Serial.println("1.6700 \n2.10000 \n3.1000 \n4.random \n5.reset");
  start();
} 

void fre5(){ 
  delay(2000);
  resetFunc();  //call reset  
} 
