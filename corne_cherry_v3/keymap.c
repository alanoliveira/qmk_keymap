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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌─────────────┬───┬───┬───┬───────────────┬───────┐                       ┌─────┬──────┬───┬───┬───┬──────┐
//    │     tab     │ q │ w │ e │       r       │   t   │                       │  y  │  u   │ i │ o │ p │ bspc │
//    ├─────────────┼───┼───┼───┼───────────────┼───────┤                       ├─────┼──────┼───┼───┼───┼──────┤
//    │ LCTL_T(esc) │ a │ s │ d │       f       │   g   │                       │  h  │  j   │ k │ l │ ; │  '   │
//    ├─────────────┼───┼───┼───┼───────────────┼───────┤                       ├─────┼──────┼───┼───┼───┼──────┤
//    │    lsft     │ z │ x │ c │       v       │   b   │                       │  n  │  m   │ , │ . │ / │ rsft │
//    └─────────────┴───┴───┴───┼───────────────┼───────┼─────────────┐   ┌─────┼─────┼──────┼───┴───┴───┴──────┘
//                              │ OSM(MOD_LGUI) │ MO(2) │ LT(1, bspc) │   │ spc │ ent │ ralt │                   
//                              └───────────────┴───────┴─────────────┘   └─────┴─────┴──────┘                   
[0] = LAYOUT_split_3x6_3(
  KC_TAB         , KC_Q , KC_W , KC_E , KC_R          , KC_T  ,                               KC_Y   , KC_U    , KC_I    , KC_O   , KC_P    , KC_BSPC,
  LCTL_T(KC_ESC) , KC_A , KC_S , KC_D , KC_F          , KC_G  ,                               KC_H   , KC_J    , KC_K    , KC_L   , KC_SCLN , KC_QUOT,
  KC_LSFT        , KC_Z , KC_X , KC_C , KC_V          , KC_B  ,                               KC_N   , KC_M    , KC_COMM , KC_DOT , KC_SLSH , KC_RSFT,
                                        OSM(MOD_LGUI) , MO(2) , LT(1, KC_BSPC) ,     KC_SPC , KC_ENT , KC_RALT                                       
),

//    ┌──────┬───┬───┬───┬─────┬─────────┐             ┌───┬─────┬───┬───┬───┬─────┐
//    │ tab  │ 1 │ 2 │ 3 │  4  │    5    │             │ 6 │  7  │ 8 │ 9 │ 0 │     │
//    ├──────┼───┼───┼───┼─────┼─────────┤             ├───┼─────┼───┼───┼───┼─────┤
//    │ lctl │ ! │ @ │ # │  $  │    %    │             │ ^ │  &  │ * │ ( │ ) │  \  │
//    ├──────┼───┼───┼───┼─────┼─────────┤             ├───┼─────┼───┼───┼───┼─────┤
//    │ lsft │ [ │ ] │ ~ │  `  │ LCTL(c) │             │ | │  +  │ - │ { │ } │ no  │
//    └──────┴───┴───┴───┼─────┼─────────┼─────┐   ┌───┼───┼─────┼───┴───┴───┴─────┘
//                       │     │         │     │   │ _ │ = │     │                  
//                       └─────┴─────────┴─────┘   └───┴───┴─────┘                  
[1] = LAYOUT_split_3x6_3(
  KC_TAB  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5       ,                         KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , _______,
  KC_LCTL , KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC    ,                         KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , KC_BSLS,
  KC_LSFT , KC_LBRC , KC_RBRC , KC_TILD , KC_GRV  , LCTL(KC_C) ,                         KC_PIPE , KC_PLUS , KC_MINS , KC_LCBR , KC_RCBR , XXXXXXX,
                                          _______ , _______    , _______ ,     KC_UNDS , KC_EQL  , _______                                        
),

//    ┌──────┬─────┬──────┬──────┬──────┬──────┐               ┌───────┬──────┬────┬──────┬─────┬─────┐
//    │  f1  │ f2  │  f3  │  f4  │  f5  │  f6  │               │  f7   │  f8  │ f9 │ f10  │ f11 │ f12 │
//    ├──────┼─────┼──────┼──────┼──────┼──────┤               ├───────┼──────┼────┼──────┼─────┼─────┤
//    │ lctl │ ins │ home │ pgup │ volu │ mply │               │ left  │ down │ up │ rght │ no  │ no  │
//    ├──────┼─────┼──────┼──────┼──────┼──────┤               ├───────┼──────┼────┼──────┼─────┼─────┤
//    │ lsft │ del │ end  │ pgdn │ vold │ mute │               │ pscr  │  no  │ no │  no  │ no  │ no  │
//    └──────┴─────┴──────┴──────┼──────┼──────┼─────┐   ┌─────┼───────┼──────┼────┴──────┴─────┴─────┘
//                               │      │      │     │   │     │ TT(3) │      │                        
//                               └──────┴──────┴─────┘   └─────┴───────┴──────┘                        
[2] = LAYOUT_split_3x6_3(
  KC_F1   , KC_F2  , KC_F3   , KC_F4   , KC_F5   , KC_F6   ,                         KC_F7   , KC_F8   , KC_F9   , KC_F10   , KC_F11  , KC_F12 ,
  KC_LCTL , KC_INS , KC_HOME , KC_PGUP , KC_VOLU , KC_MPLY ,                         KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT , XXXXXXX , XXXXXXX,
  KC_LSFT , KC_DEL , KC_END  , KC_PGDN , KC_VOLD , KC_MUTE ,                         KC_PSCR , XXXXXXX , XXXXXXX , XXXXXXX  , XXXXXXX , XXXXXXX,
                                         _______ , _______ , _______ ,     _______ , TT(3)   , _______                                         
),

//    ┌────┬────┬──────┬──────┬──────┬─────┐               ┌─────────┬─────────┬─────────┬─────────┬────┬──────────┐
//    │ no │ no │ btn1 │ ms_u │ btn2 │ no  │               │   no    │   no    │   no    │   no    │ no │ QK_BOOT  │
//    ├────┼────┼──────┼──────┼──────┼─────┤               ├─────────┼─────────┼─────────┼─────────┼────┼──────────┤
//    │ no │ no │ ms_l │ ms_d │ ms_r │ no  │               │ RGB_TOG │ RGB_HUI │ RGB_SAI │ RGB_VAI │ no │    no    │
//    ├────┼────┼──────┼──────┼──────┼─────┤               ├─────────┼─────────┼─────────┼─────────┼────┼──────────┤
//    │ no │ no │  no  │  no  │  no  │ no  │               │ RGB_MOD │ RGB_HUD │ RGB_SAD │ RGB_VAD │ no │ LCA(del) │
//    └────┴────┴──────┴──────┼──────┼─────┼─────┐   ┌─────┼─────────┼─────────┼─────────┴─────────┴────┴──────────┘
//                            │      │     │     │   │     │         │         │                                    
//                            └──────┴─────┴─────┘   └─────┴─────────┴─────────┘                                    
[3] = LAYOUT_split_3x6_3(
  XXXXXXX , XXXXXXX , KC_BTN1 , KC_MS_U , KC_BTN2 , XXXXXXX ,                         XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , QK_BOOT    ,
  XXXXXXX , XXXXXXX , KC_MS_L , KC_MS_D , KC_MS_R , XXXXXXX ,                         RGB_TOG , RGB_HUI , RGB_SAI , RGB_VAI , XXXXXXX , XXXXXXX    ,
  XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                         RGB_MOD , RGB_HUD , RGB_SAD , RGB_VAD , XXXXXXX , LCA(KC_DEL),
                                          _______ , _______ , _______ ,     _______ , _______ , _______                                            
)
};
