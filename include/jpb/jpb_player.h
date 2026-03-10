#ifndef JPB_PLAYER_H
#define JPB_PLAYER_H

#include <bn_fixed_point.h>
#include <bn_sprite_ptr.h>
#include <bn_display.h>
#include <bn_rect.h>
#include <bn_size.h>
#include "jpb/jpb_enemy.h"

namespace jpb {

bn::rect create_bounding_box(bn::sprite_ptr sprite, bn::size box_size);

class jpb_player {
    public:
        jpb_player(bn::fixed_point player_position, bn::size player_size, bn::fixed _speed);

        void update();

        bool enemy_intersect(bn::rect enemy_box) const;
    
        bn::sprite_ptr player_sprite;
        bn::fixed speed;
        bn::rect player_box;
};

}

#endif