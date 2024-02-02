#ifndef CH1_H_INCLUDED
#define CH1_H_INCLUDED

#include "common.h"

struct Channel_1 {
    /* Channel 1 Sweep - 0XFF10 -> NR10*/
    union {
        struct {
            uint8_t unused: 1;
            uint8_t pace: 3;
            uint8_t direction: 1;
            uint8_t individual_step: 3;
        } reg;

        uint8_t byte;
    } NR10;

    /* Channel 1 Length time and duty cycle - 0XFF11 -> NR11 */
    union {
        struct {
            uint8_t wave_duty: 2;
            uint8_t initial_lenth_timer: 6;
        } reg;

        uint8_t byte;
    } NR11;

    /* Channel 1 volume & envelope - 0XFF12 -> NR12: */
    union {
        struct {
            uint8_t initial_volume: 4;
            uint8_t env: 1;
            uint8_t sweep_pace: 3;
        } reg;

        uint8_t byte;
    } NR12;

    /* Channel 1 period low [write-only] - 0XFF13 -> NR13:*/
    union {
        struct {
            uint8_t period_value_lower;
        } reg;

        uint8_t byte;
    } NR13;

    /* Channel 1 period high & control - FF14 -> NR14: */
    union {
        struct {
            uint8_t trigger: 1;
            uint8_t lenth_enable: 1;
            uint8_t unused: 3;
            uint8_t period_value_upper: 3;
        } reg;

        uint8_t byte;
    } NR14;

    // stores the current length timer
    int length_timer;
};


#endif // CH1_H_INCLUDED
