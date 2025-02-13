
const int trig = 4; // Trigguer envía la señal
const int echo = 5; // Echo recibe la señal

const int red = 10; // LED rojo
const int yellow = 9; // LED amarillo
const int green = 8; // LED verde

const int rele = 12; // Pin del relevador 
const int pinTest = 13; // Pin de prueba 


void setup() {

  Serial.begin(9600);  
  
  pinMode(echo, INPUT); // Establecemos pin 5 como entrada de datos o pin de lectura
  pinMode(trig, OUTPUT); // Establecemos pin 4 como salida 

  pinMode(red, OUTPUT); // Establecemos pin conectado al LED rojo como pin de salida
  pinMode(yellow, OUTPUT); // Establecemos pin conectado al LED amarillo como pin de salida
  pinMode(green, OUTPUT); // Establecemos pin conectado al LED verde como pin de salida

  pinMode(rele, OUTPUT); // Establecemos el pin del rele como salida
  digitalWrite(rele, HIGH); // Que comience apagada
}

void loop() {


  if (Serial.available() > 0) {
    char c = Serial.read();
    if (c == 'a')
      digitalWrite(rele, LOW);

    if (c == 'q')
      digitalWrite(rele, HIGH);
  }

  int distance = sonar();

  if(distance >= 13){
    digitalWrite(green, LOW);  
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);

  }else if(distance >= 6){
    digitalWrite(green, LOW);  
    digitalWrite(yellow, HIGH);
    digitalWrite(red, LOW);
  }else if(distance >= 2){
    digitalWrite(green, HIGH);  
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
  }else{
    digitalWrite(rele, HIGH);  
    digitalWrite(green, HIGH);  
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
  }
  
}

int sonar(){
  long time; // Variable para guardar el tiempo 
  int distance; // Variable para guardar la distancia calculada

  digitalWrite(trig, HIGH);
  delayMicroseconds(20);
  digitalWrite(trig, LOW);

  time = pulseIn(echo, HIGH);
  distance = time * 0.0344 / 2;

  /*
  Serial.print("Tiempo: ");
  Serial.println(time);
  Serial.print("Distancia: ");
  */
  delay(100);
  //Serial.println(distance);
  
  return distance;
}