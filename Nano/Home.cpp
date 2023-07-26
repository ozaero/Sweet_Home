#include "WString.h"
#include <string.h>
#include "Arduino.h"
#include "Home.h"

#define room1Light1 3
#define room1Light2 4
#define red 9
#define green 10
#define blue 11
#define room2WindowEn 5
#define room2WindowDir 6
#define room2Light 7
#define room2Fan 8
#define windowSwitch 12


void Home::ManageHome(String* commandList){

  //Separated command progress

  for(int i = 0; i < sizeof(commandList); i++){

    if(commandList[i] == "room1Light10") digitalWrite(room1Light1, LOW);
    else if(commandList[i] == "room1Light11") digitalWrite(room1Light1, HIGH);

    if(commandList[i] == "room1Light20") digitalWrite(room1Light2, LOW);
    else if(commandList[i] == "room1Light21") digitalWrite(room1Light2, HIGH);

    if(commandList[i] == "room2Window0") MoveWindow(false);
    else if(commandList[i] == "room2Window1") MoveWindow(true);

    if(commandList[i] == "room2Fan0") digitalWrite(room2Fan, LOW);
    else if(commandList[i] == "room2Fan1") digitalWrite(room2Fan, HIGH);

    if(commandList[i] == "room1RGB0") ChangeColour(0);
    else if(commandList[i] == "room1RGB1") ChangeColour(1);
    else if(commandList[i] == "room1RGB2") ChangeColour(2);
    else if(commandList[i] == "room1RGB3") ChangeColour(3);
    else if(commandList[i] == "room1RGB4") ChangeColour(4);
    else if(commandList[i] == "room1RGB5") ChangeColour(5);
    else if(commandList[i] == "room1RGB6") ChangeColour(6);
    else if(commandList[i] == "room1RGB7") ChangeColour(7);
  }
}

void Home::ChangeColour(int colour){

  //Set colour of RGB ligth or make it on/off

  switch (colour) {

    case 0:
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
    break;

    case 1:
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
    break;

    case 2:
    digitalWrite(red, HIGH);
    digitalWrite(green, HIGH);
    digitalWrite(blue, LOW);
    break;

    case 3:
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(blue, LOW);
    break;

    case 4:
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(blue, HIGH);
    break;

    case 5:
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, HIGH);
    break;

    case 6:
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(blue, HIGH);
    break;

    case 7:
    digitalWrite(red, HIGH);
    digitalWrite(green, HIGH);
    digitalWrite(blue, HIGH);
    break;
  }
}

void Home::MoveWindow(bool move){

  //Close or open window until the limit switch pressed

  bool isDone;

  if(digitalRead(windowSwitch)) isDone = true;
  else isDone = false;

  if(!isDone){

    if(!move) digitalWrite(room2WindowDir, LOW);
    else digitalWrite(room2WindowDir, HIGH);
  }
}

String* Home::TakeCommand(String command){

  //This function separates command string for which componenet what will do

  String commandList[6];
  
  int count = 0;

  for(int i = 1; i < sizeof(command); i++){

    if(command[i] == "/"){

      count++;
      continue;
    }

    commandList[count] += command[i];
  }

  return commandList;
}

void Home::StartHome(){

  //Set the pins to work

  for (int i = 3; i < 12; i++) pinMode(i, OUTPUT);

  pinMode(windowSwitch, INPUT);
}