#include <Arduino.h>

void setup() {
  Serial.begin(115200);

  // TODO: setup MCP23017

  // TODO: setup e-paper panel
}

void loop() {
  Serial.println("Hello World");
  delay(1000);
  // TODO: read buttons

  // TODO: draw on e-paper panel
}