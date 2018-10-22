#include"pitches.h"

int melody[] = {
NOTE_A4, NOTE_AS4, NOTE_B4, NOTE_C4,
NOTE_C3, NOTE_CS3, NOTE_D3, NOTE_E3,                   
NOTE_D4, NOTE_DS4, NOTE_E4, NOTE_F4,0,                                 
END
};


int noteDurations[] = {       //duration of the notes
3,3,3,6,
3,3,3,6,
3,3,3,6,
};

int speed=120;

int trig = 11; // Trigger
int echo = 12; // Echo
int sound = 9; // Music output
long duration, cm, inches;

void setup() {
  Serial.begin (9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(sound, OUTPUT);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  pinMode(echo, INPUT);
  duration = pulseIn(echo, HIGH);

  cm = (duration/2) / 29.1;
  inches = (duration/2) / 74;

  if(cm <= 10){
    for (int thisNote = 0; melody[thisNote]!=-1; thisNote++) {

    int noteDuration = speed*noteDurations[thisNote];
    tone(sound, melody[thisNote],noteDuration*.95);
    Serial.println(melody[thisNote]);
    
    delay(noteDuration);
    
    noTone(sound);
    }
    delay(1000000);
  }

  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(50);
}
