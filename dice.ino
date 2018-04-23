/*
 * Created By Streanga Sarmis-Stefan<streangasarmis@gmail.com>
 * 
 * 13 -> top right
 * 12 -> right middle
 * 11 -> middle
 * 10 -> left middle
 * 9  -> top left
 * 8  -> bottom left
 * 7  -> bottom right
 * 
 */

typedef struct face{
  byte number;
  byte pins[6]; // maximum of 6 leds at once
} face;

face faces[6] = {
  {1, {11}},
  {2, {9, 7}},
  {3, {9, 11, 7}},
  {4, {13, 9, 8, 7}},
  {5, {13, 9, 8, 7, 11}},
  {6, {13, 9, 8, 7, 12, 10}}
};

byte r;

void setup() {
  Serial.begin(9600);
  for(byte pin = 7; pin <= 13; ++pin){
    pinMode(pin, OUTPUT);
  }
  
  randomSeed(analogRead(0));
}

void lightLeds(const face& f){
  for(byte pin = 7; pin <= 13; ++pin){
    digitalWrite(pin, LOW);
  }

  for(byte i = 0; i < f.number; ++i){
    digitalWrite(f.pins[i], HIGH);
  }
  
}

void loop() {
  if(Serial.available() > 0){
    byte value = Serial.read();
    if(value == '1'){
      r = random(1, 7);
      lightLeds(faces[r - 1]);
    }
  }
}





