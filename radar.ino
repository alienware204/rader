#include<Servo.h>
#include <LiquidCrystal.h>

#define trigPin 8
#define echoPin 9

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
long duration;
int distance ;

Servo myservo;

int calculateDistance()
{
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  return distance;
}

void setup()
{
  lcd.begin(16, 2);
  pinMode(trigPin , OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(6);
  Serial.begin(9600);
}

void loop()
{
 int i ;
 for (i=15; i<=165; i++)
 {
  myservo.write(i);
  delay(15);
  calculateDistance();
   lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm");

  // Print the distance to the serial monitor (optional)
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
 }
 for(i=165; i>=15; i--)
 {
  myservo.write(i);
  delay(15);
  calculateDistance();
   lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm");

  // Print the distance to the serial monitor (optional)
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
 }

 
  

}
