#pragma once

#include <string>
#include <iostream>
#include <unordered_map>

#include "Player.h"
#include "Room.h"
#include "Cords.h"

using CommandName = std::string;


struct World
{
    Player & player;
    std::unordered_map<Cords, Room, CordsHasher> & map;
    Room * room = nullptr;
};


bool N(World &);
bool E(World &);
bool S(World &);
bool W(World &);

bool EQ(World &);

bool SHOP(World &);
const std::unordered_map<CommandName, bool (*)(World &)> cmd
{
{"N",N},
{"E",E},
{"S",S},
{"W",W},
{"EQ",EQ},
{"SHOP",SHOP},
};



