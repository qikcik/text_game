//
// Created by Pawel on 19.03.2023.
//

#ifndef TEXT_GAME_COMMAND_H
#define TEXT_GAME_COMMAND_H

#include <string>
#include <iostream>
#include <unordered_map>
#include "Player.h"
#include "Room.h"


struct World
{
    Player & player;
    std::unordered_map<std::array<int,2>, Room, ArrayHasher> & map;
    Room * room = nullptr;
};


bool N(World &);
bool E(World &);
bool S(World &);
bool W(World &);

bool EQ(World &);

bool SHOP(World &);
const std::unordered_map<std::string, bool (*)(World &)> cmd
{
{"N",N},
{"E",E},
{"S",S},
{"W",W},
{"EQ",EQ},
{"SHOP",SHOP},
};


#endif //TEXT_GAME_COMMAND_H