#ifndef AXO_AQUATIC_GALAXY_DEFENSE_H
#define AXO_AQUATIC_GALAXY_DEFENSE_H

#include <bn_sprite_ptr.h>

#include "mj/mj_game.h"

namespace axo
{

class axo_aquatic_galaxy_defense : public mj::game
{
    public:
        axo_aquatic_galaxy_defense(const mj::game_data& data);
};

}

#endif