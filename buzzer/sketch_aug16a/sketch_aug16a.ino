#include "pitches.h"
 
int melody[] = {0, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5};

const int button[] = {22,28,34};
const int led[] = {-1, 4, 5, 6 ,7 , 9, 10, 11};
const int buzzer = 8;
 
void setup() {
  int i;
  for (i=1;i<=7;i++){
    pinMode(led[i], OUTPUT);
  }
  for (i=0;i<3;i++){
    pinMode(button[i], INPUT);
  }
}

void loop() {
  int i, num;
  int b[3];
  num = 0;
  for (i=0;i<3;i++){
    b[i] = digitalRead(button[i]);
  }
  num |= ( b[0] | (b[1]<<1) | (b[2]<<2) );
  
  for (i=1;i<=7;i++){
    if (num == i)
      digitalWrite(led[i], HIGH);
    else
      digitalWrite(led[i], LOW);
  }
  
  if (num > 0){
    tone(buzzer, melody[num]);
  }
  delay(200);
  noTone(buzzer);
}

