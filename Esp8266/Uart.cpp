#include "WString.h"
#include <SoftwareSerial.h>

SoftwareSerial uartSerial(A1, A0);

void Uart::SendCommandCommand(String command){

  //Send the command  string to arduino

  if (uartSerial.available()) uartSerial.print(command);
}

void Uart::StartUart(){

  //Begin the serail communucation with other arduino

  uartSerial.begin(9600);
}