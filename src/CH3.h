#ifndef CH3_H_INCLUDED
#define CH3_H_INCLUDED

#include "common.h"

/* Wave Channel */
struct Channel_3 {
    /* Channel 3 DAC enable - 0XFF1A -> NR30 */
    union {
        struct {
            uint8_t DAC_on: 1;
            uint8_t unused: 7;
        } reg;

        uint8_t byte;
    } NR30;

    /* Channel 3 length timer [write-only] -  FF1B -> NR31 */
    union {
        struct {
            uint8_t inital_length_timer;
        } reg;

        uint8_t byte;
    } NR31;

    /* Channel 3 output level - 0XFF1C — NR32 */
    union {
        struct {
            uint8_t unused_1: 1;
            uint8_t output_level: 2;
            uint8_t unused_2: 5;
        } reg;

        uint8_t byte;
    } NR32;
    /* Channel 3 period low [write-only] - 0XFF1D — NR33 */
    union {
        struct {
            uint8_t period_low;
        } reg;

        uint8_t byte;
    } NR33;

    /* Channel 3 period high & control - 0XFF1E — NR34 */
    union {
        struct {
            uint8_t trigger: 1;
            uint8_t length_enable: 1;
            uint8_t unused: 3;
            uint8_t period: 3;
        } reg;

        uint8_t byte;
    } NR34;

    // stores the current length timer
    int length_timer;
};

#endif // CH3_H_INCLUDED
