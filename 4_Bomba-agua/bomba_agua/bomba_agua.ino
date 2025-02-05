
const int trig = 4; // Trigguer envía la señal
const int echo = 5; // Echo recibe la señal

const int red = 10; // LED rojo
const int yellow = 9; // LED amarillo
const int green = 8; // LED verde


void setup() {

  Serial.begin(9600); // 
  
  pinMode(echo, INPUT); // Establecemos pin 5 como entrada de datos o pin de lectura
  pinMode(trig, OUTPUT); // Establecemos pin 4 como salida 

  pinMode(red, OUTPUT); // Establecemos pin conectado al LED rojo como pin de salida
  pinMode(yellow, OUTPUT); // Establecemos pin conectado al LED amarillo como pin de salida
  pinMode(green, OUTPUT); // Establecemos pin conectado al LED verde como pin de salida

}

void loop() {
  int distance = sonar();

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
  Serial.println(distance);
  */
  
  return distancia
}