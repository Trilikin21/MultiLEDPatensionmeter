
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
 if (ldrStatus < 150) {
    //get's sensor value from the potentionmeter
    int sensorValue = analogRead(sensorPin);
    
    //devide by 4 and -5 to normalize maximize the values to 250 to assure function with if..else statements below
    sensorValue = (sensorValue/4)-5;
    //delay of 0.1 seconds
    delay(100);
    Serial.println("LDR IS DARK, ACTIVATE LED");
    //depending on the value, it will light up different LED'S
     if (sensorValue <=50) {
    digitalWrite(yellowLED, HIGH);
  }
     else {
      digitalWrite(yellowLED, LOW);
  }
  if (sensorValue >50 && sensorValue <=100 ) {
      digitalWrite(redLED, HIGH);
  }
    else {
      digitalWrite(redLED, LOW);
  }
  if (sensorValue >100 && sensorValue <=150) {
      digitalWrite(greenLED, HIGH);
  }
    else {
      digitalWrite(greenLED, LOW);
  }
  if (sensorValue >150 && sensorValue <=200) {
      digitalWrite(whiteLED, HIGH);
  }
    else {
      digitalWrite(whiteLED, LOW);
  }
  if (sensorValue >200 && sensorValue <=250) {
      digitalWrite(blueLED, HIGH);
  }
    else {
      digitalWrite(blueLED, LOW);
  }
  //depending on the value, it will light up different LED'S
 }
 else {
  //if not, deactivate all lights.
  Serial.println("LDR IS BRIGHT, DEACTIVATE LED");
  digitalWrite(blueLED, LOW);
  digitalWrite(whiteLED, LOW);
  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);
 }
}
