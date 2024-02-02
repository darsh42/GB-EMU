#include "apu.h"

struct apu apu;

void apu_read() {
    // global registers
    apu.NR50.byte = mem_read(mNR50);
    apu.NR51.byte = mem_read(mNR51);
    apu.NR52.byte = mem_read(mNR52);

    // Channel 1
    apu.CH1.NR10.byte = mem_read(mNR10);
    apu.CH1.NR11.byte = mem_read(mNR11);
    apu.CH1.NR12.byte = mem_read(mNR12);
    apu.CH1.NR13.byte = mem_read(mNR13);
    apu.CH1.NR14.byte = mem_read(mNR14);

    // Channel 2
    apu.CH2.NR21.byte = mem_read(mNR21);
    apu.CH2.NR22.byte = mem_read(mNR22);
    apu.CH2.NR23.byte = mem_read(mNR23);
    apu.CH2.NR24.byte = mem_read(mNR24);

    // Channel 3
    apu.CH3.NR30.byte = mem_read(mNR30);
    apu.CH3.NR31.byte = mem_read(mNR31);
    apu.CH3.NR32.byte = mem_read(mNR32);
    apu.CH3.NR33.byte = mem_read(mNR33);
    apu.CH3.NR34.byte = mem_read(mNR34);

    // Channel 4
    apu.CH4.NR41.byte = mem_read(mNR41);
    apu.CH4.NR42.byte = mem_read(mNR42);
    apu.CH4.NR43.byte = mem_read(mNR43);
    apu.CH4.NR44.byte = mem_read(mNR44);
}

void apu_init() {
    apu_read();
}

// These functions will generate a signal
int apu_CH1_gen() {
    // check if DAC is off
    if ((apu.CH1.NR12.byte & 0XF8) == 0) {
        return -1;
    }
    // check if the trigger is enabled
    if (apu.CH1.NR14.reg.trigger == 0) {
        return -1;
    }

    if (apu.CH1.NR14.reg.lenth_enable == 1) {
        if (apu.CH1.length_timer == 64) {
            return -1;
        }
    }

    // Sweep period value overflowed
    if (((apu.CH1.NR14.reg.period_value_upper << 8) & apu.CH1.NR13.reg.period_value_lower) > 0X7FF) {
        return -1;
    }



    return 0;
}
int apu_CH2_gen() {
    // check if DAC is off
    if ((apu.CH2.NR22.byte & 0XF8) == 0) {
        return -1;
    }
    // check if the trigger is enabled
    if (apu.CH2.NR24.reg.trigger == 0) {
        return -1;
    }

    if (apu.CH2.NR24.reg.lenth_enable == 1) {
        if (apu.CH2.length_timer == 64) {
            return -1;
        }
    }


    return 0;
}
int apu_CH3_gen() { return 0; }
int apu_CH4_gen() { return 0; }

// Digital to analoge converter, range -1 - 1
float apu_DAC(float val) { return 0; }

// will take the DAC output and make right and left sound
void apu_mixer(float CH1, float CH2, float CH3, float CH4) {}

// take mixer output and scale to user volume
void apu_volume() {}

// take volume output and put High Pass Filter last step
void apu_HPF() {}

// main apu execution loop
int apu_exec() {
    float CH1 = apu_DAC(apu_CH1_gen());
    float CH2 = apu_DAC(apu_CH2_gen());
    float CH3 = apu_DAC(apu_CH3_gen());
    float CH4 = apu_DAC(apu_CH4_gen());

    apu_mixer(CH1, CH2, CH3, CH4);

    apu_volume();

    apu_HPF();

    return 0;
}
