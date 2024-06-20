#pragma once

#define USE_SERIAL
#define EE_HANDS

#define MOUSEKEY_INERTIA
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 8
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 96
#undef MOUSEKEY_FRICTION
#define MOUSEKEY_FRICTION 96

#undef TAPPING_TERM
#define TAPPING_TERM 200

#define ONESHOT_TAP_TOGGLE 3  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 3000  /* Time (in ms) before the one shot key is released */
