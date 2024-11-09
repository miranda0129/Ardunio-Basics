const int switchPin = 2;
const int motorPin = 9;
int switchState = 0;
bool motorFlip = false;


void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(switchPin, INPUT);

}

//void loop() {
//  switchState = digitalRead(switchPin);
//
  //if (switchState  == HIGH) {
    //digitalWrite(motorPin, HIGH);
  //} else {
    //digitalWrite(motorPin, LOW);
  //}
//}

void loop() {
  switchState = digitalRead(switchPin);

  if (switchState == HIGH){
    motorFlip = !motorFlip;
  } 

  

  if (motorFlip) {
    digitalWrite(motorPin, HIGH);
  } else {
    digitalWrite(motorPin, LOW);
  }

}
