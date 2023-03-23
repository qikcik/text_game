#include <iostream>
#include <unordered_map>

#include "Room.h"
#include "Player.h"
#include "Command.h"
#include "Cords.h"



int main() {

    Player player{{0, 0}};

    std::unordered_map<Cords, Room, CordsHasher> map
    {
        {{0,0},{"City", "small town", {"N","E","S","W"},{"SHOP"}}},
        {{0,1},{"Forest", "lot of trees", {"S"}}},
        {{0,-1},{"Cave", "air is very humid here", {"N"}}},
        {{1,0},{"Road", "dirt road", {"W"}}},
        {{-1,0},{"Plains", "large fields of grass", {"E"}}}

    };

    std::cout << "You wake up in small city."<<std::endl;


    const Room * room = &map.at(player.getPos());
    std::string input;

    World world{player, map, &map.at(player.getPos())};


    while (true) {
        std::cout<<*room;

        std::cout << "<Player> ";
        std::cin >> input;

        std::transform(input.begin(), input.end(), input.begin(), ::toupper);

        while
        (std::find(room->getExits().begin(), room->getExits().end(),input) == room->getExits().end()        // chceck if Room exits contain input
        &&
        std::find(player.getCmds().begin(), player.getCmds().end(),input) == player.getCmds().end()         // chceck if Room commands contain input
        &&
        std::find(room->getCmds().begin(), room->getCmds().end(),input) == room->getCmds().end()            // chceck if Player commands contain input
        )
        {
            std::cout << "Wrong input!"<<std::endl;
            std::cout << "<Player> ";
            std::cin >> input;
            std::transform(input.begin(), input.end(), input.begin(), ::toupper);
        }

        cmd.at(input)(world);
        room = &map.at(player.getPos());
    }




    getchar();
    return 0;
}
