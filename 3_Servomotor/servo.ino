#include <Servo.h>

Servo servoMotor;

const int trig = 4;
const int echo = 5;

const int red = 10;
const int yellow = 9;
const int green = 8;

long time;
int distance;

void setup() {
  Serial.begin(9600);
  
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);

  servoMotor.attach(6);
}

void loop() {
  int interval = 2000;
  servoMotor.write(0);
  sonar();
  delay(interval);

  servoMotor.write(60);
  sonar();
  delay(interval);

  servoMotor.write(120);
  sonar();
  delay(interval);
  
  servoMotor.write(180);
  sonar();
  delay(interval);
}

void sonar(){
  digitalWrite(trig, HIGH);
  delayMicroseconds(20);
  digitalWrite(trig, LOW);

  time = pulseIn(echo, HIGH);
  distance = time * 0.0344 / 2;

  Serial.print("Tiempo: ");
  Serial.println(time);
  Serial.print("Distancia: ");
  Serial.println(distance);

  if(distance >= 20){
    digitalWrite(green, HIGH);  
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
  }else if(distance >= 10){
    digitalWrite(green, LOW);  
    digitalWrite(yellow, HIGH);
    digitalWrite(red, LOW);
  }else{
    digitalWrite(green, LOW);  
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
  }
}