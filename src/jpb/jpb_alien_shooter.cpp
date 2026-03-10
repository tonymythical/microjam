#include "jpb/jpb_alien_shooter.h"
#include "mj/mj_game_list.h"

namespace
{
    constexpr bn::string_view code_credits[] = { "Johncarlo", "John Baltazar" };
    constexpr bn::string_view graphics_credits[] = { "Johncarlo", "John Baltazar" };
    constexpr bn::string_view sfx_credits[] = {""};
    constexpr bn::string_view music_credits[] = {""};
}

MJ_GAME_LIST_ADD(jpb::jpb_alien_shooter) 
MJ_GAME_LIST_ADD_CODE_CREDITS(code_credits)
MJ_GAME_LIST_ADD_GRAPHICS_CREDITS(graphics_credits)
MJ_GAME_LIST_ADD_MUSIC_CREDITS(music_credits)
MJ_GAME_LIST_ADD_SFX_CREDITS(sfx_credits)


namespace jpb {
    static constexpr bn::size PLAYER_SIZE = {8, 8};
    static constexpr bn::size ENEMY_SIZE = {8, 8};

    jpb_alien_shooter::jpb_alien_shooter([[maybe_unused]] int completed_games, [[maybe_unused]] const mj::game_data& data) :
        mj::game("jpb"),
        _player(jpb_player({20, 0}, PLAYER_SIZE, 2)),
        _enemy(jpb_enemy({-20, 0}, ENEMY_SIZE))
    {}

    bn::string<16> jpb_alien_shooter::title() const {
        return "placeholder";
    }

    int jpb_alien_shooter::total_frames() const {
        return 300;
    }

    mj::game_result jpb_alien_shooter::play([[maybe_unused]] const mj::game_data& data) {
        _player.update();
        _enemy.update();

        mj::game_result result(victory(), false);
        return result;
    }

    bool jpb_alien_shooter::victory() const {
        if (_player.enemy_intersect(_enemy.enemy_box)) {
            return true;
        }
        return false;
    }

    void jpb_alien_shooter::fade_in([[maybe_unused]] const mj::game_data& data) {

    }

    void jpb_alien_shooter::fade_out([[maybe_unused]] const mj::game_data& data) {

    }
}