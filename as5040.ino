#define encoder0PinA  2
#define encoder0PinB  3

int position_encoder = 0;
float position_degrees;
void setup() {
  Serial.begin (9600);
  pinMode(encoder0PinA, INPUT);
  pinMode(encoder0PinB, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), encoder, CHANGE);
}




void loop() {
  position_degrees = position_encoder * 360.00 / 512.00;
  Serial.println(position_degrees);
  delay(100);
}



void encoder() {
  noInterrupts();
  if (digitalRead(encoder0PinA) == HIGH) {

    if (digitalRead(encoder0PinB) == HIGH) {
      position_encoder++;
    }
    else if (digitalRead(encoder0PinB) == LOW) {
      position_encoder--;
    }
  }
  else if (digitalRead(encoder0PinA) == LOW) {
    if (digitalRead(encoder0PinB) == LOW) {
      position_encoder++;
    }
    else if (digitalRead(encoder0PinB) == HIGH) {
      position_encoder--;
    }
  }
  interrupts();
}

