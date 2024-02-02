#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define TEST_BIT(a, b) ((a & (1 << b)) == (1 << b))
#define RESET_BIT(a, b) (a & ~(1 << b))
#define SET_BIT(a, b) (a | (1 << b))

#define MAXCYCLES 69905
#define CPU_CLOCK 4194304

// memory location defines
// Cartridge locations
#define mHeaderStart     0X0100
#define mGBC_flag        0X0143
#define mNlic            0X0144
#define mSGB_flag        0X0146
#define mCartridge_type  0X0147
#define mROM_size        0X0148
#define mRAM_size        0X0149
#define mDest_code       0X014A
#define mOlic            0X014B
#define mROM_ver_num     0X014C
#define mHeader_Checksum 0X014D
#define mGlobal_Checksum 0X014E

// PPU locations
#define mLCDC            0XFF40
#define mLCDS            0XFF41
#define mSCY             0XFF42
#define mSCX             0XFF43
#define mWY              0XFF4A
#define mWX              0XFF4B
#define mLY              0XFF44
#define mLYC             0XFF45
#define mPAL             0XFF47
#define mPAL_sp_0        0XFF48
#define mPAL_sp_1        0XFF49

// APU locations
#define mCH1
#define mCH2
#define mCH3
#define mCH4

// DMA transfer location
#define mDMA             0XFF46

// timer locations
#define mDIV             0XFF04
#define mTIMA            0XFF05
#define mTMA             0XFF06
#define mTAC             0XFF07

// interrupt locations
#define mIF              0XFF0F
#define mIE              0XFFFF

// audio locations
#define mNR10            0XFF10
#define mNR11            0XFF11
#define mNR12            0XFF12
#define mNR13            0XFF13
#define mNR14            0XFF14
#define mNR21            0XFF16
#define mNR22            0XFF17
#define mNR23            0XFF18
#define mNR24            0XFF19
#define mNR30            0XFF1A
#define mNR31            0XFF1B
#define mNR32            0XFF1C
#define mNR33            0XFF1D
#define mNR34            0XFF1E
#define mNR41            0XFF20
#define mNR42            0XFF21
#define mNR43            0XFF22
#define mNR44            0XFF23
#define mNR50            0XFF24
#define mNR51            0XFF25
#define mNR52            0XFF26

#endif // COMMON_H_INCLUDED
