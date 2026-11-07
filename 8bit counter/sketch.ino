void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void shutdown() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(5, LOW);
  digitalWrite(7, LOW);
  digitalWrite(9, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
}

void count(int num, int unit) {
  for(int i = 0; i <= num; i++) {
    if((i & 1) == 1) {
      digitalWrite(2, HIGH);
    }
    if((i & 2) == 2) {
      digitalWrite(3, HIGH);
    }
    if((i & 4) == 4) {
      digitalWrite(5, HIGH);
    }
    if ((i & 8) == 8) {
      digitalWrite(7, HIGH);
    }
    if((i & 16) == 16) {
      digitalWrite(9, HIGH);
    }
    if ((i & 32) == 32) {
      digitalWrite(11, HIGH);
    }
    if ((i & 64) == 64) {
      digitalWrite(12, HIGH);
    }
    if((i & 128) == 128) {
      digitalWrite(13, HIGH);
    }
    delay(unit);
    shutdown();
    delay(unit);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  count(255, 300);
}
