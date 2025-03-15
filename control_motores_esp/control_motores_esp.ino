#include "BluetoothSerial.h"

// Definir los pines de los motores
const int DERECHA_DELANTE = 18;  // Pin para el motor derecho hacia adelante
const int DERECHA_ATRAS = 19;    // Pin para el motor derecho hacia atrás
const int IZQUIERDA_DELANTE = 22; // Pin para el motor izquierdo hacia adelante
const int IZQUIERDA_ATRAS = 21;   // Pin para el motor izquierdo hacia atrás

// Crear una instancia de BluetoothSerial para la comunicación Bluetooth
BluetoothSerial SerialBT;

void setup() {
  // Inicializa el puerto serie para depuración a una velocidad de 115200 baudios
  Serial.begin(115200);
  
  // Inicializa el Bluetooth con el nombre "CarritoBT"
  SerialBT.begin("CarritoBT");
  
  // Mensaje de inicio para indicar que el Bluetooth está listo
  Serial.println("Bluetooth iniciado. Esperando conexión...");

  // Configurar los pines de los motores como salidas
  pinMode(DERECHA_DELANTE, OUTPUT);
  pinMode(DERECHA_ATRAS, OUTPUT);
  pinMode(IZQUIERDA_DELANTE, OUTPUT);
  pinMode(IZQUIERDA_ATRAS, OUTPUT);

  // Apagar todos los motores al inicio para asegurar que no se muevan
  detenerMotores();
}

void loop() {
  // Verificar si hay datos disponibles a través de Bluetooth
  if (SerialBT.available()) {
    // Leer el comando recibido
    char comando = SerialBT.read();
    
    // Imprimir el comando recibido en el monitor serie para depuración
    Serial.print("Comando recibido: ");
    Serial.println(comando);

    // Ejecutar la acción correspondiente al comando recibido
    ejecutarComando(comando);
  }
}

void ejecutarComando(char comando) {
  // Dependiendo del comando recibido, ejecutar la acción correspondiente
  switch (comando) {
    case 'F': // Comando para mover adelante
      moverAdelante();
      break;
    case 'B': // Comando para mover atrás
      moverAtras();
      break;
    case 'L': // Comando para girar a la izquierda
      girarIzquierda();
      break;
    case 'R': // Comando para girar a la derecha
      girarDerecha();
      break;
    case 'S': // Comando para detener los motores
      detenerMotores();
      break;
    default:  // Si el comando no es reconocido, imprimir un mensaje de error
      Serial.println("Comando desconocido");
      break;
  }
}

void moverAdelante() {
  // Activar los motores para mover el carrito hacia adelante
  digitalWrite(DERECHA_DELANTE, HIGH);
  digitalWrite(DERECHA_ATRAS, LOW);
  digitalWrite(IZQUIERDA_DELANTE, HIGH);
  digitalWrite(IZQUIERDA_ATRAS, LOW);
  
  // Imprimir mensaje de depuración
  Serial.println("Moviendo adelante");
}

void moverAtras() {
  // Activar los motores para mover el carrito hacia atrás
  digitalWrite(DERECHA_DELANTE, LOW);
  digitalWrite(DERECHA_ATRAS, HIGH);
  digitalWrite(IZQUIERDA_DELANTE, LOW);
  digitalWrite(IZQUIERDA_ATRAS, HIGH);
  
  // Imprimir mensaje de depuración
  Serial.println("Moviendo atrás");
}

void girarIzquierda() {
  // Activar los motores para girar el carrito a la izquierda
  digitalWrite(DERECHA_DELANTE, HIGH);
  digitalWrite(DERECHA_ATRAS, LOW);
  digitalWrite(IZQUIERDA_DELANTE, LOW);
  digitalWrite(IZQUIERDA_ATRAS, HIGH);
  
  // Imprimir mensaje de depuración
  Serial.println("Girando a la izquierda");
}

void girarDerecha() {
  // Activar los motores para girar el carrito a la derecha
  digitalWrite(DERECHA_DELANTE, LOW);
  digitalWrite(DERECHA_ATRAS, HIGH);
  digitalWrite(IZQUIERDA_DELANTE, HIGH);
  digitalWrite(IZQUIERDA_ATRAS, LOW);
  
  // Imprimir mensaje de depuración
  Serial.println("Girando a la derecha");
}

void detenerMotores() {
  // Desactivar todos los motores para detener el carrito
  digitalWrite(DERECHA_DELANTE, LOW);
  digitalWrite(DERECHA_ATRAS, LOW);
  digitalWrite(IZQUIERDA_DELANTE, LOW);
  digitalWrite(IZQUIERDA_ATRAS, LOW);
  
  // Imprimir mensaje de depuración
  Serial.println("Motores detenidos");
}