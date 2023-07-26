#include "Uart.h"
#include "Home.h"

Uart Uart;
Home Home;

void setup() {
  
  Parameter();
}

void loop() {

  //From Esp8266 command send to progress

  String command = Uart.TakeCommand();
  Home.TakeCommand(command);
}

void Parameter(){

  //Start the componenets and serial communucation

  Uart.StartUart();
  Home.StartHome();
}
