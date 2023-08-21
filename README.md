# clockgen - adjustable / programable clock generator


Features:
* based on ATtiny25/45/85
* 8 pin, footprint similar to crystal oscillators
* select input: change between low and high frequency range
* adjust can use analog input, steps between HIGH and LOW possible
* package includes simple programming schematic 


(todo: picture programming adapter)


Pinout:

     Vcc Adj Sel Out 
      |   |   |   |
    +-+---+---+---+-+
    |               |
    >     ATtiny    |    *nc - not conneted / used
    | 1             |
    +-+---+---+---+-+
      |   |   |   |
     Res nc* nc* GND  


### source codes, Arduino IDE: ###
* tiny-blink - hello world
* tiny-fast - fast switching of digital output
* tiny-clock - clock generator


### Notes: ###
* IC Pin 2,3 (Arduino 3,4) not used (Digispark USB interface)
* program with fastest internal clock:
  * board - select ATtiny25/45/85 (no bootloader)
  * select clock 16.5 MHz (pll, tweaked)
  * burn bootloader (--> only to set clock)
  * compile sketch
  * upload: use "sketch" --> "upload using programmer" 
  

### References: ###
* https://www.heise.de/blog/Winzling-gang-gross-3329007.html
* https://roboticsbackend.com/arduino-fast-digitalwrite/


### Licence: CC0 1.0 Universal ###
