const int PIN = A0;
const int R1 = 1000;
const int R2 = 560;
int pin_reading;
float pin_voltage;

float voltage(int reading) {
  return reading*(5.0/1023.0);
}

float current(float U, float R){
  return U*1000/R;
}

void setup() {

  Serial.begin(9600);

}

void loop() {
  
  pin_reading = analogRead(PIN);
  pin_voltage = voltage(pin_reading);


  Serial.println(pin_voltage);
  Serial.println("Voltage: " + String(pin_voltage, 3) + " V, Current: " + String(current(pin_voltage, R2), 2));
  delay(500);

}
