#include <Arduino.h>

int inputPin = A0;
int outputPin = 9;

void setup() {
    Serial.begin(115200);

    pinMode(inputPin, INPUT);
    pinMode(outputPin, OUTPUT);
}

void loop() {
    int isOn = digitalRead(inputPin);
    Serial.print("Healthcheck... ");
    Serial.println(isOn == HIGH ? "ON" : "OFF");

    if (isOn == LOW)
    {
        delay(5000);
        Serial.println("Server is OFF, sending digitalWrite");
        digitalWrite(outputPin, HIGH);
        delay(1000);
        digitalWrite(outputPin, LOW);
    }

    delay(5000);
}
