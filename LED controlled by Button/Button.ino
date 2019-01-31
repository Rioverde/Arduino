int buttonState = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(7, INPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   buttonState = digitalRead(7);
   if(buttonState == HIGH)
   {
      digitalWrite(4, HIGH);
      Serial.println("HIGH");
    }
   else
      digitalWrite(4, LOW);
      Serial.println("LOW");
   
}