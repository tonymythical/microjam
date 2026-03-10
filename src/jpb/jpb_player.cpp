#include "jpb/jpb_player.h"
#include <bn_keypad.h>
#include "bn_sprite_items_jpb_ship.h"

namespace jpb {
    
    bn::rect create_bounding_box(bn::sprite_ptr sprite, bn::size box_size) {
        return bn::rect(sprite.x().round_integer(),
                        sprite.y().round_integer(),
                        box_size.width(),
                        box_size.height());
    }

    jpb_player::jpb_player(bn::fixed_point starting_position, bn::size _size, bn::fixed _speed) :
        player_sprite(bn::sprite_items::jpb_ship.create_sprite(starting_position)),
        speed(_speed),
        player_box(create_bounding_box(player_sprite, _size))
    {}
    
    void jpb_player::update() {
        if(bn::keypad::left_held()) {
            player_sprite.set_x(player_sprite.x() - speed);
        }
        if(bn::keypad::right_held()) {
            player_sprite.set_x(player_sprite.x() + speed);
        }
        if(bn::keypad::up_held()) {
            player_sprite.set_y(player_sprite.y() - speed);
        }
        if(bn::keypad::down_held()) {
            player_sprite.set_y(player_sprite.y() + speed);
        }

        player_box = create_bounding_box(player_sprite, {8, 8});

    }

    bool jpb_player::enemy_intersect(bn::rect enemy_box) const {
        return player_box.intersects(enemy_box);
    }
}