#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>

#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";


// I2C
Adafruit_LIS3DH lis = Adafruit_LIS3DH();

#if defined(ARDUINO_ARCH_SAMD)
   #define Serial SerialUSB
#endif

void setup(void) {
#ifndef ESP8266
  while (!Serial);
#endif

  Serial.begin(9600);
  Serial.println("LIS3DH test!");
  
  if (! lis.begin(0x18)) {
    Serial.println("Couldnt start");
    while (1);
  }
  Serial.println("LIS3DH found!");
  
  lis.setRange(LIS3DH_RANGE_16_G); 
  
  Serial.print("Range = "); Serial.print(2 << lis.getRange());  
  Serial.println("G");

  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}


void loop() {
  lis.read(); 
  Serial.print("X:  "); Serial.println(lis.x); 
  Serial.print("  \tY:  "); Serial.println(lis.y); 
  
  volatile int text;
  
  //Stop
  if(lis.x<300 && lis.x>-300 && lis.y<300 && lis.y>-300){
    text= 2000;
    radio.write(&text, sizeof(text));
    Serial.println(text);
    }
    
  //right
  else if(lis.x>=300){
    text= 2002;
    Serial.println(text);
    radio.write(&text, sizeof(text));
    }
    
  //left
  else if(lis.x<=-300){
    text= 2020;
    radio.write(&text, sizeof(text));
    }
    
  //forward
  else if(lis.y>=300){
    text= 2200;
    radio.write(&text, sizeof(text));
    }
    
  //backwards
  else if(lis.y<=-300){
    text= 1200;
    radio.write(&text, sizeof(text));
    Serial.println(text);
    }
    
  else{
    text= 2000;
    radio.write(&text, sizeof(text));
      }
}
