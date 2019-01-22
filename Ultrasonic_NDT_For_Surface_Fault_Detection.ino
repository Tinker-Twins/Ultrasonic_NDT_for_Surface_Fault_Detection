// HC-SR04 produces 40kHz ultrasound, whose wavelength in air is ~0.85cm and such a low frequency will not be able to detect a fault unless its size is comparable to the wavelength.

int Trigger = 12;
int Echo = 11;
int LED = 13;
int Buzzer = 8;
long t = 0, newSignal = 0, oldSignal = 0; 

void setup()
{
Serial.begin(9600);
pinMode(Trigger, OUTPUT);
pinMode(Echo, INPUT);
pinMode(LED, OUTPUT);
pinMode(Buzzer, OUTPUT);
}

void loop()
{
digitalWrite(Trigger, LOW);       // Transmitting Pulse
delayMicroseconds(2);
digitalWrite(Trigger, HIGH);
delayMicroseconds(10);
digitalWrite(Trigger, LOW);
t = pulseIn(Echo, HIGH);          // Waiting for Pulse
newSignal = (t/2) / 29.1;         // Calculating Distance
Serial.print(newSignal);
Serial.print(" cm\n");
if((newSignal - oldSignal) >= 500){
  digitalWrite(LED, HIGH);
  digitalWrite(Buzzer, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  digitalWrite(Buzzer, LOW);
}
oldSignal = newSignal;
}
