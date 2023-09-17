#include QMK_KEYBOARD_H


// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _COLEMAK,
    _EXTEND,
    _FUNCTION,
    _SYMBOLS,
    _NUMBERS
};

#define EXT MO(_EXTEND)
#define SYM MO(_SYMBOLS)

#define OS_LSFT OSM(MOD_LSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_LGUI OSM(MOD_LGUI)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   '  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  | Ext  | Shift|      |    |      | Space| Sym  |
 *                  `--------------------'    `--------------------.
 */

// Default config uses home row mods. So hold each of the keys on the home row to use ctrl, gui, alt, or shift
[_QWERTY] = LAYOUT_split_3x5_3(
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT,
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                    EXT,     KC_LSFT, TO(_QWERTY), TO(_COLEMAK), KC_SPC,  SYM
),

/* Colemak
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   F  |   P  |   B  |           |   J  |   L  |   U  |   Y  |   '  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   R  |   S  |   T  |   G  |           |   M  |   N  |   E  |   I  |   O  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   D  |   V  |           |   K  |   H  |   ,  |   .  |   /  |
 * `-------------+--------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  | Ext  | Shift|      |    |      | Space| Sym  |
 *                  `--------------------'    `--------------------.
 */

// Default config uses home row mods. So hold each of the keys on the home row to use ctrl, gui, alt, or shift
[_COLEMAK] = LAYOUT_split_3x5_3(
  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,   KC_U,    KC_Y,    KC_QUOT,
  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,   KC_E,    KC_I,    KC_O,
  KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,   KC_COMM, KC_DOT,  KC_SLSH,
                    EXT,     KC_LSFT, _______, _______, KC_SPC,  SYM
),

/* Extend
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  Esc |  Bk  |  Fnd |  Fw  | Ins  |           |  pgup|home  |up    |end   |caps  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Alt | Super|  Shft| Ctrl |AltGr |           |pgdw  |left  |down  |right |delete|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Undo|   Cut|  Copy| super|paste |           | ent  |bksp  |tab   |menu  |prtscr|
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  |      |      |      |    |      | enter|      |
 *                  `--------------------'    `--------------------.
 */
[_EXTEND] = LAYOUT_split_3x5_3(
  KC_ESC,  KC_WBAK, KC_FIND, KC_WFWD, KC_INS,       KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_CAPS,
  OS_LALT, OS_LGUI, OS_LSFT, OS_LCTL, _______,      KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,
  KC_UNDO, KC_CUT,  KC_COPY, KC_LGUI, KC_PSTE,      _______, KC_BSPC, KC_TAB,  KC_APP,  KC_PSCR,
                    _______, _______, _______,      _______, KC_ENT, _______
),

/* Symbols
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |           |   =  |   `  |   :  |   ;  |   +  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Alt | Super|  Shft| Ctrl |  ^   |           |   *  |   (  |   {  |   [  |   -  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |  \   |   |  |  &   |           |   ~  |   )  |   }  |   ]  |   _  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  |      |      |      |    |      |      |      |
 *                  `--------------------'    `--------------------.
 */
[_SYMBOLS] = LAYOUT_split_3x5_3(
  KC_ESC, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  OS_LALT, OS_LGUI, OS_LSFT, OS_LCTL, _______,      _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,
  KC_CAPS, KC_TILD, _______, _______, _______,      _______, KC_BSPC, _______, KC_PIPE,  KC_DQT,
                    _______, _______, _______,      KC_DEL,  _______, _______
),

/* Adjust (Lower + Raise)
 *
 * ,----------------------------------.           ,----------------------------------.
 * |    ! |    @ |    # |    $ |    % |           |   F1 |  F2  |  F3  |  F4  |  F5 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | SPD_I| HUE_I| SAT_I| VAL_I|    ^ |           |   F6 |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      | \    | |    |   &  |           |  F11 |  F12 |      |      | Reset|
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,--------------------.
 *                  | LOWER|      |      |    |      |      | RAISE|
 *                  `--------------------'    `--------------------.
 *
[_ADJUST] =  LAYOUT_split_3x5_3(
  RGB_TOG, RGB_RMOD, RGB_MOD, _______, TO(_QWERTY),       KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,
  RGB_SPI, RGB_HUI,  RGB_SAI, RGB_VAI, TO(_COLEMAK),      KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,
  RGB_SPD, RGB_HUD,  RGB_SAD, RGB_VAD, _______,           KC_F11,  KC_F12,  _______, _______,  QK_BOOT,
                     _______, _______, _______,           _______, _______, _______
)*/
};
/*
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
*/
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Qwerty\n"), false);
            break;
        case _COLEMAK:
            oled_write_P(PSTR("Colemak\n"), false);
            break;
        case _EXTEND:
            oled_write_P(PSTR("Extend\n"), false);
            break;
        case _SYMBOLS:
            oled_write_P(PSTR("Symbols\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }
    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    
    return false;
}

#endif
