const int greenLEDin = 9;
const int redLEDin = 11;
const int blueLEDin = 10;

const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(greenLEDin, OUTPUT);
  pinMode(redLEDin, OUTPUT);
  pinMode(blueLEDin, OUTPUT);
  
}

void loop() {
  redSensorValue = analogRead(redSensorPin);
  delay(5);
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);

  redValue = redSensorValue/4;
  blueValue = blueSensorValue/4;
  greenValue = greenSensorValue/4;

  analogWrite(redLEDin, redValue);
  analogWrite(greenLEDin, greenValue);
  analogWrite(blueLEDin, blueValue);


}
