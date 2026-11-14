int var = 0;
float voltage = 0;

void setup() {
  // put your setup code here, to run once:
    pinMode(A4, INPUT);
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    var = analogRead(A4);
    voltage = (5./1023.)*var;
    Serial.print(voltage);
    Serial.println(" volts");
    delay(1000);
}
