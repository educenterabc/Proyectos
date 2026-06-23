#include <Servo.h>

Servo tapa;

// Pines
const int servoPin = 5;
const int trigPin = 7;
const int echoPin = 6;

// Variables
long duracion;
float distancia;

void setup() {
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  tapa.attach(servoPin);

  // Tapa cerrada
  tapa.write(0);
}

void loop() {

  // Limpiar el TRIG
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Enviar pulso
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Leer el eco
  duracion = pulseIn(echoPin, HIGH);

  // Calcular distancia
  distancia = duracion * 0.0343 / 2;

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // Detectar mano
  if (distancia > 0 && distancia <= 15) {

    Serial.println("Abriendo tapa");

    tapa.write(80);      // Abrir
    delay(3000);         // Mantener abierta

    Serial.println("Cerrando tapa");

    tapa.write(0);       // Cerrar
    delay(500);
  }

  delay(100);
}

