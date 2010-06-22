/* main.c
 */

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include "rom.h"

/*--------------------------------------------------------------*/

static bool
should_generate_pair(char a, char b)
{
	assert(('A' <= a && a <= 'Z') || ('a' <= a && a <= 'z'));
	assert('a' <= b && b <= 'z');

	/* Special case for Q and q:
	 * We have already substituted Q -> Qu, q -> qu.
	 */
	if (a == 'Q' || a == 'q')
		return false;

	/* Generate all cases of letter-vowel. */
	if (b == 'a' || b == 'e' || b == 'i' ||
	    b == 'o' || b == 'u' || b == 'y')
		return true;

	/* Blacklist.  A,E,I,O,U,S basically join to everything. */
	if ((a == 'B' && b != 'h' && b != 'l' && b != 'r')
	 || (a == 'C' && b != 'h' && b != 'l' && b != 'r')
	 || (a == 'D' && b != 'r' && b != 'w')
	 || (a == 'F' && b != 'l' && b != 'r')
	 || (a == 'G' && b != 'h' && b != 'l' && b != 'n' && b != 'r')
	 || (a == 'H')
	 || (a == 'J')
	 || (a == 'K' && b != 'h' && b != 'l' && b != 'n' && b != 'r')
	 || (a == 'L' && b != 'l')
	 || (a == 'M' && b != 'n' && b != 'r' && b != 's')
	 || (a == 'N')
	 || (a == 'P' && b != 'h' && b != 'l' && b != 'n' && b != 'r' && b != 's')
	 || (a == 'R' && b != 'h')
	 || (a == 'T' && b != 'h' && b != 'r' && b != 's' && b != 'w')
	 || (a == 'V')
	 || (a == 'W' && b != 'h' && b != 'p' && b != 'r')
	 || (a == 'X')
	 || (a == 'Y')
	 || (a == 'Z'))
		return false;

	return true;
}

static void
create_font(void)
{
	char a, b;
	int c, i;

	/* Full-width characters. */
	assign_char_code(0x8140, ' ', ' ');
	assign_char_code(0x8143, ',', ' ');
	assign_char_code(0x8144, '.', ' ');
	assign_char_code(0x8146, ':', ' ');
	assign_char_code(0x8147, ';', ' ');
	assign_char_code(0x8148, '?', ' ');
	assign_char_code(0x8149, '!', ' ');
	assign_char_code(0x815e, '/', ' ');
	assign_char_code(0x8163, '.', '.');
	assign_char_code(0x8169, '(', ' ');
	assign_char_code(0x816a, ')', ' ');
	assign_char_code(0x817b, '+', ' ');
	assign_char_code(0x817c, '-', ' ');
	assign_char_code(0x8193, '%', '%');

	for (i = 0; i <= 9; i++) {
		assign_char_code(0x824f + i, '~', '0' + i);
	}

	for (i = 0; i < 26; i++) {
		assign_char_code(0x8260 + i, '~', 'A' + i);
		assign_char_code(0x8281 + i, '~', 'a' + i);
	}

	/* Q is inevitably followed by u. */
	patch_char_code(0x8270, 0x0060, 'Q', 'u');
	patch_char_code(0x8291, 0x007a, 'q', 'u');

	/* Kanji start at 0x015f. */
	c = 0x015f;

	for (i = 0; i < 26 * 2; i++) {
		b = (i < 26) ? ('A' + i) : ('a' + i - 26);

		/* space-X, dash-X. */
		patch_char_code(0, c++, ' ', b);
		patch_char_code(0, c++, '-', b);
	}

	{
		/* Apostrophes in contractions. */
		patch_char_code(0, c++, '\'', 'l');
		patch_char_code(0, c++, '\'', 's');
		patch_char_code(0, c++, '\'', 't');
	}

	{
		/* A-dash. */
		for (a = 'A'; a <= 'Z'; a++) {
			patch_char_code(0, c++, a, '-');
		}

		/* A-space, I-space. */
		patch_char_code(0, c++, 'A', ' ');
		patch_char_code(0, c++, 'I', ' ');

		/* AGL, ATK, DEF, DUR, TEC, HP. */
		patch_char_code(0, c++, 'A', 'G');
		patch_char_code(0, c++, 'G', 'L');
		patch_char_code(0, c++, 'L', ' ');

		patch_char_code(0, c++, 'A', 'T');
		patch_char_code(0, c++, 'T', 'K');
		patch_char_code(0, c++, 'K', ' ');

		patch_char_code(0, c++, 'D', 'E');
		patch_char_code(0, c++, 'E', 'F');
		patch_char_code(0, c++, 'F', ' ');

		patch_char_code(0, c++, 'D', 'U');
		patch_char_code(0, c++, 'U', 'R');
		patch_char_code(0, c++, 'R', ' ');

		patch_char_code(0, c++, 'T', 'E');
		patch_char_code(0, c++, 'E', 'C');
		patch_char_code(0, c++, 'C', ' ');

		patch_char_code(0, c++, 'H', 'P');
		patch_char_code(0, c++, 'P', ' ');
	}

	for (a = 'a'; a <= 'z'; a++) {
		/* x-space, x-comma, x-period, etc. */
		patch_char_code(0, c++, a, ' ');
		patch_char_code(0, c++, a, ',');
		patch_char_code(0, c++, a, '.');
		patch_char_code(0, c++, a, '?');
		patch_char_code(0, c++, a, '!');
		patch_char_code(0, c++, a,'\'');
		patch_char_code(0, c++, a, '-');
	}

	{
		/* d-semicolon, n-semicolon. */
		patch_char_code(0, c++, 'd', ';');
		patch_char_code(0, c++, 'n', ';');
	}

	{
		/* n-M, m-M (ItmMat, WpnMat). */
		patch_char_code(0, c++, 'n', 'M');
		patch_char_code(0, c++, 'm', 'M');
	}

	/* "Aa" and "aa". */
	for (i = 0; i < 26 * 2; i++) {
		a = (i < 26) ? ('A' + i) : ('a' + i - 26);
		for (b = 'a'; b <= 'z'; b++) {
			if (!should_generate_pair(a, b))
				continue;

			patch_char_code(0, c++, a, b);
		}
	}
}

/*--------------------------------------------------------------*/

static void
translate_name_entry_menu(void)
{
	/* Default Names. */
	patch_str(0x00bd5744, 12, "~Ritchburn");
	patch_str(0x00bd5752, 12, "~Rifmonica");
	patch_str(0x00bd575e, 10, "Rundor");
	patch_str(0x00bd5768,  8, "Enzi");
	patch_str(0x00bd5770, 12, "Killfith");
	patch_str(0x00bd577c, 12, "Rufeel");
	patch_str(0x00bd57a0, 10, "~Ritchie");
	patch_str(0x00bd57aa,  6, "~Rif");

	/* Hiragana table. */
	patch_2char(0x00bd5408, 'K', 'a'); patch_2char(0x00bd540a, 'n', 'a');
	patch_2char(0x00bd540e, '~', 'E'); patch_2char(0x00bd5410, '~', 'N');
	patch_2char(0x00bd5414, '~', 'D'); patch_2char(0x00bd5416, 'e', 'l');
	patch_2char(0x00bd541a, '~', 'O'); patch_2char(0x00bd541c, '~', 'K');

	/* Katakana table. */
	patch_2char(0x00bd5504, 'G', 'a'); patch_2char(0x00bd5506, 'n', 'a');
	patch_2char(0x00bd550a, '~', 'E'); patch_2char(0x00bd550c, '~', 'N');
	patch_2char(0x00bd5510, '~', 'D'); patch_2char(0x00bd5512, 'e', 'l');
	patch_2char(0x00bd5516, '~', 'O'); patch_2char(0x00bd5518, '~', 'K');

	/* English table. */
	patch_2char(0x00bd5600, 'G', 'a'); patch_2char(0x00bd5602, 'n', 'a');
	patch_2char(0x00bd5606, 'K', 'a'); patch_2char(0x00bd5608, 'n', 'a');
	patch_2char(0x00bd560c, '~', 'D'); patch_2char(0x00bd560e, 'e', 'l');
	patch_2char(0x00bd5612, '~', 'O'); patch_2char(0x00bd5614, '~', 'K');
}

/*--------------------------------------------------------------*/

int
main(int argc, char *argv[])
{
	(void)argc, (void)argv;

	read_rom("sncsm3.gba");

	create_font();
	translate_name_entry_menu();

	write_rom("out.gba");

	return 0;
}
