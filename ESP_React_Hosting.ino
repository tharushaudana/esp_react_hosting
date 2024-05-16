/*
#################################
Install LittleFS: https://randomnerdtutorials.com/arduino-ide-2-install-esp32-littlefs/
#################################
*/

#ifdef ESP32
#include <WiFi.h>
#include <AsyncTCP.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#endif
#include <ESPAsyncWebServer.h>
#include "LittleFS.h"

#define SSID "Tharusha"
#define PASS "abc12345"

AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);
  init_wifi();
  init_littlefs();
  init_webserver();
}

void loop() {
  // put your main code here, to run repeatedly:
}

void init_webserver() {
  Serial.println(">>> [SERVER]: Setting up...");

  //#################### [Your other routes here] ####################

  server.on("/test", HTTP_GET, [](AsyncWebServerRequest *req) {
    req->send(200, "text/plain", "this is test route...");
  });

  //##################################################################

  handle_react(&server);
  
  server.begin();

  Serial.println(">>> [SERVER]: Successfully started.");
}

void init_littlefs() {
  if(!LittleFS.begin()) {
    Serial.println(">>> [LittleFS]: An Error has occurred while mounting SPIFFS !!!");
    return;
  }

  Serial.println(">>> [LittleFS]: Initialized.");
  	
  //Serial.println(LittleFS.exists("/index.html"));
}

void init_wifi() {
  WiFi.mode(WIFI_AP_STA);
  WiFi.begin(SSID, PASS);

  Serial.println();
  Serial.print(">>> [WiFi]: Connecting to WiFi ..");

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }

  Serial.println();
  Serial.print(">>> [WiFi]: IP = ");
  Serial.println(WiFi.localIP());
}