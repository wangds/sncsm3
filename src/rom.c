/* rom.c
 *
 * Summon Night Craft Sword Monogatari: Hajimari no Ishi ROM is 32MB,
 * with md5sum:
 *
 *  6d676a8cb2d528a647e62110653418a8  sncsm3.gba
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "rom.h"
#include "table/font.h"
#include "table/kanji.h"

static unsigned char *s_rom;
static int s_char_code[256][256];

/*--------------------------------------------------------------*/

static letter_t *
get_symbol(unsigned char c)
{
	if ('A' <= c && c <= 'Z')
		return k_font_uppercase[c - 'A'];

	if ('a' <= c && c <= 'z')
		return k_font_lowercase[c - 'a'];

	if (c == ' ') return &k_font_space;
	if (c == ',') return &k_font_comma;
	if (c == '.') return &k_font_period;
	if (c == ';') return &k_font_semicolon;
	if (c == '?') return &k_font_question;
	if (c == '!') return &k_font_exclamation;
	if (c =='\'') return &k_font_apostrophe;
	if (c == '-') return &k_font_dash;

	return NULL;
}

static void
patch_glyph(int i, const char a[12][6], const char b[12][6])
{
	int y;

	for (y = 0; y < 12; y++) {
		int offset = 0x014d5c88 + (2*12 * i) + (2*y);
		int img = 0;

		if (a[y][0] != ' ') img |= (1 << 15);
		if (a[y][1] != ' ') img |= (1 << 14);
		if (a[y][2] != ' ') img |= (1 << 13);
		if (a[y][3] != ' ') img |= (1 << 12);
		if (a[y][4] != ' ') img |= (1 << 11);
		if (a[y][5] != ' ') img |= (1 << 10);

		if (b[y][0] != ' ') img |= (1 << 9);
		if (b[y][1] != ' ') img |= (1 << 8);
		if (b[y][2] != ' ') img |= (1 << 7);
		if (b[y][3] != ' ') img |= (1 << 6);
		if (b[y][4] != ' ') img |= (1 << 5);
		if (b[y][5] != ' ') img |= (1 << 4);

		s_rom[offset + 0] = (img >> 8);
		s_rom[offset + 1] = (img & 0xff);
	}
}

void
assign_char_code(int code, unsigned char a, unsigned char b)
{
	assert(s_char_code[a][b] == 0);
	s_char_code[a][b] = code;
}

static int
allocate_char_code(void)
{
	static int l_lastchar = 0x889f - 1;
	static int l_remaining = 0;
	static int l_index = 0;

    while (l_remaining <= 0) {
        if (k_contiguous_kanji[l_index] == 0) {
            fprintf(stderr, "Warning: out of space.\n");
            return -1;
        }
        else if (k_contiguous_kanji[l_index] < 0) {
            l_lastchar += -k_contiguous_kanji[l_index];
        }
        else {
            l_remaining = k_contiguous_kanji[l_index];
        }

        l_index++;
    }

    l_remaining--;
    l_lastchar++;
    return l_lastchar;
}

void
patch_char_code(int code, int i, unsigned char a, unsigned char b)
{
	const letter_t *syma = get_symbol(a);
	const letter_t *symb = get_symbol(b);
	assert(syma != NULL && symb != NULL);

	if (code <= 0) {
		code = allocate_char_code();
		assert(code > 0);
	}

	assign_char_code(code, a, b);
	patch_glyph(i, *syma, *symb);
}

/*--------------------------------------------------------------*/

void
read_rom(const char *fn)
{
	FILE *fp_in;
	size_t bytes;

	fp_in = fopen(fn, "rb");
	assert(fp_in != NULL);

	s_rom = malloc(ROM_SIZE + 1);
	assert(s_rom != NULL);

	bytes = fread(s_rom, 1, ROM_SIZE, fp_in);
	assert(bytes == ROM_SIZE);

	fclose(fp_in);
}

void
write_rom(const char *fn)
{
	FILE *fp_out;
	size_t bytes;

	fp_out = fopen(fn, "wb");
	assert(fp_out != NULL);

	bytes = fwrite(s_rom, 1, ROM_SIZE, fp_out);
	assert(bytes == ROM_SIZE);

	fclose(fp_out);

	free(s_rom);
	s_rom = NULL;
}
