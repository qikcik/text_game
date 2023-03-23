#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "Cords.h"


class Room {
private:
    std::string name;                    // name of room
    std::string description;             // description of room
    std::vector<std::string> exits;      // possible movement directions
    std::vector<std::string> commands;   // items and characters in room
    bool isOpen{true};                   // true if you can enter the room

public:
    Room(const std::string & nm, const std::string & desc, const std::vector<std::string> & ext, const std::vector<std::string> & cmds = {})
    : name{nm}, description{desc}, exits(ext), commands(cmds){}

    std::string getName()const { return name; }                               // get name
    std::string getDesc()const { return description; }                        // get description
    const std::vector<std::string> & getExits()const { return exits; }        // get exits symbols
    const std::vector<std::string> & getCmds()const { return commands; }
    friend std::ostream & operator<<(std::ostream & os, const Room & r);

};


