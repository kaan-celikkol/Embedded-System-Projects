const int sensorPin = A0;
const int buzzerPin = 8;
const int ledPin = 9;

void setup() {
  Serial.begin(9600);
  pinMode (buzzerPin, OUTPUT);
  pinMode (ledPin, OUTPUT);
}

void loop() 
{
  int sensorValue = analogRead(sensorPin);
  float voltage = sensorValue * (5.0 / 1024.0);
  float temperature = voltage * 100.0; // LM35: 10mV = 1°C
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");
  const float TEMP_MAX = 30.0;
  if (temperature > TEMP_MAX)
  {
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
   } 
  else 
    {
      digitalWrite(buzzerPin, LOW);
      digitalWrite(ledPin, LOW);
    }
  delay(500);
}
