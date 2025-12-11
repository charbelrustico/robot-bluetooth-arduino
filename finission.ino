#include <SoftwareSerial.h>
//SoftwareSerial Bluetooth(11, 12);
int IN1 = 2;
int IN2 = 3;
int IN3 = 4;
int IN4 = 5;
int ENA = 6;
int ENB =9;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  arret();
  

}

void loop() {
  // put your main code here, to run repeatedly:
  char command = 'o';
  if(Serial.available()){
    command = (char)Serial.read();
    if(command == 'F'){
      forware();
      }

      if(command == 'B'){
      backware();
      }

      if(command == 'L'){
      left();
      }

      if(command == 'R'){
      right();
      }

      if(command == 'S'){
      arret();
      }
    
    }

}


void forware(){

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 250);
  
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 250);
  
}

void arret(){

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
  
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
}

void backware(){

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 250);
  
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH );
  analogWrite(ENB, 250);
  
}


void left(){

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 250);
  
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
}

void right(){

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
  
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 250);
}
