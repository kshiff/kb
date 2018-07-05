/*
Copyright 2016 Jun Wako <wakojun@gmail.com>

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
#include "unimap_trans.h"

enum macro_id {
    SLP
};

// macro - sleep mac
#define AC_SLP ACTION_MACRO(SLP)
#define AC_FN0 ACTION_LAYER_MOMENTARY(1)

#ifdef KEYMAP_SECTION_ENABLE
const action_t actionmaps[][UNIMAP_ROWS][UNIMAP_COLS] __attribute__ ((section (".keymap.keymaps"))) = {
#else
const action_t actionmaps[][UNIMAP_ROWS][UNIMAP_COLS] PROGMEM = {
#endif
    UNIMAP(
              TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    ESC,      F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12,          SLP, SLCK,PAUS,    TRNS,TRNS,TRNS,
    GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL,TRNS,BSPC,     INS, HOME,PGUP,    NLCK,PSLS,PAST,PMNS,    
    TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,    BSLS,     DEL, END, PGDN,    P7,  P8,  P9,  TRNS,    
    FN0, A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,    TRNS, ENT,                        P4,  P5,  P6,  PPLS,   
    LSFT,TRNS,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,    TRNS,RSFT,          UP,           P1,  P2,  P3,  TRNS,       
    LCTL,LALT,LGUI,TRNS,      SPC,              TRNS,TRNS,RGUI,RALT,APP, RCTL,     LEFT,DOWN,RGHT,    P0,       PDOT,PENT
    ),
    UNIMAP(
              TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,
    TRNS,     TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,         TRNS,TRNS,TRNS,   TRNS,TRNS,TRNS,
    TRNS,  F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9, F10, F11, F12,TRNS, DEL,    TRNS,TRNS,TRNS,   NLCK,PSLS,PAST,PMNS,    
    CAPS,MPRV,MPLY,MNXT,TRNS,TRNS,TRNS,PGUP,  UP,PGDN,TRNS,TRNS,TRNS,     TRNS,    TRNS,TRNS,TRNS,   P7,  P8,  P9,  TRNS,    
    TRNS,MUTE,VOLD,VOLU,TRNS,TRNS,TRNS,LEFT,DOWN,RGHT,TRNS,TRNS,     TRNS,TRNS,                      P4,  P5,  P6,  PPLS,   
    TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,     TRNS,RSFT,           UP,        P1,  P2,  P3,  TRNS,       
    LCTL,LALT,LGUI,TRNS,       SPC,             TRNS,TRNS,RGUI,RALT, APP, RCTL,    LEFT,DOWN,RGHT,   P0,       PDOT,PENT    
    ),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case SLP:
            return (record->event.pressed ?
                    MACRO( D(LGUI), D(LCTL), T(Q), END ) :
                    MACRO( U(LGUI), U(LCTL), END ) );
    }
    return MACRO_NONE;
}