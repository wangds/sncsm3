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
#include <string.h>
#include "rom.h"
#include "table/font.h"
#include "table/kanji.h"

static unsigned char *s_rom;
static int s_designated_glyph[NUM_CHAR_CODES];
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

static void
initialise_char_codes(void)
{
	int code = FIRST_CHAR_CODE;
	int glyph = 0x015f;
	int remaining;
	int i;

	for (i = 0; k_contiguous_kanji[i] != 0; i++) {
		if (k_contiguous_kanji[i] < 0) {
			code += -k_contiguous_kanji[i];
			continue;
		}

		for (remaining = k_contiguous_kanji[i]; remaining > 0; remaining--) {
			s_designated_glyph[code - FIRST_CHAR_CODE] = -glyph;
			code++;
			glyph++;
		}
	}
}

void
patch_char_code_ex(int code, int glyph, unsigned char a, unsigned char b)
{
	const letter_t *syma = get_symbol(a);
	const letter_t *symb = get_symbol(b);
	assert(syma != NULL && symb != NULL);

	assign_char_code(code, a, b);
	patch_glyph(glyph, *syma, *symb);
}

void
patch_char_code(int code, unsigned char a, unsigned char b)
{
	assert(FIRST_CHAR_CODE <= code && code <= LAST_CHAR_CODE);

	if (s_char_code[a][b] != 0)
		return;

	/* Search for a free code within the block. */
	if ((code & 0x00FF) == 0 || (code == FIRST_CHAR_CODE)) {
		while (s_designated_glyph[code - FIRST_CHAR_CODE] >= 0) {
			code++;

			if ((code & 0xFF) == 0) {
				fprintf(stderr, "Warning: out of space in 0x%04x\n",
						code - 0x0100);
				assert((code & 0xFF) > 0);
			}
		}
	}

	assert(s_designated_glyph[code - FIRST_CHAR_CODE] < 0);
	s_designated_glyph[code - FIRST_CHAR_CODE] *= -1;

	patch_char_code_ex(code, s_designated_glyph[code - FIRST_CHAR_CODE], a, b);
}

/*--------------------------------------------------------------*/

void
patch_raw(int offset, int code)
{
	assert(offset < ROM_SIZE);

	s_rom[offset + 0] = (code >> 8);
	s_rom[offset + 1] = (code & 0xFF);
}

void
patch_2char(int offset, unsigned char a, unsigned char b)
{
	int code = s_char_code[a][b];

	if (code <= 0) {
		fprintf(stderr, "Unknown character code 0x%04x: %c%c\n", code, a, b);
		assert(code > 0);
	}

	patch_raw(offset, code);
}

/* Strings are terminated by 0x0000.
 * length = maximum length of destination string (bytes)
 */
void
patch_str(int offset, int length, const char *str)
{
	int len = strlen(str);
	int i;
	assert((length & 0x1) == 0);

	if (len > length - 2) {
		fprintf(stderr, "String too long (len %d, max %d): %s\n",
				len, length, str);
		assert(len <= length - 2);
	}

	for (i = 0; i < len; i += 2) {
		char a = str[i + 0];
		char b = (i + 1 < len) ? str[i + 1] : ' ';

		patch_2char(offset + i, a, b);
	}

	for (; i < length; i++) {
		s_rom[offset + i] = '\0';
	}
}

/* offset = offset in rom to patch
 * stride = stride between elements in rom
 * num    = number of elements to patch
 * length = maximum length of destination strings
 * src    = replacement strings
 */
void
patch_table(int offset, int stride, int num, int length, const char * const * str)
{
	int i;

	for (i = 0; i < num; i++) {
		if (str[i] != NULL)
			patch_str(offset + stride * i, length, str[i]);
	}
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

	initialise_char_codes();
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
