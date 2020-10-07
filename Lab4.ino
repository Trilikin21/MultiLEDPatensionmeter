
const int redLED = 6;
const int yellowLED = 7;
const int greenLED = 5;
const int blueLED = 3;
const int whiteLED = 4;
const int sensorPin = A0;
const int ldrPin = A1;

void setup()
{

  Serial.begin(9600);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(whiteLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(ldrPin, INPUT);
  pinMode(sensorPin, INPUT);
}

void loop()
{

  //get's sensor value from the photoresistor
  int ldrStatus = analogRead(ldrPin);
  //if the photoresitor value is over 150, continue with inner if...else statement
  Serial.print(ldrStatus);

  //get's sensor value from the potentionmeter
  int sensorValue = analogRead(sensorPin);

  int blinkSpeed = ldrStatus * 100;

  //devide by 4 and -5 to normalize maximize the values to 250 to assure function with if..else statements below
  sensorValue = (sensorValue / 4) - 5;
  //delay of 0.1 seconds
  delay(100);
  Serial.println("LDR IS DARK, ACTIVATE LED");
  //depending on the value, it will light up different LED'S
  if (sensorValue < 50) {
    digitalWrite(yellowLED, HIGH);
    delay(blinkSpeed);
    digitalWrite(yellowLED, LOW);
  }
  else {
    digitalWrite(yellowLED, LOW);
  }
  if (sensorValue > 50 && sensorValue <= 100 ) {
    digitalWrite(redLED, HIGH);
    delay(blinkSpeed);
    digitalWrite(redLED, LOW);
  }
  else {
    digitalWrite(redLED, LOW);
  }
  if (sensorValue > 100 && sensorValue <= 150) {
    digitalWrite(greenLED, HIGH);
    delay(blinkSpeed);
    digitalWrite(greenLED, LOW);
  }
  else {
    digitalWrite(greenLED, LOW);
  }
  if (sensorValue > 150 && sensorValue <= 200) {
    digitalWrite(whiteLED, HIGH);
    delay(blinkSpeed);
    digitalWrite(whiteLED, LOW);
  }
  else {
    digitalWrite(whiteLED, LOW);
  }
  if (sensorValue > 200 && sensorValue <= 250) {
    digitalWrite(blueLED, HIGH);
    delay(blinkSpeed);
    digitalWrite(blueLED, LOW);
  }
  else {
    digitalWrite(blueLED, LOW);

  }
  //depending on the value, it will light up different LED'S
}
