/*
  tiny-clock - first program for ATtiny  

  2023-08-11, initial version

  info:
  https://www.heise.de/blog/Winzling-gang-gross-3329007.html
  https://wolles-elektronikkiste.de/attiny-mit-arduino-code-programmieren
  https://roboticsbackend.com/arduino-fast-digitalwrite/

  Digispark uses 3/4, not used here

*/

// const int Sel = 1;   // select low/high frequency
// const int Out = 0;   // output, clock signal
const int Sel = 1;   // select low/high frequency
const int Out = 0;   // output, clock signal
const int Adj = A1;  // adjust frequency


int step;
int half = 1;  // period/2
               // largest value: 16383 us



void setup() {

  pinMode(Sel, INPUT_PULLUP);
  pinMode(Out, OUTPUT);

  step = analogRead(Adj) / 32;  // 0...1023 -> 0..31

  half = 1 + (step * 128);
}


void loop_ms() {
  while (1) {

    step = analogRead(Adj) / 32;  // 0...1023 -> 0..31
    half = 1 + (step * 64);

    digitalWrite(Out, HIGH);
    delay(half);
    digitalWrite(Out, LOW);
    delay(half);
  }
}


void loop_us() {
  while (1) {
    digitalWrite(Out, HIGH);
    delayMicroseconds(half);
    digitalWrite(Out, LOW);
    delayMicroseconds(half);
  }
}


void loop() {
  if (digitalRead(Sel))
    loop_us();
  else
    loop_ms();
}
