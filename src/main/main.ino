#define SOLENOID1 2
#define SOLENOID2 3

void setup() {
  // put your setup code here, to run once:

  pinMode(SOLENOID1, OUTPUT);
  pinMode(SOLENOID2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(SOLENOID1, HIGH);
  digitalWrite(SOLENOID2, HIGH);

  delay(1000);

  digitalWrite(SOLENOID1, LOW);
  digitalWrite(SOLENOID2, LOW);

  delay(1000);

}
