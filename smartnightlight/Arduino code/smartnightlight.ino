#include <Adafruit_NeoPixel.h>

#define NUMPIXELS 8
#define PIN 6   // choose the output pin (for LED light)
#define PIR 2   // choose the input pin (for PIR sensor)
  
Adafruit_NeoPixel pixels(NUMPIXELS, PIN);
void setup()
{
  Serial.begin(9600);
  pinMode(PIN, OUTPUT); // declare pin as output
  pinMode(PIR,INPUT); // declare sensor as input 
  pixels.begin();                                                                                                                          
}

void loop() {
  int valeur_ldr = analogRead(A4); // read LDR value
  int valeur_pir = digitalRead(PIR); // read input value
  Serial.println(valeur_ldr);
  Serial.println(valeur_pir);
  
 if((100>valeur_ldr) && ( valeur_pir==HIGH) ){
      pixels.clear();
      for(int i=0; i<NUMPIXELS; i++) {
        pixels.setPixelColor(i, 255, 255, 255);
        pixels.show();
      }
       delay(15000);
  }
 else {
      pixels.clear();
      pixels.show();
      
       
 }
}
