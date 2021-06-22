#include <Arduino.h>

#define pinled1 13
#define entradasom 11

void setup() {
   pinMode( pinled1 , OUTPUT);
   pinMode(entradasom , INPUT);
   Serial.begin(9600);
}

void loop() {
  Serial.println(digitalRead(pinled1));
  int t = digitalRead(entradasom);
  
  if (t == 1){
    
    int p = false; 
    delay(100);
    int timer = millis()+1500;
  
    while(timer > millis()){
      int t = digitalRead(entradasom);
      if (t == 1){ 
        p = true;
      }
    }
    
    if (p == false){
      digitalWrite(pinled1,HIGH);
    }
    if (p == true){
      digitalWrite(pinled1,LOW);
    }
  }
}