
int redLED = 6;
int yellowLED = 7;
int greenLED = 5;
int blueLED = 3;
int whiteLED = 4;
 
void setup()
{
  
  Serial.begin(9600);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(whiteLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
}
 
void loop()
{
  //get's sensor value from the Potentionmeter
  int sensorValue = analogRead(A0);
  //delay of 0.05 seconds
  delay(50);
  //devide by 4 and -5 to normalize the values.
  sensorValue = (sensorValue/4)-5;
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
  }+-
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
  delay(1);
  if (sensorValue >250){
    digitalWrite(blueLED, LOW);
    digitalWrite(whiteLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
  }
  Serial.println(sensorValue);
}
