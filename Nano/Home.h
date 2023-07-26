#ifndef Home_h
#define Home_h

class Home {
  
  public:

  void StartHome();
  String* TakeCommand(String command);
  void ManageHome(String* commandList);

  private:
  
  void MoveWindow(bool move);
  void ChangeColour(int colour);
};

#endif