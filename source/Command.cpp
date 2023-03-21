//
// Created by Pawel on 19.03.2023.
//

#include "Command.h"
bool N(World & w)
{
    w.player.move(0,1);
    return true;
}

bool E(World & w)
{
    w.player.move(1, 0);
    return true;
}

bool S(World & w)
{
    w.player.move(0,-1);
    return true;
}

bool W(World & w)
{
    w.player.move(-1, 0);
    return true;
}

bool EQ(World &)
{
   std::cout<<"Showing Player Equipment"<<std::endl;
    return true;
}

bool SHOP(World &)
{
   std::cout<<"Showing SHOP"<<std::endl;
    return true;
}