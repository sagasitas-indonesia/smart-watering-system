/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-soil-moisture-sensor
 */

#define AOUT_PIN 36 // ESP32 pin GIOP36 (ADC0) that connects to AOUT pin of moisture sensor

void setup() {
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(AOUT_PIN); // read the analog value from sensor

  Serial.print("Moisture value: ");
  Serial.println(value);

  delay(500);
}
