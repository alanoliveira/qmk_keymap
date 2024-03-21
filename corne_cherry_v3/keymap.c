/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#define MK_TMUX LSFT(KC_F1)
#define MK_MOZC KC_F13

enum layers {
    _BASE,
    _LOWER,
    _RAISE,
    _MISC,
    _NUMPAD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌──────────────────┬───┬───┬───┬──────┬────────────┐                ┌────────────┬──────┬───┬───┬───┬───────────┐
//    │ LT(_NUMPAD, tab) │ q │ w │ e │  r   │     t      │                │     y      │  u   │ i │ o │ p │ MO(_MISC) │
//    ├──────────────────┼───┼───┼───┼──────┼────────────┤                ├────────────┼──────┼───┼───┼───┼───────────┤
//    │   LCTL_T(esc)    │ a │ s │ d │  f   │     g      │                │     h      │  j   │ k │ l │ ; │   rctl    │
//    ├──────────────────┼───┼───┼───┼──────┼────────────┤                ├────────────┼──────┼───┼───┼───┼───────────┤
//    │       lsft       │ z │ x │ c │  v   │     b      │                │     n      │  m   │ , │ . │ / │   rsft    │
//    └──────────────────┴───┴───┴───┼──────┼────────────┼──────┐   ┌─────┼────────────┼──────┼───┴───┴───┴───────────┘
//                                   │ lgui │ MO(_LOWER) │ bspc │   │ spc │ MO(_RAISE) │ ralt │                        
//                                   └──────┴────────────┴──────┘   └─────┴────────────┴──────┘                        
[_BASE] = LAYOUT_split_3x6_3(
  LT(_NUMPAD, KC_TAB) , KC_Q , KC_W , KC_E , KC_R    , KC_T       ,                        KC_Y       , KC_U    , KC_I    , KC_O   , KC_P    , MO(_MISC),
  LCTL_T(KC_ESC)      , KC_A , KC_S , KC_D , KC_F    , KC_G       ,                        KC_H       , KC_J    , KC_K    , KC_L   , KC_SCLN , KC_RCTL  ,
  KC_LSFT             , KC_Z , KC_X , KC_C , KC_V    , KC_B       ,                        KC_N       , KC_M    , KC_COMM , KC_DOT , KC_SLSH , KC_RSFT  ,
                                             KC_LGUI , MO(_LOWER) , KC_BSPC ,     KC_SPC , MO(_RAISE) , KC_RALT                                         
),

//    ┌──────┬────┬────┬────┬─────┬─────┐             ┌──────┬─────────┬──────┬──────┬─────┬─────┐
//    │ caps │ 1  │ 2  │ 3  │  4  │  5  │             │  6   │    7    │  8   │  9   │  0  │     │
//    ├──────┼────┼────┼────┼─────┼─────┤             ├──────┼─────────┼──────┼──────┼─────┼─────┤
//    │      │ f1 │ f2 │ f3 │ f4  │ f5  │             │ left │  down   │  up  │ rght │ ins │     │
//    ├──────┼────┼────┼────┼─────┼─────┤             ├──────┼─────────┼──────┼──────┼─────┼─────┤
//    │      │ f6 │ f7 │ f8 │ f9  │ f10 │             │ home │  pgdn   │ pgup │ end  │ del │     │
//    └──────┴────┴────┴────┼─────┼─────┼─────┐   ┌───┼──────┼─────────┼──────┴──────┴─────┴─────┘
//                          │ f11 │     │ f12 │   │ _ │  =   │ MK_TMUX │                          
//                          └─────┴─────┴─────┘   └───┴──────┴─────────┘                          
[_LOWER] = LAYOUT_split_3x6_3(
  KC_CAPS , KC_1  , KC_2  , KC_3  , KC_4   , KC_5    ,                        KC_6    , KC_7    , KC_8    , KC_9     , KC_0   , _______,
  _______ , KC_F1 , KC_F2 , KC_F3 , KC_F4  , KC_F5   ,                        KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT , KC_INS , _______,
  _______ , KC_F6 , KC_F7 , KC_F8 , KC_F9  , KC_F10  ,                        KC_HOME , KC_PGDN , KC_PGUP , KC_END   , KC_DEL , _______,
                                    KC_F11 , _______ , KC_F12 ,     KC_UNDS , KC_EQL  , MK_TMUX                                        
),

//    ┌──────┬─────────┬─────────┬───┬─────────┬─────────┐               ┌─────┬─────┬───┬───┬───┬──────┐
//    │ pscr │    !    │    @    │ # │    $    │    %    │               │  ^  │  &  │ * │ ( │ ) │ bspc │
//    ├──────┼─────────┼─────────┼───┼─────────┼─────────┤               ├─────┼─────┼───┼───┼───┼──────┤
//    │      │ LSFT(,) │ LSFT(.) │ ` │    '    │ LSFT(/) │               │ no  │  -  │ | │ { │ } │      │
//    ├──────┼─────────┼─────────┼───┼─────────┼─────────┤               ├─────┼─────┼───┼───┼───┼──────┤
//    │      │    [    │    ]    │ ~ │ LSFT(') │ LSFT(;) │               │ no  │  +  │ \ │ [ │ ] │      │
//    └──────┴─────────┴─────────┴───┼─────────┼─────────┼─────┐   ┌─────┼─────┼─────┼───┴───┴───┴──────┘
//                                   │ MK_MOZC │ CW_TOGG │ ent │   │     │     │     │                   
//                                   └─────────┴─────────┴─────┘   └─────┴─────┴─────┘                   
[_RAISE] = LAYOUT_split_3x6_3(
  KC_PSCR , KC_EXLM       , KC_AT        , KC_HASH , KC_DLR        , KC_PERC       ,                        KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , KC_BSPC,
  _______ , LSFT(KC_COMM) , LSFT(KC_DOT) , KC_GRV  , KC_QUOT       , LSFT(KC_SLSH) ,                        XXXXXXX , KC_MINS , KC_PIPE , KC_LCBR , KC_RCBR , _______,
  _______ , KC_LBRC       , KC_RBRC      , KC_TILD , LSFT(KC_QUOT) , LSFT(KC_SCLN) ,                        XXXXXXX , KC_PLUS , KC_BSLS , KC_LBRC , KC_RBRC , _______,
                                                     MK_MOZC       , CW_TOGG       , KC_ENT ,     _______ , _______ , _______                                        
),

//    ┌─────┬─────────┬─────────┬─────────┬─────────┬─────────┐                ┌─────────┬─────────┬─────────┬─────────┬─────────┬──────────┐
//    │     │ RGUI(1) │ RGUI(2) │ RGUI(3) │ RGUI(4) │ RGUI(5) │                │ RGUI(6) │ RGUI(7) │ RGUI(8) │ RGUI(9) │ RGUI(0) │          │
//    ├─────┼─────────┼─────────┼─────────┼─────────┼─────────┤                ├─────────┼─────────┼─────────┼─────────┼─────────┼──────────┤
//    │     │  wh_u   │  btn2   │  ms_u   │  btn1   │  volu   │                │ RGB_TOG │ RGB_HUI │ RGB_SAI │ RGB_VAI │         │          │
//    ├─────┼─────────┼─────────┼─────────┼─────────┼─────────┤                ├─────────┼─────────┼─────────┼─────────┼─────────┼──────────┤
//    │     │  wh_d   │  ms_l   │  ms_d   │  ms_r   │  vold   │                │ RGB_MOD │ RGB_HUD │ RGB_SAD │ RGB_VAD │         │ LCA(del) │
//    └─────┴─────────┴─────────┴─────────┼─────────┼─────────┼──────┐   ┌─────┼─────────┼─────────┼─────────┴─────────┴─────────┴──────────┘
//                                        │         │         │ mute │   │     │ QK_BOOT │ EE_CLR  │                                         
//                                        └─────────┴─────────┴──────┘   └─────┴─────────┴─────────┘                                         
[_MISC] = LAYOUT_split_3x6_3(
  _______ , RGUI(KC_1) , RGUI(KC_2) , RGUI(KC_3) , RGUI(KC_4) , RGUI(KC_5) ,                         RGUI(KC_6) , RGUI(KC_7) , RGUI(KC_8) , RGUI(KC_9) , RGUI(KC_0) , _______    ,
  _______ , KC_WH_U    , KC_BTN2    , KC_MS_U    , KC_BTN1    , KC_VOLU    ,                         RGB_TOG    , RGB_HUI    , RGB_SAI    , RGB_VAI    , _______    , _______    ,
  _______ , KC_WH_D    , KC_MS_L    , KC_MS_D    , KC_MS_R    , KC_VOLD    ,                         RGB_MOD    , RGB_HUD    , RGB_SAD    , RGB_VAD    , _______    , LCA(KC_DEL),
                                                   _______    , _______    , KC_MUTE ,     _______ , QK_BOOT    , EE_CLR                                                         
),

//    ┌─────┬────┬────┬────┬─────────────┬────┐              ┌───┬───┬───┬───┬───┬──────┐
//    │     │ no │ no │ no │     no      │ no │              │ * │ 7 │ 8 │ 9 │ + │ bspc │
//    ├─────┼────┼────┼────┼─────────────┼────┤              ├───┼───┼───┼───┼───┼──────┤
//    │ no  │ no │ no │ no │     no      │ no │              │ / │ 4 │ 5 │ 6 │ - │  no  │
//    ├─────┼────┼────┼────┼─────────────┼────┤              ├───┼───┼───┼───┼───┼──────┤
//    │ no  │ no │ no │ no │     no      │ no │              │ . │ 1 │ 2 │ 3 │ , │  no  │
//    └─────┴────┴────┴────┼─────────────┼────┼────┐   ┌─────┼───┼───┼───┴───┴───┴──────┘
//                         │ TG(_NUMPAD) │ no │ no │   │ ent │ 0 │ = │                   
//                         └─────────────┴────┴────┘   └─────┴───┴───┘                   
[_NUMPAD] = LAYOUT_split_3x6_3(
  _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX     , XXXXXXX ,                        KC_ASTR , KC_7   , KC_8 , KC_9 , KC_PLUS , KC_BSPC,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX     , XXXXXXX ,                        KC_SLSH , KC_4   , KC_5 , KC_6 , KC_MINS , XXXXXXX,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX     , XXXXXXX ,                        KC_DOT  , KC_1   , KC_2 , KC_3 , KC_COMM , XXXXXXX,
                                          TG(_NUMPAD) , XXXXXXX , XXXXXXX ,     KC_ENT , KC_0    , KC_EQL                                  
)
};
