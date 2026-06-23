// CODIGO ARDUINO - RADAR 

#include <Servo.h>

// Pines (los tuyos)
const int trigPin = 9;
const int echoPin = 8;

long duration;
int distance;

Servo myServo;

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  
  Serial.begin(9600);
  
  // Servo en pin 7 (tu configuración)
  myServo.attach(7);
}

void loop() {
  // Barrido de izquierda a derecha
  for(int i = 15; i <= 165; i++){  
    myServo.write(i);
    delay(30);

    distance = calculateDistance();

    Serial.print(i); 
    Serial.print(","); 
    Serial.print(distance);
    Serial.print(".");
  }

  // Barrido de derecha a izquierda
  for(int i = 165; i > 15; i--){  
    myServo.write(i);
    delay(30);

    distance = calculateDistance();

    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
}

// Función para calcular distancia
int calculateDistance(){
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Timeout agregado (mejora importante)
  duration = pulseIn(echoPin, HIGH, 30000);

  distance = duration * 0.034 / 2;

  return distance;
}

