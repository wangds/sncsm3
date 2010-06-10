#ifndef ROM_H
#define ROM_H

enum {
	ROM_SIZE = 33554432
};

extern void read_rom(const char *fn);
extern void write_rom(const char *fn);

#endif
