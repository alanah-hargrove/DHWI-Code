/*
  TinyCircuits Microphone Wireling Example Sketch
  
  This sketch reads the analog value output by the
  microphone based on the volume of sound it receives. The
  best way to see data is via the Serial Plotter. A simple
  test can be done by speaking at a normal volume, clapping,
  or blowing gently into the microphone and looking at the
  data on screen.

  Written 15 July 2019
  By Hunter Hykes
  Modified N/A
  By N/A

  https://TinyCircuits.com
*/

#if defined (ARDUINO_ARCH_AVR)
#define SerialMonitorInterface Serial
#elif defined(ARDUINO_ARCH_SAMD)
#define SerialMonitorInterface SerialUSB
#endif

float micPin = A0; // use port 0
float value = 0.0;

void setup() {
  SerialMonitorInterface.begin(9600);
  while (!SerialMonitorInterface); // must open Serial Monitor to execute following code

  delay(100);
}
int value2 = 0;
void loop() {
  value = analogRead(micPin);  // read the input pin
  SerialMonitorInterface.println(value-value2);  // print value
  delay(10);
  value2 = value;
}
