#include <Servo.h> 

Servo SMGrua; // El palo grueso 
Servo SMBrazo; // El palo no tan grueso que va horizontal
Servo SMInclinacionGarra; // El servo que controla la elevación de la garra
Servo SMGarra; // El servo que controla la apertura o cierre de la garra

// Pines donde conectamos para enviar cosas a los servos
const int servoPinGrua = 7;
const int servoPinBrazo = 6;
const int servoPinInclinacionGarra = 8;
const int servoPinGarra = 9;

// En estos pines se conectan los joysticks, son solo 2 (Usamos cada eje para mover algo diferente)
const int joyYPinGrua = A0;
const int joyXPinBrazo = A1;
const int joyYPinInclinacionGarra = A4;
const int joyXPinAperturaGarra = A5;

// Para controlar el giro de cada servo, además para tener una posicion inicial
int posGrua = 130;
int posBrazo = 95;
int posInclinacionGarra = 90;
int posAperturaGarra = 68;

// Estas son para controlar los valores que envían los joysticks
int joyYGrua;
int joyXBrazo;
int joyYInclinacionGarra;
int joyXAperturaGarra;

// Umbrales de movimientos máximos y mínimos oara la lectura de los joysticks (Podrían usar valores constantes para optimizar la memoria)
// Los umbrales están casi a los extremos de los joysticks para evitar un poco mover dos servos a la vez, aunque aún puede pasar
const int umbralSuperior = 925;
const int umbralInferior = 125;

void setup() {
  Serial.begin(9600);

  SMGrua.attach(servoPinGrua);
  SMBrazo.attach(servoPinBrazo);
  SMInclinacionGarra.attach(servoPinInclinacionGarra);
  SMGarra.attach(servoPinGarra);

  // Establecemos una posición inicial a cada servo
  SMGrua.write(posGrua);
  SMBrazo.write(posBrazo);
  SMInclinacionGarra.write(posInclinacionGarra);
  SMGarra.write(posAperturaGarra);
}

void loop() {
  // Leemos lo que nos mandan los joysticks XD
  joyYGrua = analogRead(joyYPinGrua);
  joyXBrazo = analogRead(joyXPinBrazo);
  joyYInclinacionGarra = analogRead(joyYPinInclinacionGarra);
  joyXAperturaGarra = analogRead(joyXPinAperturaGarra);

  // Banderas para saber cual se menea
  bool moverGrua = false; 
  bool moverBrazo = false; 
  bool inclinarGarra = false; 
  bool abrirGarra = false; 

  // Bloque de evaluación de lectura de los valores de los joysticks
  // Según el movimiento y magnitud del movimiento del joystick activamos que se mueva un servomotro
  // NOTA: Podríamos aplicar restricciones en las magnitudes más específicas para evitar que se muevan otros servos como daño colateral de nuestra falta de precisión en los dedos XD
  if (joyYGrua > umbralSuperior && posGrua < 170) {
    posGrua++; 
    moverGrua = true;
  } else if (joyYGrua < umbralInferior && posGrua > 90) {
    posGrua--; 
    moverGrua = true;
  }
  
  if (joyXBrazo > umbralSuperior && posBrazo < 140) {
    posBrazo++;
    moverBrazo = true;
  } else if (joyXBrazo < umbralInferior && posBrazo > 50) {
    posBrazo--; 
    moverBrazo = true;
  }

  if (joyYInclinacionGarra > umbralSuperior && posInclinacionGarra < 135) {
    posInclinacionGarra++; 
    inclinarGarra = true;
  } else if (joyYInclinacionGarra < umbralInferior && posInclinacionGarra > 45) {
    posInclinacionGarra--; 
    inclinarGarra = true;
  }

  if (joyXAperturaGarra > umbralSuperior && posAperturaGarra < 112) {
    posAperturaGarra++;
    abrirGarra = true;
  } else if (joyXAperturaGarra < umbralInferior && posAperturaGarra > 68) {
    posAperturaGarra--; 
    abrirGarra = true;
  }

  // Evaluamos las banderas para enviar una señal de movimiento a los servos
  if (moverGrua) {
    SMGrua.write(posGrua);
  }
  
  if (moverBrazo) {
    SMBrazo.write(posBrazo);
  }

  if (inclinarGarra) {
    SMInclinacionGarra.write(posInclinacionGarra);
  }

  if (abrirGarra) {
    SMGarra.write(posAperturaGarra);
  }

  delay(50);
}