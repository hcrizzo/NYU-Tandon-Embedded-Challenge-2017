#include <nRF24L01.h>

#include <RF24.h>
#include <RF24_config.h>

#include <SPI.h>

RF24 radio(7, 8); 
const byte address[6] = "00001";

void setup()
{
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  DDRB |= 0b0000110;
  TCCR1A = 0b10100011;
  TCCR1B = 0b00001011;
}

 void fullright()
 {
   OCR1A = 600;
   OCR1B = 210;
 }
void fullbackward()
{
  OCR1A = 210;
  OCR1B = 630;
}
void fullforward()
{
  OCR1A = 633;
  OCR1B = 633;
}
void fullleft()
{
  OCR1A = 210;
  OCR1B = 600;
}
void NO()
{
  OCR1A = 400;
  OCR1B = 400;
}


void loop() {
  
  if (radio.available()) {
    volatile int text;
    radio.read(&text, sizeof(text));
    //Serial.println(sizeof(text));
    Serial.println(text);
    //OCR1A = 0;
    //OCR1B = 0;
   if (text == 2200){
      fullright();
   }
    else if (text == 1200)
      fullbackward();
    else if (text == 2020)
      fullforward();
    else if (text == 2002)
      fullleft();
    else if (text == 2000) 
      NO();
    else 
      NO();
  }
}
