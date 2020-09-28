#include <sx_pro.h>

SXPro module = SXPro(9, false);

void readParam(char *param) {
    Serial.print(param);
    Serial.print(": ");
    Serial.println(module.readParam(param));
}

void setup() {
    Serial.begin(9600);
    Serial2.begin(9600);

    module.begin(Serial2);

    if (module.enterCommandMode()) {
        Serial.println("Entered command mode.");
        module.reset();
        delay(2000);
        readParam("AF");
        readParam("ID");
        readParam("BR");
        readParam("PL");
        readParam("NI");
        module.setParam("NI", "Baja Vehicle");
        module.setParam("ID", "2015");
        readParam("NI");
        readParam("ID");
        if (module.exitCommandMode())
            Serial.println("Exited command mode.");
    }

    Serial.println("Done.");
}

// This enters transparent mode, allows us to send AT commands directly.
void loop() {
    if (Serial.available()) { // If anything comes in Serial (USB),

        Serial2.write(Serial.read()); // read it and send it out Serial1 (pins 0 & 1)
    }

    if (Serial2.available()) { // If anything comes in Serial1 (pins 0 & 1)

        Serial.write(Serial2.read()); // read it and send it out Serial (USB)
    }
}
