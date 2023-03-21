//
// Created by Pawel on 19.03.2023.
//

#ifndef TEXT_GAME_CONTENT_H
#define TEXT_GAME_CONTENT_H

#include <string>

// abstract parent class for contents inside room like player, item, object etc.
class Content {
private:
    std::string name;                    // name of content object
    std::string description;             // description of content object
    //std::vector<Command> commands;
public:
        virtual bool execute(std::string xd) = 0;
};


#endif //TEXT_GAME_CONTENT_H
