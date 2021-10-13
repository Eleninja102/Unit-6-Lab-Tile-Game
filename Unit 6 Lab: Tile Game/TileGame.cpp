#include <sstream>
#include <string>
#include <iostream>
#include "TileGame.h"
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
using namespace std;

TileGame::TileGame()
{
    //Assign each item in the array to the value of the index
    for(int i = 0; i < 10; i++)
    {
      tiles[i] = i;
        //cout << tiles[i]<<endl;
    }

    //TODO: Mix the positions up
    for(int i = 0; i < 10; i++)
    {
        //usleep(1000000);

        srand ((unsigned int)time(NULL));
        int z = rand() % (10-i);
        int c = rand() % (10-i);
        //cout << z << endl;
        int x = tiles[c];
        int y = tiles[z];
        tiles[c] = y;
        tiles[z] = x;
        //cout << tiles[z];
        

    }
}

int TileGame::findZero()
{
    //TODO Return the position of the Zero
    for(int i = 0; i < 10; i++){
        if(tiles[i] == 0){
            return i;
        
        }
    }
    return NULL;
}

void TileGame:: moveRight()
{
    int zero = findZero();
    
    int x = tiles[zero];
    int y = tiles[zero-1];
    tiles[zero] = y;
    tiles[zero-1] = x;
  //TODO:  Swap the value to the left of the zero with the zero
  //Use the variable zero as the index of the zero


}
void TileGame::moveLeft()
{
    int zero = findZero();
    int x = tiles[zero];
    int y = tiles[zero+1];
    tiles[zero] = y;
    tiles[zero+1] = x;
    
      return;
    //TODO:  Swap the value to the right of the zero with the zero
    //Use the variable zero as the index of the zero
}

void TileGame::swap()
{
    int zero = findZero();  
    int x = tiles[zero-1];
    int y = tiles[zero+1];
    tiles[zero-1] = y;
    tiles[zero+1] = x;
    //TODO:  Swap the values on Eithor Side of the 0
    //Use the variable zero as the index of the zero
}

bool TileGame::inOrder()
{
    //TODO: Check to see if the game is in order.
    for(int i = 0; i < 10; i++)
    {
        if(tiles[i] != i){
            return false;
        }
    }
    
    return true;
}


//Returns the game as a string for display 
string TileGame::getDisplay()
{
  stringstream output;
  for(int i = 0; i < 10; i++)
  {
    if(tiles[i]>0)
      output << "[" << tiles[i] << "]" << " ";
    else
      output << "[ ]" << " ";
  }
  return output.str();
}
