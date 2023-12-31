/* Copyright 2022 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum layers {
    SWITCH_L,
    SWITCH_R,
    _FN1,
    _FN2,
    _FN3
};

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌─────────────┬──────┬──────┬───┬───┬───┬───┬───┬───┬───┬──────┬──────┬──────────┬──────┐
//    │      `      │  1   │  2   │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │  0   │  -   │    =     │ bspc │
//    ├─────────────┼──────┼──────┼───┼───┼───┼───┼───┼───┼───┼──────┼──────┼──────────┼──────┤
//    │     tab     │  q   │  w   │ e │ r │ t │ y │ u │ i │ o │  p   │  [   │    ]     │  \   │
//    ├─────────────┼──────┼──────┼───┼───┼───┼───┼───┼───┼───┼──────┼──────┼──────────┴──────┤
//    │ LCTL_T(esc) │  a   │  s   │ d │ f │ g │ h │ j │ k │ l │  ;   │  '   │       ent       │
//    ├─────────────┴──────┼──────┼───┼───┼───┼───┼───┼───┼───┼──────┼──────┼─────────────────┤
//    │        lsft        │  z   │ x │ c │ v │ b │ n │ m │ , │  .   │  /   │      rsft       │
//    ├─────────────┬──────┼──────┼───┴───┴───┴───┴───┴───┴───┼──────┼──────┼──────────┬──────┤
//    │  MO(_FN1)   │ lalt │ lgui │            spc            │ ralt │ rgui │ TT(_FN3) │ rctl │
//    └─────────────┴──────┴──────┴───────────────────────────┴──────┴──────┴──────────┴──────┘
[SWITCH_L] = LAYOUT_ansi_61(
  KC_GRV         , KC_1    , KC_2    , KC_3 , KC_4 , KC_5 , KC_6 , KC_7 , KC_8 , KC_9    , KC_0    , KC_MINS , KC_EQL   , KC_BSPC,
  KC_TAB         , KC_Q    , KC_W    , KC_E , KC_R , KC_T , KC_Y , KC_U , KC_I , KC_O    , KC_P    , KC_LBRC , KC_RBRC  , KC_BSLS,
  LCTL_T(KC_ESC) , KC_A    , KC_S    , KC_D , KC_F , KC_G , KC_H , KC_J , KC_K , KC_L    , KC_SCLN , KC_QUOT , KC_ENT            ,
  KC_LSFT                  , KC_Z    , KC_X , KC_C , KC_V , KC_B , KC_N , KC_M , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT           ,
  MO(_FN1)       , KC_LALT , KC_LGUI ,                      KC_SPC                       , KC_RALT , KC_RGUI , TT(_FN3) , KC_RCTL
),

//    ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
//    │     │     │     │     │     │     │     │     │     │     │     │     │     │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
//    │     │     │     │     │     │     │     │     │     │     │     │     │     │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┴─────┤
//    │     │     │     │     │     │     │     │     │     │     │     │     │           │
//    ├─────┴─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼───────────┤
//    │           │     │     │     │     │     │     │     │     │     │     │           │
//    ├─────┬─────┼─────┼─────┴─────┴─────┴─────┴─────┴─────┴─────┼─────┼─────┼─────┬─────┤
//    │     │     │     │              LT(_FN2, spc)              │     │     │     │     │
//    └─────┴─────┴─────┴─────────────────────────────────────────┴─────┴─────┴─────┴─────┘
[SWITCH_R] = LAYOUT_ansi_61(
  _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______,
  _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______,
  _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______          ,
  _______           , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______          ,
  _______ , _______ , _______ ,                          LT(_FN2, KC_SPC)                           , _______ , _______ , _______ , _______
),

//    ┌──────┬─────┬──────┬──────┬──────┬─────┬──────┬──────┬─────┬──────┬─────┬─────┬─────┬──────┐
//    │      │ f1  │  f2  │  f3  │  f4  │ f5  │  f6  │  f7  │ f8  │  f9  │ f10 │ f11 │ f12 │ pscr │
//    ├──────┼─────┼──────┼──────┼──────┼─────┼──────┼──────┼─────┼──────┼─────┼─────┼─────┼──────┤
//    │      │     │      │      │      │     │      │      │     │      │     │     │     │      │
//    ├──────┼─────┼──────┼──────┼──────┼─────┼──────┼──────┼─────┼──────┼─────┼─────┼─────┴──────┤
//    │ caps │ ins │ home │ pgup │      │     │ left │ down │ up  │ rght │     │     │            │
//    ├──────┴─────┼──────┼──────┼──────┼─────┼──────┼──────┼─────┼──────┼─────┼─────┼────────────┤
//    │            │ del  │ end  │ pgdn │     │      │      │     │      │     │     │            │
//    ├──────┬─────┼──────┼──────┴──────┴─────┴──────┴──────┴─────┴──────┼─────┼─────┼─────┬──────┤
//    │      │     │      │                                              │     │     │     │      │
//    └──────┴─────┴──────┴──────────────────────────────────────────────┴─────┴─────┴─────┴──────┘
[_FN1] = LAYOUT_ansi_61(
  _______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_F9    , KC_F10  , KC_F11  , KC_F12  , KC_PSCR,
  _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______  , _______ , _______ , _______ , _______,
  KC_CAPS , KC_INS  , KC_HOME , KC_PGUP , _______ , _______ , KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT , _______ , _______ , _______          ,
  _______           , KC_DEL  , KC_END  , KC_PGDN , _______ , _______ , _______ , _______ , _______  , _______ , _______ , _______          ,
  _______ , _______ , _______ ,                               _______                                , _______ , _______ , _______ , _______
),

//    ┌─────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────┬─────┬─────┐
//    │     │         │         │         │         │         │         │         │         │         │         │     │     │     │
//    ├─────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────┼─────┼─────┤
//    │     │    1    │    2    │    3    │    4    │    5    │    6    │    7    │    8    │    9    │    0    │     │     │     │
//    ├─────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────┼─────┴─────┤
//    │     │ LSFT(1) │ LSFT(2) │ LSFT(3) │ LSFT(4) │ LSFT(5) │ LSFT(6) │ LSFT(7) │ LSFT(8) │ LSFT(9) │ LSFT(0) │     │           │
//    ├─────┴─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────────┼─────┼───────────┤
//    │    LSFT(\)    │ LSFT(=) │    -    │ LSFT(-) │    =    │         │ LSFT(`) │    `    │         │         │  \  │           │
//    ├─────┬─────────┼─────────┼─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┼─────────┼─────┼─────┬─────┤
//    │     │         │         │                                                                     │         │     │     │     │
//    └─────┴─────────┴─────────┴─────────────────────────────────────────────────────────────────────┴─────────┴─────┴─────┴─────┘
[_FN2] = LAYOUT_ansi_61(
  _______ , _______    , _______      , _______    , _______       , _______    , _______    , _______      , _______    , _______    , _______    , _______ , _______ , _______,
  _______ , KC_1       , KC_2         , KC_3       , KC_4          , KC_5       , KC_6       , KC_7         , KC_8       , KC_9       , KC_0       , _______ , _______ , _______,
  _______ , LSFT(KC_1) , LSFT(KC_2)   , LSFT(KC_3) , LSFT(KC_4)    , LSFT(KC_5) , LSFT(KC_6) , LSFT(KC_7)   , LSFT(KC_8) , LSFT(KC_9) , LSFT(KC_0) , _______ , _______          ,
  LSFT(KC_BSLS)        , LSFT(KC_EQL) , KC_MINS    , LSFT(KC_MINS) , KC_EQL     , _______    , LSFT(KC_GRV) , KC_GRV     , _______    , _______    , KC_BSLS , _______          ,
  _______ , _______    , _______      ,                                            _______                                            , _______    , _______ , _______ , _______
),

//    ┌─────────┬──────┬──────┬──────┬─────┬──────────┬─────────┬─────────┬─────────┬─────────┬──────┬─────┬─────┬───────────────┐
//    │         │      │      │      │     │          │         │         │         │         │      │     │     │               │
//    ├─────────┼──────┼──────┼──────┼─────┼──────────┼─────────┼─────────┼─────────┼─────────┼──────┼─────┼─────┼───────────────┤
//    │ RGB_TOG │ btn1 │ ms_u │ btn2 │     │ RGB_MOD  │ RGB_VAI │ RGB_HUI │ RGB_SAI │ RGB_SPI │      │     │     │ QK_BOOTLOADER │
//    ├─────────┼──────┼──────┼──────┼─────┼──────────┼─────────┼─────────┼─────────┼─────────┼──────┼─────┼─────┴───────────────┤
//    │         │ ms_l │ ms_d │ ms_r │     │ RGB_RMOD │ RGB_VAD │ RGB_HUD │ RGB_SAD │ RGB_SPD │      │     │                     │
//    ├─────────┴──────┼──────┼──────┼─────┼──────────┼─────────┼─────────┼─────────┼─────────┼──────┼─────┼─────────────────────┤
//    │                │      │      │     │          │         │         │  mute   │  vold   │ volu │     │                     │
//    ├─────────┬──────┼──────┼──────┴─────┴──────────┴─────────┴─────────┴─────────┴─────────┼──────┼─────┼─────┬───────────────┤
//    │         │      │      │                                                               │      │     │     │               │
//    └─────────┴──────┴──────┴───────────────────────────────────────────────────────────────┴──────┴─────┴─────┴───────────────┘
[_FN3] = LAYOUT_ansi_61(
  _______ , _______ , _______ , _______ , _______ , _______  , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______      ,
  RGB_TOG , KC_BTN1 , KC_MS_U , KC_BTN2 , _______ , RGB_MOD  , RGB_VAI , RGB_HUI , RGB_SAI , RGB_SPI , _______ , _______ , _______ , QK_BOOTLOADER,
  _______ , KC_MS_L , KC_MS_D , KC_MS_R , _______ , RGB_RMOD , RGB_VAD , RGB_HUD , RGB_SAD , RGB_SPD , _______ , _______ , _______                ,
  _______           , _______ , _______ , _______ , _______  , _______ , _______ , KC_MUTE , KC_VOLD , KC_VOLU , _______ , _______                ,
  _______ , _______ , _______ ,                               _______                                , _______ , _______ , _______ , _______      
)
};

// clang-format on
