#ifndef ROM_H
#define ROM_H

enum {
	ROM_SIZE = 33554432
};

extern void assign_char_code(int code, unsigned char a, unsigned char b);
extern void patch_char_code_ex(int code, int glyph, unsigned char a, unsigned char b);
extern void patch_char_code(int code, unsigned char a, unsigned char b);

extern void patch_raw(int offset, int code);
extern void patch_2char(int offset, unsigned char a, unsigned char b);
extern void patch_str(int offset, int length, const char *str);
extern void patch_table(int offset, int stride, int num, int length, const char * const * str);

extern void read_rom(const char *fn);
extern void write_rom(const char *fn);

#endif
