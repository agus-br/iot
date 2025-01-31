
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
}

void loop() {
  

  digitalWrite(trig, HIGH);
  delayMicroseconds(20);
  digitalWrite(trig, LOW);

  time = pulseIn(echo, HIGH);
  distance = time * 0.0344 / 2;

  Serial.print("Tiempo: ");
  Serial.println(time);
  Serial.print("Distancia: ");
  Serial.println(distance);

  if (distance >= 20)
      digitalWrite(green, HIGH);
  else if (distance >= 10)
      digitalWrite(yellow, HIGH);
  else
      digitalWrite(red, HIGH);

  delay(1000);
  
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);

}
