#pragma once

#define USE_SERIAL

// #define MASTER_LEFT // this is the default - usb connected side is taken as master 
#define SPLIT_HAND_PIN D2 // rx pin must be pulled high by a 10k resister in the left side
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 2000
#define SPLIT_USB_TIMEOUT_POLL 10
// #define MASTER_RIGHT
//#define EE_HANDS
// wrote eeprom in promicro using avrdude in windows using the following commands
// for right and left hands respectively
// .\avrdude -p m32U4 -P COM4 -c avr109 -U eeprom:w:eeprom-righthand.eep:i
// .\avrdude -p m32U4 -P COM5 -c avr109 -U eeprom:w:eeprom-lefthand.eep:i

/* Set 0 if debouncing isn't needed */
#undef DEBOUNCE
#define DEBOUNCE 40


// WS2812 RGB LED strip input and number of LEDs
#undef RGB_DI_PIN
#define RGB_DI_PIN D0
#undef RGBLED_NUM
#define RGBLED_NUM 48
#define RGBLIGHT_SPLIT
#define RGBLED_SPLIT { 24, 24 }
//#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_LAYERS
#define RGBLIGHT_SLEEP // If defined, the RGB lighting will be switched off when the host goes to sleep
#define RGBLIGHT_LIMIT_VAL 250 // max 255 (0.32A one side for 24 leds with 255, 0.29A at 250)
#define RGBLIGHT_HUE_STEP 10 // The number of steps to cycle through the hue by
#define RGBLIGHT_SAT_STEP 17 // The number of steps to increment the saturation by
#define RGBLIGHT_VAL_STEP 17 // The number of steps to increment the brightness by

/* serial.c configuration for split keyboard */
#undef SOFT_SERIAL_PIN
#define SOFT_SERIAL_PIN D3

#define SPLIT_MODS_ENABLE
#define SPLIT_TRANSPORT_MIRROR
#define SERIAL_USE_MULTI_TRANSACTION

#define TAPPING_TOGGLE 2 // for TT layers tapping 2 times will toggle the layer

// following settings are for the home row mods (used only for ctrl and alt)
// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 220
#define TAPPING_TERM_PER_KEY // See bottom of keymap.c
// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
// This prevents accidental repeats of the tap-hold keys when typing quickly.
//#define TAPPING_FORCE_HOLD

// Apply the modifier on keys that are tapped during a short hold of a modtap
// This prevents short hold periods to be interpreted as individual taps when typing quickly.
//#define PERMISSIVE_HOLD


// Limits the max. amount of layers to 8 to save firmware memory.
#define LAYER_STATE_8BIT