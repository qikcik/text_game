//
// Created by Pawel on 28.02.2023.
//

#ifndef TEXT_GAME_PLAYER_H
#define TEXT_GAME_PLAYER_H

#include <array>
#include <vector>
#include <string>


class Player {
private:
     std::array<int,2> position;                                    // room coordinates
    //int hp;
    std::vector<std::string> commands{"EQ"};                              // Player commands showeq, showskills etc.
public:
    Player(const std::array<int,2> & pos): position(pos){}
    std::array<int,2> getPos()const { return position; }            // get position
    const std::vector<std::string> & getCmds()const { return commands; }
    void move(const int & x, const int & y)                         // move player
    {
        position = {position[0] + x, position[1] + y};
    }



};


#endif //TEXT_GAME_PLAYER_H
