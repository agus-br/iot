#include <Servo.h> // Librería para controlar el servomotor

// Definición del objeto para el servomotor
Servo servoMotor;  

// Definición de pines para el sensor ultrasónico
const int TRIG = 4;  // Pin para la señal de disparo del sensor ultrasónico
const int ECHO = 5;  // Pin para la señal de eco del sensor ultrasónico

// Definición de pines para los LEDs del semáforo
const int LED_ROJO = 10; // Proximidad alta
const int LED_AMARILLO = 9; // Proximidad media
const int LED_VERDE = 8; // Proximidad baja

// Variables globales para almacenar el tiempo y la distancia medida
long time;
int distance;

// Variable de control para encender o apagar el radar
bool on = false;

void setup() {
  // Inicialización de la comunicación serial para la conexión con Python o monitoreo
  Serial.begin(9600);
  
  // Configuración de los pines del sensor ultrasónico y LEDs
  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_AMARILLO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);

  // Asignación del pin donde está conectado el servomotor
  servoMotor.attach(6);
}

void loop() {
  // Verifica si hay datos disponibles en el puerto serial
  if (Serial.available() > 0) {
    char c = Serial.read();  // Lee el carácter recibido
    if (c == 'a')  // Si recibe 'a', enciende el radar
      on = true;
    if (c == 'q')  // Si recibe 'q', apaga el radar
      on = false;
  }

  // Si el radar está activado, realiza el escaneo en diferentes ángulos
  if (on) {
    int interval = 2000;  // Tiempo de espera entre cada medición (2 segundos)

    // Movimiento del servomotor a diferentes posiciones y medición de distancia
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
}

// Función para medir la distancia con el sensor ultrasónico y actualizar el semáforo
void sonar(){
  // Genera un pulso de activación en el sensor ultrasónico
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(20);
  digitalWrite(TRIG, LOW);

  // Mide el tiempo que tarda en regresar el eco
  time = pulseIn(ECHO, HIGH);
  
  // Calcula la distancia en cm (tiempo * velocidad del sonido / 2)
  distance = time * 0.0344 / 2;

  // Muestra los valores en el monitor serial
  Serial.print("Tiempo: ");
  Serial.println(time);
  Serial.print("Distancia: ");
  Serial.println(distance);

  // Control del semáforo en función de la distancia detectada
  if(distance >= 20){
    digitalWrite(LED_VERDE, HIGH);  
    digitalWrite(LED_AMARILLO, LOW);
    digitalWrite(LED_ROJO, LOW);
  } else if(distance >= 10){
    digitalWrite(LED_VERDE, LOW);  
    digitalWrite(LED_AMARILLO, HIGH);
    digitalWrite(LED_ROJO, LOW);
  } else {
    digitalWrite(LED_VERDE, LOW);  
    digitalWrite(LED_AMARILLO, LOW);
    digitalWrite(LED_ROJO, HIGH);
  }
}
