#include "glacier_defines.h"

#include <array>

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Arduino.h>

#include <Sensor/SensorIR.h>
#include <IR/IRTransmitter.h>


glacier::ir::IRTransmitter IR;


void serialPrint(String message) {
    #ifdef DEBUG
    Serial.println(message);
    #endif // DEBUG
}

void connect()
{
    WiFi.mode(WIFI_STA);
    bool success = false;

    serialPrint("Connecting...");

    long start_time = millis();
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(10);
        if (((millis() - start_time) > MINUTE) && !success)
        {
            WiFi.beginSmartConfig();
            serialPrint("Begin SmartConfig...");
            while (1)
            {
                delay(10);
                if (WiFi.smartConfigDone())
                {
                    serialPrint("SmartConfig: Success");
                    success = true;
                    break;
                }
                if ((millis() - start_time) > (MINUTE * 2))
                {
                    ESP.restart();
                }
            }
        }
    }

    serialPrint("WiFi Connected.");
    WiFi.printDiag(Serial);
    serialPrint(WiFi.localIP().toString().c_str());
    serialPrint(WiFi.gatewayIP().toString().c_str());
    serialPrint(WiFi.hostname().c_str());
}


void setup() {
    Serial.begin(9600);

    WiFi.setAutoConnect(true);
    WiFi.setAutoReconnect(true);
    connect();

    IR.begin();
    Serial.println("--------");
    Serial.println(IR.saz);
    Serial.println(IR.sf);
    Serial.println("xxxxxxxxx");
}

void loop() {
    IR.powerOn();
    serialPrint("on");
    delay(1000 * 10);
    IR.powerOff();
    serialPrint("off");
    delay(1000 * 10);
}
