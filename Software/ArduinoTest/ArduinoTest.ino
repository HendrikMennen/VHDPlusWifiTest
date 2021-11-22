//Bibliotheken für die Kommunikation mit WiFi Geräten
#include "vhdplus_remote.h"
#include <GDBStub.h>

const char* ssid = "TEAM"; //SSID aus dem Router
const char* password = "59916301587616164123"; //Passwort für den Zugang zum WLAN

VHDPlusRemote remote;

void setup() {
    Serial.begin(19200);
    gdbstub_init();
    delay(10);
    
    Serial.print("\nConnect to ");
    Serial.println(ssid);

    remote.begin(ssid, password);

    remote.onButtonHandler(&onButton);
    remote.onSwitchHandler(&onSwitch);
    remote.onSliderHandler(&onSlider);
    remote.onConsoleHandler(&onConsole);

    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
}

bool led = false;
long l = 0;

void loop(){
    remote.run();
}

void onEvent(char type, String hook){
    Serial.println(type + " " + hook);
}

void onButton(String hook){
    Serial.println("Button " + hook);
}

void onSwitch(String hook, bool value){
    Serial.println("Switch " + hook + " " + value);
}

void onSlider(String hook, int value){
    Serial.println("Slider " + hook + " " + value);
}

String onConsole(String hook, String value){
    Serial.println("Console " + hook + " " + value);
    return value;
}

