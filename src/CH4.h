#ifndef CH4_H_INCLUDED
#define CH4_H_INCLUDED

#include "common.h"

struct Channel_4 {
    /* Channel 4 length timer [write-only] - FF20 -> NR41 */
    union {
        struct {
            uint8_t unused: 2;
            uint8_t initial_length_timer: 6;
        } reg;

        uint8_t byte;
    } NR41;

    /* Channel 4 volume & envelope - FF21 -> NR42 */
    union {
        struct {
            uint8_t initial_volume: 4;
            uint8_t env: 1;
            uint8_t sweep_pace: 3;
        } reg;

        uint8_t byte;
    } NR42;

    /* Channel 4 frequency & randomness - FF22 -> NR43 */
    union {
        struct {
            uint8_t clock_shift: 4;
            uint8_t LFSR_width: 1;
            uint8_t clock_divider: 3;
        } reg;

        uint8_t byte;
    } NR43;

    /* Channel 4 control - FF23 — NR44 */
    union {
        struct {
            uint8_t trigger: 1;
            uint8_t lenth_enable: 1;
            uint8_t unused: 6;
        } reg;

        uint8_t byte;
    } NR44;
};


#endif // CH4_H_INCLUDED
