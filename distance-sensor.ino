#include <LiquidCrystal.h>
int rs=7;
int en=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
int trigPin=2;
int echoPin=3;
int pingTime;
float pingDistance;
float targetDistance;
int dt=250;


void setup() {

lcd.begin(16,2);
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
Serial.begin(9600);
}
 



void loop() {

digitalWrite(trigPin,LOW);
delayMicroseconds(10);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);
pingTime=pulseIn(echoPin,HIGH);
delay(25);
pingDistance=(pingTime*765.*5280.*12)/(3600.*1000000);
targetDistance=pingDistance/2;
Serial.print("Distance: ");
Serial.print(targetDistance);
Serial.println(" in");

lcd.setCursor(0,0);
lcd.print("Distance ");
lcd.setCursor(0,1);
lcd.print(targetDistance);
lcd.print(" Inches'");
delay(dt);
lcd.clear();
}
