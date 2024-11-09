void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.write(100);
  delay(1);
}

