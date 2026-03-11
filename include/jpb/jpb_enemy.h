#ifndef JPB_ENEMY_H
#define JPB_ENEMY_H

#include "jpb/jpb_player.h"

namespace jpb {

class jpb_enemy {
    public:
        jpb_enemy(bn::fixed_point enemy_position, bn::size enemy_size);

        void update();

        bn::sprite_ptr _enemy_sprite;
        bn::rect _enemy_box;
};

}

#endif