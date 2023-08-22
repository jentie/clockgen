/*
  tiny-fast - study fast switching with ATtiny  

  2023-08-21, initial version

  infos:
  https://www.heise.de/blog/Winzling-gang-gross-3329007.html
  https://wolles-elektronikkiste.de/attiny-mit-arduino-code-programmieren
  https://roboticsbackend.com/arduino-fast-digitalwrite/

  note:
  Digispark uses 3/4, not used here

  using programmer:
  * board - select ATtiny25/45/85 (no bootloader)
  * select clock 16.5 MHz (pll, tweaked)
  * burn bootloader (--> only to set clock)
  * compile sketch
  * upload: use "sketch" --> "upload using programmer" 

  result:
  * 8 MHz (intenal):          432 kHz / 2.31 us
  * 16,5 MHz (pll, tweaked):  842 kHz / 1.19 us 

*/


const int Sel = 1;  // select low/high frequency
const int Out = 0;  // output, clock signal

const byte portb0 = B00000001;  // Port B, Pin0 equals Out


int half = 1;  // period/2
               // us --> largest value: 16383


void setup() {
  pinMode(Sel, INPUT_PULLUP);  // defined state with open input
  pinMode(Out, OUTPUT);
}



void loop_us() {   // fast clock, highest frequency
  half = 1;        // shortest delay
  noInterrupts();  // disable interrupts, just loop
  while (1) {
    PORTB = PORTB | B00000001;  // fast port manipulation
    delayMicroseconds(half);
    PORTB = PORTB & B11111110;
    delayMicroseconds(half);
  }
}


void loop_ms() {  // slow clock, visible blinking
  half = 500;     // real frequency depends on clock
  while (1) {
    if (digitalRead(Sel))  // still change to fast clock
      loop_us();
    digitalWrite(Out, HIGH);
    delay(half);
    digitalWrite(Out, LOW);
    delay(half);
  }
}


void loop() {
  if (digitalRead(Sel))
    loop_us();
  else
    loop_ms();
}
