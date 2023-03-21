#include <iostream>
#include <array>
#include <memory>
#include <cstdlib>
#include <ctime>
#include <cmath>

/*
 spoko będzie zacząć od pomieszczeń,
 że gracz może być w danym pomieszczeniu,
 każde pomieszczenie ma swój opis,
 ma relację do jakich, można się przemieścić,
 i gracz za pomocą interfejsu może po nich sobie chodzić

 + do pierwszego zadania ekstra
 w każdym pomieszczeniu jest lista "objektów" z którymi można wejść w interakcjie
 */

#include "Room.h"
#include "Player.h"

const int rows = 10;
const int cols = 10;
std::array<int,2> new_room_pos(std::array<int,2> current)
{
    int drct = rand()%4;
    switch (drct) {
        case 0:
            current[0]--;
            break;

        case 1:
            current[1]++;
            break;

        case 2:
            current[0]++;
            break;

        case 3:
            current[1]--;
            break;
    }
    return current;
}

void showMap(const std::array<std::array<std::unique_ptr<Room>, cols>, rows> & Map)
{
    for (auto &row : Map)
    {
        for(auto &r :row)
        {
            if(!r)
                std::cout<<"  ";
            else
                std::cout<<"1 ";
        }
        std::cout<<'\n';
    }
}

int main() {

    std::array<std::array<std::unique_ptr<Room>, cols>, rows> Map{};

    showMap(Map);

    srand(time(nullptr));


    std::array<int,2> start{rows/2 - 1,cols/2 - 1};

    for(int i = 1; i <= floor(sqrt(cols * rows)); i++)
    {
        std::cout<<start[0]<<" "<<start[1]<<std::endl;
       // if(!Map[start[0]][start[1]])
        Map[start[0]][start[1]] = std::make_unique<Room>("Forest", "Lot of trees", start );

        std::array<int,2> new_pos = new_room_pos(start);
        while( (new_pos[0] < 0 || new_pos[0] > (rows - 1) || new_pos[1] < 0 || new_pos[1] > (cols - 1)) || Map[new_pos[0]][new_pos[1]])
        {
            new_pos = new_room_pos(start);
        }
    start = new_pos;
    }

    showMap(Map);


    getchar();
    return 0;
}
