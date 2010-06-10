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

static unsigned char *s_rom;

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
