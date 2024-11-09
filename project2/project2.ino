int switchState = 0;
void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop() {
  switchState = digitalRead(2);

  if (switchState == LOW) {
    digitalWrite(3, HIGH); //green
    digitalWrite(4, LOW);  //blue
    digitalWrite(5, LOW);  //red
  } else {
    digitalWrite(3, LOW);  //green
    digitalWrite(4, LOW);  //blue
    digitalWrite(5, HIGH);  //red

    delay(250); //wait quarter of a second

    //toggle
    digitalWrite(4, HIGH);  //blue
    digitalWrite(5, LOW);  //red

    delay(250); //delay
  }

}
