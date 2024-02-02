#ifndef CH2_H_INCLUDED
#define CH2_H_INCLUDED

#include "common.h"

struct Channel_2 {
    /* Channel 2 Length time and duty cycle - 0XFF11 -> NR21 */
    union {
        struct {
            uint8_t wave_duty: 2;
            uint8_t initial_lenth_timer: 6;
        } reg;

        uint8_t byte;
    } NR21;

    /* Channel 2 volume & envelope - 0XFF12 -> NR22 */
    union {
        struct {
            uint8_t initial_volume: 4;
            uint8_t env: 1;
            uint8_t sweep_pace: 3;
        } reg;

        uint8_t byte;
    } NR22;

    /* Channel 2 period low [write-only] - 0XFF13 -> NR23*/
    union {
        struct {
            uint8_t period_value_lower;
        } reg;

        uint8_t byte;
    } NR23;

    /* Channel 2 period high & control - FF14 -> NR24 */
    union {
        struct {
            uint8_t trigger: 1;
            uint8_t lenth_enable: 1;
            uint8_t unused: 3;
            uint8_t period_value_upper: 3;
        } reg;

        uint8_t byte;
    } NR24;
};

#endif // CH2_H_INCLUDED
