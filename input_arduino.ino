String first = "";  
String operation = "";  
String second = "";
boolean Bin1[] = {0,0,0,0};
boolean Bin2[] = {0,0,0,0};
//boolean Bin3[] = {0,0,0,0};   
int f=0;
int s=0; 
int sel=0;
  
void setup() {  
    Serial.begin(9600);
    pinMode(12,OUTPUT);
    pinMode(13,OUTPUT);
    pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(6,OUTPUT);
    pinMode(7,OUTPUT);
    pinMode(8,OUTPUT);
    pinMode(9,OUTPUT);
    pinMode(10,OUTPUT);
    pinMode(11,OUTPUT);    
   
}  
  
  
void loop() {  
    
   Serial.println("Enter first number.");  
   
  while (Serial.available()==0)  
  {                                       //Wait for user input  
    
  }  
   first=Serial.readString();  //Reading the Input string from Serial port.
   f=first.toInt();
   
   convertDecToBin(f,Bin1);
      
Serial.println("Enter operation.");
Serial.println("1.Addition");
Serial.println("2.Subtraction");  
Serial.println("3.Multiplication");
Serial.println("4.division");
Serial.println("5.logical shift left");
Serial.println("6.Logical shift right");
Serial.println("7.rotate left");
Serial.println("8.rotate right");
Serial.println("9.and");
Serial.println("10.or");
Serial.println("11.xor");
Serial.println("12.nor");
Serial.println("13.nand");
Serial.println("14.xnor");
Serial.println("15.greater comparision");
Serial.println("16.equal comparision");
  while(Serial.available()==0)  
  {  
      
  }  
   operation=Serial.readString();
   sel=operation. toInt();
   boolean Bin3[] = {0,0,0,0};
   if (sel==1){
    Bin3[0]=0;
    Bin3[1]=0;
    Bin3[2]=0;
    Bin3[3]=0;
   }
   else if (sel==2){
   Bin3[0]=0;
    Bin3[1]=0;
    Bin3[2]=0;
    Bin3[3]=1;
    }
   else if (sel==3){
    Bin3[0]=0;
    Bin3[1]=0;
    Bin3[2]=1;
    Bin3[3]=0;
    }
    else if (sel==4){
    Bin3[0]=0;
    Bin3[1]=0;
    Bin3[2]=1;
    Bin3[3]=1;
    }
    else if (sel==5){
    Bin3[0]=0;
    Bin3[1]=1;
    Bin3[2]=0;
    Bin3[3]=0;
    }
    else if (sel==6){
    Bin3[0]=0;
    Bin3[1]=1;
    Bin3[2]=0;
    Bin3[3]=1;
    }
    else if (sel==7){
    Bin3[0]=0;
    Bin3[1]=1;
    Bin3[2]=1;
    Bin3[3]=0;
    }
    else if (sel==8){
    Bin3[0]=0;
    Bin3[1]=1;
    Bin3[2]=1;
    Bin3[3]=1;
    }
    else if (sel==9){
    Bin3[0]=1;
    Bin3[1]=0;
    Bin3[2]=0;
    Bin3[3]=0;
    }
   else if (sel==10){
    Bin3[0]=1;
    Bin3[1]=0;
    Bin3[2]=0;
    Bin3[3]=1;
    }
    else if (sel==11){
    Bin3[0]=1;
    Bin3[1]=0;
    Bin3[2]=1;
    Bin3[3]=0;
    }
    else if (sel==12){
    Bin3[0]=1;
    Bin3[1]=0;
    Bin3[2]=1;
    Bin3[3]=1;
    }
    else if (sel==13){
    Bin3[0]=1;
    Bin3[1]=1;
    Bin3[2]=0;
    Bin3[3]=0;
    }
    else if (sel==14){
    Bin3[0]=1;
    Bin3[1]=1;
    Bin3[2]=0;
    Bin3[3]=1;
    }
    else if (sel==15){
    Bin3[0]=1;
    Bin3[1]=1;
    Bin3[2]=1;
    Bin3[3]=0;
    }
    else if (sel==16){
    Bin3[0]=1;
    Bin3[1]=1;
    Bin3[2]=1;
    Bin3[3]=1;
    }
    
   Serial.println("Enter second number.");  
   while(Serial.available()==0)  
  {  
      
  }  
  second=Serial.readString();
  s=second.toInt();
  convertDecToBin(s,Bin2);
  boolean output[]={0,0,0,0}  ;
  digitalWrite(12,Bin1[0]);
  digitalWrite(13,Bin1[1]);
  digitalWrite(2,Bin1[2]);
  digitalWrite(3,Bin1[3]);
  digitalWrite(4,Bin2[0]);
  digitalWrite(5,Bin2[1]);
  digitalWrite(6,Bin2[2]);
  digitalWrite(7,Bin2[3]);
  digitalWrite(8,Bin3[0]);
  digitalWrite(9,Bin3[1]);
  digitalWrite(10,Bin3[2]);
  digitalWrite(11,Bin3[3]);
   Serial.println("--------------------------------------------------------------------------------");
  
  /*Serial.print(output[0]);
  Serial.print(output[1]);
  Serial.print(output[2]);
  Serial.print(output[3]);  
  Serial.print(output[4]);
   Serial.println("");*/  
    while(Serial.available()>0)  
  {  
   }    
}
void convertDecToBin(int Dec, boolean Bin[]) {
   Bin[0]=0;
    Bin[1]=0;
    Bin[2]=0;
    Bin[3]=0;
  for(int i = 3 ; i >= 0 ; i--) {
    if(pow(2, i)<=Dec) {
      Dec = Dec - pow(2, i);
      Bin[4-(i+1)] = 1;
    }
  }
}
float convertBinToDec(boolean Bint[]) {
  float ReturnInt = 0;
  for(int i = 0;i<4;i++) {
    ReturnInt+=(pow(2,3-i)*(int(Bint[i])));
    //Serial.println(pow(2,4-i)*int(Bint[i]));
  }
  return ReturnInt;
}
