void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(7, OUTPUT);
}

void blink(int pincode, int amount, int delaytime) {
  for(int i = 0; i < amount; i++) {
    digitalWrite(pincode, HIGH);
    delay(delaytime);
    digitalWrite(pincode,LOW);
    delay(delaytime);
  }
}

void loop() {
  blink(13, 5, 250);
  blink(12,10, 500);
  blink(7, 15, 300);
}
