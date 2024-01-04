##
# Gameboy Emulator
#
# @file
# @version 0.1

CC=gcc
FILES=src/GBC.c src/cpu.c src/ppu.c src/apu.c src/mem.c src/timer.c src/interrupts.c src/sdl.c

debug:
	$(CC) src/*.c -o bin/gameboy -g -lSDL2 -lncurses -Wall -Wextra -fsanitize=address

release:
	$(CC) $(FILES) -o bin/gameboy -lSDL2


# end
