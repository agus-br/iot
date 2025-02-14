
const int trig = 4; // Trigguer envía la señal
const int echo = 5; // Echo recibe la señal

const int red = 10; // LED rojo
const int yellow = 9; // LED amarillo
const int green = 8; // LED verde

const int rele = 12; // Pin del relevador 

void setup() {
  // Inicialización de la comunicación serial para la conexión con Python o monitoreo
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
  // Verifica si hay datos disponibles en el puerto serial
  if (Serial.available() > 0) {
    char c = Serial.read(); // Lee el carácter recibido
    if (c == 'a') // Si recibe 'a', enciende la bomba
      digitalWrite(rele, LOW);
    if (c == 'q') // Si recibe 'q', apaga la bomba
      digitalWrite(rele, HIGH);
  }

  // Recuperamos la distancia que calculamos con el sensor ultrasónico
  int distance = sonar();

  // Si la distancia es mayor o igual a 13 cm, encendemos el LED rojo y apagamos los demás
  // Esto indica que el recipiente está casi vacío
  if(distance >= 13){
    digitalWrite(green, LOW);  
    digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
  }
  // Si la distancia está entre 6 y 12 cm, encendemos el LED amarillo y apagamos los demás
  // Esto indica que el recipiente está a la mitad
  else if(distance >= 6){
    digitalWrite(green, LOW);  
    digitalWrite(yellow, HIGH);
    digitalWrite(red, LOW);
  }
  // Si la distancia está entre 2 y 5 cm, encendemos el LED verde y apagamos los demás
  // Esto indica que el recipiente está casi lleno
  else if(distance >= 2){
    digitalWrite(green, HIGH);  
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
  }
  // Si la distancia es menor a 2 cm, activamos el relé y encendemos el LED verde
  // La activación del rele hace que la bomba se apague, así simulamos un apagado de emergencia
  else{
    digitalWrite(rele, HIGH);  
    digitalWrite(green, HIGH);  
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
  }
  
}

// Función para medir la distancia con el sensor ultrasónico
int sonar(){
  long time; // Variable para guardar el tiempo 
  int distance; // Variable para guardar la distancia calculada

  // Genera un pulso de activación en el sensor ultrasónico
  digitalWrite(trig, HIGH);
  delayMicroseconds(20);
  digitalWrite(trig, LOW);

  // Mide el tiempo que tarda en regresar el eco
  time = pulseIn(echo, HIGH);

  // Calcula la distancia en cm (tiempo * velocidad del sonido / 2)
  distance = time * 0.0344 / 2;

  delay(100);
  
  // Retorna la distancia calculada
  return distance;
}