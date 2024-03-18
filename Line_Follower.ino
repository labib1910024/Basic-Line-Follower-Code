#define enA 10//Enable1 L298 Pin enA  
#define in1 9 //Motor1  L298 Pin in1  
#define in2 8 //Motor1  L298 Pin in1  
#define in3 7 //Motor2  L298 Pin in1  
#define in4 6 //Motor2  L298 Pin in1  
#define enB 5 //Enable2 L298 Pin enB  
 
#define L_S A0 //ir sensor Left 
#define R_S A1 //ir sensor Right 
#define M_S A4//ir sensor middle 
 
 
 
void setup(){ // put your setup code here, to run once 
 
Serial.begin(9600); // start serial communication at 9600bps 
 
pinMode(R_S, INPUT); // declare if sensor as input   
pinMode(L_S, INPUT); // declare ir sensor as input 
pinMode(M_S, INPUT); // declare mr sensor as input 
 
  
 
pinMode(enA, OUTPUT); // declare as output for L298 Pin enA  
pinMode(in1, OUTPUT); // declare as output for L298 Pin in1  
pinMode(in2, OUTPUT); // declare as output for L298 Pin in2  
pinMode(in3, OUTPUT); // declare as output for L298 Pin in3    
pinMode(in4, OUTPUT); // declare as output for L298 Pin in4  
pinMode(enB, OUTPUT); // declare as output for L298 Pin enB  
 
analogWrite(enA, 130); // Write The Duty Cycle 0 to 255 Enable Pin A for Motor1 Speed  
analogWrite(enB, 130); // Write The Duty Cycle 0 to 255 Enable Pin B for Motor2 Speed  
 

 

} 
 
 
void loop(){   

//if Right Sensor and Left Sensor are at White color then it will call forword function 
 if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 0)&&(digitalRead(M_S) == 1))
 {  
    forword(); 
      
 }   
  
//if Right Sensor is Black and Left Sensor is White then it will call turn Right function 
else if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 0)&&(digitalRead(M_S) == 1)||(digitalRead(R_S) == 1)&&(digitalRead(L_S) == 0)&&(digitalRead(M_S) == 0))
{
  turnRight();
}   
 
//if Right Sensor is White and Left Sensor is Black then it will call turn Left function 
else if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 1)&&(digitalRead(M_S) == 1)||(digitalRead(R_S) == 0)&&(digitalRead(L_S) == 1)&&(digitalRead(M_S) == 0))
{
  turnLeft();
 }  



//if Right Sensor is Black and Left Sensor is black then it will call stop function 
else if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 1)&&(digitalRead(M_S) == 1))
{
  Stop();
 }   
 

delay(10); 
} 
 



void forword(){  
digitalWrite(in1, LOW); //Right Motor backword Pin  
digitalWrite(in2, HIGH); //Right Motor forword Pin  
digitalWrite(in3, HIGH); //Left Motor forword Pin  
digitalWrite(in4, LOW); //Left Motor backword Pin  
} 
 
void backword(){ 
digitalWrite(in1, HIGH); //Right Motor backword Pin  
digitalWrite(in2, LOW); //Right Motor forword Pin  
digitalWrite(in3, LOW); //Left Motor forword Pin  
digitalWrite(in4, HIGH); //Left Motor backword Pin  
} 
 
void turnRight(){ 
digitalWrite(in1, HIGH); //Right Motor backword Pin  
digitalWrite(in2, LOW); //Right Motor forword Pin  
digitalWrite(in3, HIGH); //Left Motor forword Pin  
digitalWrite(in4, LOW); //Left Motor backword Pin  
} 
 
void turnLeft(){ 
digitalWrite(in1, LOW); //Right Motor backword Pin  
digitalWrite(in2, HIGH); //Right Motor forword Pin  
digitalWrite(in3, LOW); //Left Motor forword Pin  
digitalWrite(in4, HIGH); //Left Motor backword Pin  
} 
 
void Stop(){ 
digitalWrite(in1, LOW); //Right Motor backword Pin  
digitalWrite(in2, LOW); //Right Motor forword Pin  
digitalWrite(in3, LOW); //Left Motor forword Pin  
digitalWrite(in4, LOW); //Left Motor backword Pin  
}
