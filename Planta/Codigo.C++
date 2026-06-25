
#include <Servo.h>

// Creamos el objeto servo
Servo miServo;

// Definimos el pin donde conectarás el cable de señal (naranja o amarillo)
const int pinServo = 5; 

void setup() {
  // Inicializamos el servo en el pin 9
  miServo.attach(pinServo);
}

void loop() {
  // Se mueve a 90 grados
  miServo.write(0);
  delay(1500); // Espera 1.5 segundos en esa posición

  // Regresa a 0 grados
  miServo.write(80);
  delay(1500); // Espera 1.5 segundos en esa posición
}
