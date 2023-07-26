#include "Network.h"
#include "Uart.h"

Network Network;
Uart Uart;

String dataCluster;

void setup() {

  Parameter();
}

void loop(){

  dataCluster = Network.TakeCommand();
  Uart.SendCommand(String dataCluster)
}

void Parameter(){

  Network.ConnectInternet();
  Network.ConnectDatabase();
  Uart.StartUart();
}
