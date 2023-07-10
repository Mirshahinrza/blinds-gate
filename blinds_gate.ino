#include "thingProperties.h"


#define gate1pin 12
#define gate2pin 14

unsigned long current_time = 0;
unsigned long previous_time = 0;
unsigned long previous_time2 = 0;
int  interval = 1000;
int  interval2 = 500;
bool gate1_relay  = false ;
bool gate2_relay  = false ;
int n = 0;

void setup() {



  Serial.begin(9600);
  delay(500);



  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();



  pinMode(gate1pin, OUTPUT);
  pinMode(gate2pin, OUTPUT);
  digitalWrite(gate1pin, LOW);
  digitalWrite(gate2pin, LOW);

}

void loop() {
  ArduinoCloud.update();
  current_time = millis();

  switch (n) {
    case 1: //Open
      digitalWrite(gate1pin, HIGH);
      Serial.println("Opening");
      message = "Opening";
      break;

    case 3: //Close
      digitalWrite(gate2pin, HIGH);
      Serial.println("Closing");
      message = "Closing";
      break;
    case 2: //Stop
    case 4: //Stop
      digitalWrite(gate1pin, LOW);
      digitalWrite(gate2pin, LOW);
      Serial.println("Stopped");
      message = "Stopped";
      break;

  }
  if ( n == 4) {
    n = 0;
  }
}

void onGate1Change()  {
  if (gate1 == 1) {
    n = n + 1;
    Serial.println(n);
    message = n;
  }
}

void onGate2Change()  {
}
void onMessageChange()  {

}
