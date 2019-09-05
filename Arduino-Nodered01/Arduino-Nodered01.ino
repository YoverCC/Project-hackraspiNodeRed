void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  float V = 5.0;
  float I = V/330;
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.print("Voltaje: ");
  Serial.print(V);
  Serial.print(", Corriente: ");
  Serial.println(I);
  delay(1000);

  V = 0.0;
  I = V/330;
  digitalWrite(LED_BUILTIN, LOW);
  Serial.print("Voltaje: ");
  Serial.print(V);
  Serial.print(", Corriente: ");
  Serial.println(I);
  delay(1000);
}
