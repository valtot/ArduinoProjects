int buttonApin = 2;
int buttonBpin = 3;
int buttonCpin = 4;
int buttonDpin = 5;

int notes[] = {262, 294,330,349};


void setup() {
  pinMode(buttonApin, INPUT_PULLUP);
  pinMode(buttonBpin, INPUT_PULLUP);
  pinMode(buttonCpin, INPUT_PULLUP);
  pinMode(buttonDpin, INPUT_PULLUP);
}

void loop() {

if (digitalRead(buttonApin) == LOW){
  tone(9, notes[0],20);
} else if(digitalRead(buttonBpin) == LOW){
  tone(9, notes[1],20);
}else if(digitalRead(buttonCpin) == LOW){
  tone(9, notes[2],20);
}else if(digitalRead(buttonDpin) == LOW){
  tone(9, notes[3],20);
} else{
  noTone(9);
  
}
//delay(10);
}
