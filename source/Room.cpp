//
// Created by Pawel on 28.02.2023.
//

#include "Room.h"
 std::ostream & operator<<(std::ostream & os, const Room & r)
{
    os<<"\""<<r.name<<"\""<<std::endl;
    os<<"'"<<r.description<<"'"<<std::endl;

    os<<"> ";
    for( const std::string &d : r.exits)
    {
        os<<d<<" ";
    }
    os<<std::endl;
    return os;
}