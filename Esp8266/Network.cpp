#include "Network.h"
#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>
#include <HardwareSerial.h>
#include "WString.h"
#include <Arduino.h>

#define FirebaseId "***************************"
#define FirebaseToken "*******************************"
#define WifiId "**************************"
#define WifiPass "************************"

FirebaseData Database;

String commandList[] = {"/room1Light1", "/room1Light2", "room1RGB", "room2Window", "room2Light", "room2Fan"};

String Network::TakeCommand(){

  //Take all data from database and ready to send 

  String workList;

  String data;

  for(int i = 0;  i < sizeof(commandList); i++){

    if(Firebase.getString(Database, commandList[i])){

    data = Database.stringData();

    workList += commandList[i] + data;
  }

  return workList;
}

void Network::ConnectInternet(){

  //Connect and check web connection

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting Wifi");

  while (WiFi.status() != WL_CONNECTED){

    Serial.print(".");
    delay(300);
  }

  Serial.println();
  Serial.print("Connected to IP adress: ");
  Serial.println(WiFi.localIP());
  Serial.println();
}

void Network::ConnectDatabase(){

  //Connect and check systems realtime database
  
  Firebase.begin(FirebaseId, FirebaseToken);
  Firebase.reconnectWiFi(true);
}