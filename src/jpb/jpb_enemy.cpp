#include "jpb/jpb_enemy.h"
#include "bn_sprite_items_jpb_alien.h"
#include "jpb_missile.h"

namespace jpb {

    jpb_enemy::jpb_enemy(bn::fixed_point starting_position, bn::size size) :
        _enemy_sprite(bn::sprite_items::jpb_alien.create_sprite(starting_position)),
        _enemy_box(create_bounding_box(_enemy_sprite, size))
    {}

    void jpb_enemy::update() {
        _enemy_box = create_bounding_box(_enemy_sprite, {8, 8});
    }
}