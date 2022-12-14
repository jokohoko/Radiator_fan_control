#include <OneWire.h>
#include <DS18B20_INT.h>

#define ONE_WIRE_BUS    8
#define output          9

OneWire     oneWire(ONE_WIRE_BUS);
DS18B20_INT sensor(&oneWire);

void setup() {
  // put your setup code here, to run once
  sensor.begin();
  Serial.begin(9600);
  pinMode(output, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.println("start");
}

void loop() {
  // put your main code here, to run repeatedly:
  sensor.requestTemperatures();

  while (!sensor.isConversionComplete());  // (BLOCKING!!) wait until sensor is ready
  Serial.println(sensor.getTempC());
  if (sensor.getTempC() > 25) {
    digitalWrite(output, HIGH);
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(output, LOW);
    digitalWrite(13, LOW);
  }
  delay(5000);
}
