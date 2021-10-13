#ifndef TILEGAME_H
#define TILEGAME_H
#include <string>
using namespace std;

class TileGame{
  public:
     TileGame();
     void moveRight();
     void moveLeft();
     void swap();
     bool inOrder();
     string getDisplay();

  private:
     int tiles[10];
     int findZero();

};

#endif