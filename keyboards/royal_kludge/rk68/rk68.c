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

#include "rk68.h"
#ifdef BLUETOOTH_ENABLE
#include "outputselect.h"
#include "iton_bt.h"
#endif


uint8_t curr_bt_profile = -1;

void iton_bt_connection_successful(void) {
    // Only go back to old matrix mode if we come here after a pairing operation
    rgb_matrix_reload_from_eeprom();
}

void iton_bt_entered_pairing(void) {
    //rgb_matrix_set_color_all(0x00, 0x00, 0x00);

    rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_bt_pairing_effect);
}
void iton_bt_disconnected(void) {
    rgb_matrix_reload_from_eeprom();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
#ifdef BLUETOOTH_ENABLE
            case BT_PROFILE1:
                curr_bt_profile = 0;
                iton_bt_switch_profile(0);
                break;
            case BT_PROFILE2:
                curr_bt_profile = 1;
                iton_bt_switch_profile(1);
                break;
            case BT_PROFILE3:
                curr_bt_profile = 2;
                iton_bt_switch_profile(2);
                break;
            case BT_PROFILE4:
                curr_bt_profile = 3;
                iton_bt_switch_profile(3);
                break;
            case BT_PROFILE5:
                curr_bt_profile = 4;
                iton_bt_switch_profile(4);
                break;
            case BT_PAIR:
                if(curr_bt_profile != -1)
                    iton_bt_enter_pairing();
                break;
            case BT_TOGGLE:
                // if(where_to_send() == OUTPUT_USB)
                //     set_output(OUTPUT_BLUETOOTH);
                // else
                //     set_output(OUTPUT_AUTO);
                break;
            case BT_RESET:
                iton_bt_reset_pairing();
                break;
#endif
            default:
                break;
        }
    }
    return process_record_user(keycode, record);
}