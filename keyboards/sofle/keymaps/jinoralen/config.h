#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/
#define MASTER_RIGHT

/* Enables This makes it easier for fast typists to use dual-function keys */
#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY

#define HOLD_ON_OTHER_KEY_PRESS
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

#undef TAPPING_TERM
#define TAPPING_TERM 270