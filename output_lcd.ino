#include <LiquidCrystal.h> // includes the LiquidCrystal Library 
LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7) 
void setup() { 
 lcd.begin(16,2);
 pinMode(10,INPUT);
 pinMode(11,INPUT);
 pinMode(12,INPUT);
 pinMode(13,INPUT);
 // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display } 
}
void loop() {
 boolean output[]={0,0,0,0};
 output[0]=digitalRead(10);
 output[1]=digitalRead(11);
 output[2]=digitalRead(12);
 output[3]=digitalRead(13);
 float n=convertBinToDec(output);
 int m=(int)n;
 if (m<n){
   m+=1;
 }
 
 lcd.print(m); // Prints "Arduino" on the LCD 
 delay(1000); // 3 seconds delay  
 lcd.clear(); // Clears the LCD screen 
}
float convertBinToDec(boolean Bint[]) {
  float ReturnInt = 0;
  for(int i = 0;i<4;i++) {
    ReturnInt+=(pow(2,3-i)*(int(Bint[i])));
    //Serial.println(pow(2,4-i)*int(Bint[i]));
  }
  return ReturnInt;
}
