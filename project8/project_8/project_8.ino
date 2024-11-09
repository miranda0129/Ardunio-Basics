const int switchPin = 8;
unsigned long previousTime = 0;

int switchState = 0;
int prevSwitchState = 0;

int led = 2;
long interval = 10000;

void setup() {
  Serial.begin(9600);
  for (int x = 2; x < 8; x++) {
    pinMode(x, OUTPUT);
  }
  pinMode(switchPin, INPUT);
}

void loop() {
  unsigned long currentTime = millis();

  if (currentTime - previousTime > interval) {
    previousTime = currentTime;
    digitalWrite(led, HIGH);
    led++;
  }


  Serial.print("led: ");
  Serial.println(led);

  if (led > 7){

    for(int i=0; i < 5; i++) {
      for (int x = 2; x < 8; x++) {
        digitalWrite(x, LOW);
      }
      delay(1000);
      for (int x = 2; x < 8; x++) {
        digitalWrite(x, HIGH);
      }
      delay(1000);
    }
    
  }

  switchState = digitalRead(switchPin);

  if (switchState != prevSwitchState) {
    for (int x = 2; x < 8; x++) {
      digitalWrite(x, LOW);
    }

    led = 2;
    previousTime = currentTime;
  }

  prevSwitchState = switchState;

}
