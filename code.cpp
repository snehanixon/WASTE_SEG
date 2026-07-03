// Eazytronic.com
#include<Servo.h>
int IR_sensor = 0;
Servo s1;
const int trigPin = 5;
const int echoPin = 6;
long duration;
int distanceCm, distanceInch;
void setup()
{

  Serial.begin(9600); 
  s1.attach(7);
  pinMode(4,INPUT);   // Soil moisture Sensor Pin
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}
void loop() 
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
distanceInch = duration*0.0133/2;
  IR_sensor = digitalRead(4);
  Serial.println(IR_sensor);

  Serial.println("Distance cm: ");
  Serial.println(distanceCm);
  delay(100);

if(distanceCm <20)
{
  
    if (IR_sensor == 0)
  {
       delay(1000);
       s1.write(100);
       delay(1000);
       
  }

      if (IR_sensor == 1)
  {
       delay(1000);
       s1.write(0);
       delay(1000);
       
  }

}

else
{ 
    s1.write(50);
  delay(1000);

}
}
