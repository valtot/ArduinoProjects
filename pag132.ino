#include <Servo.h>
Servo myServo;
const int piezo = A0;
const int switchPin = 2;
const int led1 = 3;
const int led2 = 4;
const int led3 = 5;

int knockVal;
int switchVal;

const int quietKnock = 10;
const int loudKnock = 100;
boolean locked = false;
int numberOfKnocks = 0;

void setup() {
  myServo.attach(9);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);
  Serial.begin(9600);
  digitalWrite(led2, HIGH);
  myServo.write(0);
  Serial.println("the box is unlocked!");
}

void loop() {
  if (locked == false){
    switchVal = digitalRead(switchPin);
    if (switchVal == LOW){
      locked = true;
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      myServo.write(90);
      Serial.println("The box is locked!");
      delay(1000);
    }
  }
if(locked == true){
  knockVal = analogRead(piezo);
  if(numberOfKnocks < 3 && knockVal>0){
    if(checkForKnock(knockVal)== true){
      numberOfKnocks++;
    }
    Serial.println(3-numberOfKnocks);
    Serial.println("more knocks to go");
  }
  if(numberOfKnocks >= 3){
    locked = false;
    myServo.write(0);
    delay(20);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    Serial.println("The box is unlocked!"); 
  }
}
}
boolean checkForKnock(int value){
  if(value>quietKnock && value <loudKnock){
    digitalWrite(led1, HIGH);
    delay(50);
    digitalWrite(led1, HIGH);
    Serial.print("Valid knock of value ");
    Serial.println(value);
    return true;
  }else{
    Serial.print("bad Knock Value");
    Serial.println(value);
    return false;
  }
}
