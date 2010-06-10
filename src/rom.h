#ifndef ROM_H
#define ROM_H

enum {
	ROM_SIZE = 33554432
};

extern void assign_char_code(int code, unsigned char a, unsigned char b);
extern void patch_char_code(int code, int i, unsigned char a, unsigned char b);

extern void read_rom(const char *fn);
extern void write_rom(const char *fn);

#endif
