
// Librería para la comunicación Bluetooth
#include <SoftwareSerial.h>

// Configuración de pines del módulo L298N
#define enA 6
#define enB 9
#define in1 5
#define in2 4
#define in3 8
#define in4 7

// Configuración de pines del módulo Bluetooth
#define bluetoothRX 12
#define bluetoothTX 13

// Variables para almacenar los comandos de Bluetooth
char comando;

// Crear instancia de comunicación Bluetooth
SoftwareSerial bluetoothSerial(bluetoothRX, bluetoothTX);

void setMotorSpeed(int speed) {
  analogWrite(enA, speed);
  analogWrite(enB, speed);
}


void stopMotors() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, HIGH);
}

void setup() {
  // Inicializar el puerto serie para la depuración
  Serial.begin(9600);

  // Inicializar la comunicación Bluetooth
  bluetoothSerial.begin(9600);

  // Configurar los pines del módulo L298N como salidas
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  setMotorSpeed(200);

  // Detener los motores al inicio
  stopMotors();
}

void loop() {

  // Verificar si hay datos disponibles en la conexión Bluetooth
  if (bluetoothSerial.available()) {
    comando = bluetoothSerial.read();
    Serial.println(comando);
    // Movimiento hacia adelante
    if (comando == 'F') {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      //setMotorSpeed(255);
    }

    // Movimiento hacia atrás
    if (comando == 'B') {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      //setMotorSpeed(255);
      
    }

    // Girar a la izquierda
    if (comando == 'L') {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      //setMotorSpeed(150);
      
    }

    // Girar a la derecha
    if (comando == 'R') {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      //setMotorSpeed(150);
    }

    // Detener el movimiento
    if (comando == 'S') {
      stopMotors();
    }
  }
}


