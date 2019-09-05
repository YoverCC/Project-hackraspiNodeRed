int k = 0; // Discretizando las funciones trigonométricas a ser enviadas
static float pi = 3.1416;
int value = 0;
int sensorPin = A2;
int sensorValue = 0;
int pot = 0;
float seno = 0;
float coseno = 0;
int N = 50;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  
}

void loop() {

  sensorValue = analogRead(sensorPin);
  pot = sensorValue*100/1024;
  seno = sin(2*pi*k/N);
  coseno = cos(2*pi*k/N);
  Serial.print(" sin: ");
  Serial.print(seno);
  Serial.print(" ,cos: ");
  Serial.print(coseno);
  Serial.print(" ,Potenciometro: ");
  Serial.println(pot);
  
  k = k+1;


  if(Serial.available())
  {
    int valueread = Serial.parseInt(); // Esta en porcentaje [0 a 100]
    value = valueread*4094/100;
    // Los valores aceptados son de 0 a 4095
    if (value < 0){
      value = 0;
      }
    if (value > 4094){
      value = 4094;
      }
    }
  analogWriteResolution(12);
  analogWrite(DAC1,value);
  delay(200);
}
