#include <ATcommands.h>

ATcommands module = ATcommands(9, false); // Use "false" if you don't want AT commands with newline, "true" otherwise

void getReply() {
  String reply = Serial2.readStringUntil('\r');
  Serial.println(reply);
}

void setup() {
  Serial.begin(9600);
  Serial2.begin(9600);

  module.begin(Serial2);

  delay(1000);

  if (module.sendCommand("+++", "OK", 2000)) {
    Serial.println("Entered command mode.");
    module.sendCommand("ATAF\r");
    getReply();
    module.sendCommand("ATID\r");
    getReply();
    module.sendCommand("ATBR\r");
    getReply();
    module.sendCommand("ATPL\r");
    getReply();
    module.sendCommand("ATNI\r");
    getReply();
  }
}

//bool waitForOK() {
//  while(!Serial2.available()) {} //Wait for response.
//  uint8_t buf[3];
//  Serial2.readBytes(buf, 2);
//  buf[3] = '\0';
//  Serial.write(buf, 2);
//
//  if (buf[0] == 'O' && buf[1] == 'K')
//    return true;
//  else return false;
//}

void loop() {
//   if (waitForOK()) {
//      Serial.println("Received OK from RF module.");
//   } else {
//      Serial.println("Did not receive OK from RF module.");
//   }
//
  if (Serial.available()) {      // If anything comes in Serial (USB),

    Serial2.write(Serial.read());   // read it and send it out Serial1 (pins 0 & 1)

  }

  if (Serial2.available()) {     // If anything comes in Serial1 (pins 0 & 1)

    Serial.write(Serial2.read());   // read it and send it out Serial (USB)

  }
}
