//Automatic Garbage Sorting Machine by Hobby Project.

#include <Servo.h>            // include servo.h library
#include <LiquidCrystal.h>   //  include liquid crytstal library

#define trigPin 6 //Define the HC-SE04 triger on pin 6 on the arduino
#define echoPin 5 //Define the HC-SE04 echo on pin 5 on the arduino

Servo myservo_sensor;
int pos_sensor = 0; 
int smos;
int metel;

LiquidCrystal lcd(A3, A2,13 , 12, 11, 10);
void setup()
{
  Serial.begin (9600);
  myservo_sensor.attach(8);//connect servo to pin 8
  myservo_sensor.write(0); 
  pinMode(7,INPUT); //input pin coming from soil sensor
  pinMode(9,INPUT); //input pin coming from metel sensor(black wire)
  pinMode(trigPin, OUTPUT); //set the trigpin to output
  pinMode(echoPin, INPUT); //set the echopin to input
  pinMode(3,OUTPUT); //Buzzer
  
  lcd.begin(16, 2);
  lcd.print("    WELCOME"); 
  delay (3000);
}

void loop() { 
lcd.setCursor(0, 0);  
lcd.print("  WAITING...");
smos = digitalRead(7); 
metel = digitalRead(9);
digitalWrite(3,LOW);
lcd.setCursor(0, 0);  
lcd.print("  WAITING...");
Serial.print("waiting"); 

 if(metel == LOW)
 {
  lcd.clear();
   Serial.print("metel"); 
   lcd.setCursor(0, 0); 
   lcd.print(" METAL ");
   digitalWrite(3,HIGH);
   myservo_sensor.write(40); 
  
  delay(3000);
 }
  if(smos == LOW)  
  {
    lcd.clear();
   Serial.print("organic"); 
   lcd.setCursor(0, 0); 
   lcd.print(" ORGANIC ");
   digitalWrite(3,HIGH); 
   myservo_sensor.write(40); 
  
  delay(3000);
  }
  else
  {
    int duration, distance; //Define two intregers duration and distance to be used to save data

digitalWrite(trigPin, HIGH); //write a digital high to the trigpin to send out the pulse

delayMicroseconds(500); //wait half a millisecond

digitalWrite(trigPin, LOW); //turn off the trigpin

duration = pulseIn(echoPin, HIGH); //measure the time using pulsein when the echo receives a signal set it to high

distance = (duration/2) / 29.1; //distance is the duration devided by 2 becasue the signal traveled from the trigpin then back to the echo pin, then divide by 29.1 to convert to centimeters

if (distance < 04) //if the distance is less than 4 CM
{
    lcd.clear();
   Serial.print("plastic");  
     lcd.setCursor(0, 0); 
     lcd.print("  PLASTIC ");
     digitalWrite(3,HIGH);
  myservo_sensor.write(40);
  
  delay(2000); 
}}}
