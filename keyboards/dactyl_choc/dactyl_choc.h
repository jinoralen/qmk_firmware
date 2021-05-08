#pragma once

#include "quantum.h"

#define KEYMAP(\
    L00, L01, L02, L03, L04, L05,      R05, R04, R03, R02, R01, R00, \
    L10, L11, L12, L13, L14, L15,      R15, R14, R13, R12, R11, R10, \
    L20, L21, L22, L23, L24, L25,      R25, R24, R23, R22, R21, R20, \
              L32, L33, L34, L35,      R35, R34, R33, R32, \
                        L44, L45,      R45, R44, \
                        L54, L55,      R55, R54                      \
    )\
    {\
        { L00, L01, L02, L03, L04, L05},    \
        { L10, L11, L12, L13, L14, L15},    \
        { L20, L21, L22, L23, L24, L25},    \
    { KC_NO, KC_NO, L32, L33, L34, L35},    \
{ KC_NO, KC_NO, KC_NO, KC_NO, L44, L45},    \
{ KC_NO, KC_NO, KC_NO, KC_NO, L54, L55},    \
\
        { R00, R01, R02, R03, R04, R05},    \
        { R10, R11, R12, R13, R14, R15},    \
        { R20, R21, R22, R23, R24, R25},    \
    { KC_NO, KC_NO, R32, R33, R34, R35},    \
{ KC_NO, KC_NO, KC_NO, KC_NO, R44, R45},    \
{ KC_NO, KC_NO, KC_NO, KC_NO, R54, R55}     \
}
