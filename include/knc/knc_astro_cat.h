#ifndef KNC_ASTRO_CAT_H
#define KNC_ASTRO_CAT_H

#include "mj/mj_game.h"
#include "knc/knc_cat.h"
#include "knc/knc_planet.h"
#include "mj/mj_difficulty_level.h"
#include "knc/knc_shooting_star.h"
#include "knc/knc_background.h"
#include "knc/knc_enemy.h"

namespace knc {
    class knc_astro_cat : public mj::game {
    public:
        knc_astro_cat(int completed_games, const mj::game_data& data);

        bn::string<16> title() const override;
        int total_frames() const override;
        mj::game_result play(const mj::game_data& data) override;
        bool victory() const override;
        void fade_in(const mj::game_data& data) override;
        void fade_out(const mj::game_data& data) override;

    private:
        static bn::fixed _recommended_speed (mj::difficulty_level difficulty);

        background _background;
        cat _cat;
        mj::difficulty_level _difficulty;
        planet _planet1;
        planet _planet2;
        planet _planet3;
        planet _planet4;
        shooting_star _star1;
        shooting_star _star2;
        shooting_star _star3;
        enemy _enemy1;
        bool _enemy1_direction;
        int  _enemy1_delay;
        bool _hit;
    };
}

#endif
