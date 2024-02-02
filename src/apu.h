#ifndef APU_H_INCLUDED
#define APU_H_INCLUDED

#include "common.h"

#include "CH1.h"
#include "CH2.h"
#include "CH3.h"
#include "CH4.h"

struct apu {
    /* APU registers */
    uint8_t left;
    uint8_t right;

    /* Audio Master Control - 0XFF26 -> NR52 */
    union {
        struct {
            uint8_t power: 1;
            uint8_t unused: 3;
            uint8_t CH4: 1;
            uint8_t CH3: 1;
            uint8_t CH2: 1;
            uint8_t CH1: 1;
        } reg;

        uint8_t byte;
    } NR52;

    /* Sound Panning - 0XFF25 -> NR51 */
    union {
        struct {
            uint8_t CH4_l: 1;
            uint8_t CH3_l: 1;
            uint8_t CH2_l: 1;
            uint8_t CH1_l: 1;
            uint8_t CH4_r: 1;
            uint8_t CH3_r: 1;
            uint8_t CH2_r: 1;
            uint8_t CH1_r: 1;
        } reg;

        uint8_t byte;
    } NR51;

    /* Master Volume & VIN - 0XFF24 -> NR50 */
    union {
        struct {
            uint8_t VIN_l: 1;
            uint8_t vol_l: 3;
            uint8_t VIN_r: 1;
            uint8_t vol_r: 3;
        } reg;

        uint8_t byte;
    } NR50;

    /* CH1 - Pulse channel
     * CH2 - Pulse channel
     * CH3 -  Wave channel
     * CH4 - Noise channel */
    struct Channel_1 CH1;
    struct Channel_2 CH2;
    struct Channel_3 CH3;
    struct Channel_4 CH4;

    struct {
        int right;
        int left;
    } stereo;

};

extern uint8_t *mem_pointer(uint16_t addr);
extern uint8_t mem_read(uint16_t addr);

#endif // APU_H_INCLUDED
