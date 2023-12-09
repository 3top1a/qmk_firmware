/* Copyright 2022 Philip Mourdjis <philip.j.m@gmail.com>
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

#pragma once

#include "quantum.h"

#ifndef USER00
#define USER00 SAFE_RANGE
#endif

enum rk68_keycodes {
    BT_PROFILE1 = USER00,
    BT_PROFILE2,
    BT_PROFILE3,
    BT_PROFILE4,
    BT_PROFILE5,
    BT_PAIR,
    BT_TOGGLE,
    BT_RESET,
    RK68_SAFE_RANGE
};

#if defined(KEYBOARD_royal_kludge_rk68_rgb)
    #include "rgb.h"
#elif defined(KEYBOARD_royal_kludge_rk68_white)
    #include "white.h"
#endif