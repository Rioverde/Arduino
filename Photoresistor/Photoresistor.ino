void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(7, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(10);

  if(sensorValue <= 650)
    digitalWrite(7,LOW);
  else
    digitalWrite(7,HIGH);
  }
