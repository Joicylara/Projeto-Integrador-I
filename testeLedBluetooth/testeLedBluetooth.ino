#include <SoftwareSerial.h>

#define led1 6
#define led2 7

SoftwareSerial bt_serial(11, 12);//RX(TX no módulo) e TX (RX no módulo) 

void setup() {
  bt_serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);


}

void loop() {
  char c = bt_serial.read();
  if(c == 'A'){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  }
  if(c == 'a'){
    digitalWrite(led2, HIGH);
    digitalWrite(led1,LOW);
  }
  I

}
