const int PIN = A0;
const int R1 = 1000;
const int R2 = 560;
int pin_reading;
float pin_voltage;
float pin_current;

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
  
  // getting values
  //Voltage 
  pin_reading = analogRead(PIN);
  pin_voltage = voltage(pin_reading);
  //Current
  pin_current = current(pin_voltage, R2)

  // print to console
  Serial.println("Voltage: " + String(pin_voltage, 3) + " V, Current: " + String(pin_current, 2) + " mA");
  delay(500);

}
