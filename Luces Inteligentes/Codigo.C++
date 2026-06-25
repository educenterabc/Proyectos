int D0 = 2;

int leds[] = {3,4,5,6,7,8,9,10};
int ESTADO = 0;

void setup(){
  pinMode(D0, INPUT_PULLUP);

  for(int i=0; i<8; i++){
    pinMode(leds[i], OUTPUT);
  }
}

void loop(){
  ESTADO = digitalRead(D0);

  if (ESTADO == 0){ // invertido

    for(int i=0; i<8; i++){
      digitalWrite(leds[i], HIGH);
      delay(80);
    }

    for(int i=7; i>=0; i--){
      digitalWrite(leds[i], LOW);
      delay(80);
    }
  }
}

