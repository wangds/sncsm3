/* main.c
 */

#include <assert.h>
#include <stdlib.h>
#include "rom.h"

int
main(int argc, char *argv[])
{
	(void)argc, (void)argv;

	read_rom("sncsm3.gba");

	write_rom("out.gba");

	return 0;
}
