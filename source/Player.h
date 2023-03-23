#pragma once

#include <vector>
#include <string>

#include "Cords.h"

class Player {
private:
    Cords position;                                                  // current room coordinates
    //int hp;
    std::vector<std::string> commands{"EQ"};                              // Player commands showeq, showskills etc.
public:
    Player(const Cords & pos): position(pos){}
    Cords getPos()const { return position; }            // get position
    const std::vector<std::string> & getCmds()const { return commands; }
    void move(const int & x, const int & y)                         // move player
    {
        position = {position[0] + x, position[1] + y};
    }



};



