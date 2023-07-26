#include <SoftwareSerial.h>
#include "WString.h"

SoftwareSerial uartSerial(A0, A1);

void Uart::SendCommand(){

  //Take the command string form ESP8266

  String command;

  if (uartSerial.available()) command = uartSerial.read(command);

  return command;
}

void Uart::StartUart(){

  //Begin the serail communucation with other arduino

  uartSerial.begin(9600);
}