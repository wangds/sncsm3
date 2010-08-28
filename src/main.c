/* main.c
 */

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include "rom.h"
#include "table/beast.h"
#include "table/effect.h"
#include "table/item.h"
#include "table/magic.h"
#include "table/special.h"
#include "table/weapon.h"

static const char * const k_script[] = {
	"script/day0_0x017bcb2c_kajishi.txt",

	"script/minigame_fishing.txt",
	"script/teleporter.txt",
	NULL
};

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
create_font_punctuation(int code)
{
	char b;

	for (b = 'A'; b <= 'Z'; b++) {
		patch_char_code(code, ' ', b);
	}

	for (b = 'a'; b <= 'z'; b++) {
		patch_char_code(code, ' ', b);
	}

	for (b = 'a'; b <= 'z'; b++) {
		patch_char_code(code, '-', b);
	}

	/* Apostrophes in contractions. */
	patch_char_code(code, '\'', 'l'); /* I'll */
	patch_char_code(code, '\'', 'r'); /* you're */
	patch_char_code(code, '\'', 's'); /* that's */
	patch_char_code(code, '\'', 't'); /* don't */
	patch_char_code(code, '\'', 'v'); /* you've */

	/* Special: Four-Leaf Twin-Snake fooled; fishermen; */
	patch_char_code(code, '-', 'L');
	patch_char_code(code, '-', 'S');
	patch_char_code(code, 'd', ';');
	patch_char_code(code, 'n', ';');
}

static void
create_font_upper(int code, const char *as)
{
	char b;
	int i;

	for (i = 0; as[i] != '\0'; i++) {
		for (b = 'a'; b <= 'z'; b++) {
			if (should_generate_pair(as[i], b))
				patch_char_code(code, as[i], b);
		}
	}
}

static void
create_font_lower(int code, const char *as)
{
	static const char *bs = " ,.?!\'-abcdefghijklmnopqrstuvwxyz";
	int i, j;

	for (i = 0; as[i] != '\0'; i++) {
		for (j = 0; bs[j] != '\0'; j++) {
			patch_char_code(code, as[i], bs[j]);
		}
	}
}

static void
create_font(void)
{
	int i;

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
	assign_char_code(0x8166,'\'', ' ');
	assign_char_code(0x8169, '(', ' ');
	assign_char_code(0x816a, ')', ' ');
	assign_char_code(0x817b, '+', ' ');
	assign_char_code(0x817c, '-', ' ');
	assign_char_code(0x8193, '%', '%');
	assign_char_code(0x83c0, '@', 'R'); /* Ritchburn/Rifmonica. */
	assign_char_code(0x83c2, '@', 'r'); /* Ritchie/Rif. */

	for (i = 0; i <= 9; i++) {
		assign_char_code(0x824f + i, '~', '0' + i);
	}

	for (i = 0; i < 26; i++) {
		assign_char_code(0x8260 + i, '~', 'A' + i);
		assign_char_code(0x8281 + i, 'a' + i, '~');
	}

	/* Q is inevitably followed by u. */
	patch_char_code_ex(0x8270, 0x0060, 'Q', 'u');
	patch_char_code_ex(0x8291, 0x007a, 'q', 'u');

	/* "Case-sensitive letter and bigram frequency counts
	 *  from large-scale English corpora"
	 *
	 * Lower case frequency: etaon isrhl dcumf pgywb vkxzj q
	 * Upper case frequency: TSAMC INBRP EDHWL OFYGJ UKVQX Z
	 */

	create_font_punctuation(0x8e00);

	/* Attempt to share second letters:
	 * [Th][th] (e ) -- the , then, etc.
	 * [Wh][wh] (en) -- who , when, etc.
	 */
	patch_char_code(0x8cfc, 'T','h');
	patch_char_code(0x89fc, 't','h');
	patch_char_code(0x90fc, 'W','h');
	patch_char_code(0x93fc, 'w','h');

	/* Attempt to group capitals into the same few slots. */
	create_font_upper(0x8c00, "TSAMCIN");
	create_font_upper(0x9000, "BRPEDHWL");
	create_font_upper(0x9100, "OFYGJUKVXZ");

	create_font_lower(0x8900, "eta");
	create_font_lower(0x8a00, "oni");
	create_font_lower(0x8b00, "srh");
	create_font_lower(0x8d00, "ldc");
	create_font_lower(0x8f00, "umf");
	create_font_lower(0x9200, "pgy");
	create_font_lower(0x9300, "wbv");
	create_font_lower(0x9500, "kxz");
	create_font_lower(0x889f, "j");

	{
		/* A-space, I-space. */
		patch_char_code(0x8c00, 'A', ' ');
		patch_char_code(0x8c00, 'I', ' ');
		patch_char_code(0x8c00, 'I','\'');
		patch_char_code(0x9100, 'O', 'K');

		/* AGL, ATK, DEF, DUR, TEC, HP. */
		patch_char_code(0x8c00, 'A', 'G');
		patch_char_code(0x9100, 'G', 'L');
		patch_char_code(0x9000, 'L', ' ');

		patch_char_code(0x8c00, 'A', 'T');
		patch_char_code(0x8c00, 'T', 'K');
		patch_char_code(0x9100, 'K', ' ');

		patch_char_code(0x9000, 'D', 'E');
		patch_char_code(0x9000, 'E', 'F');
		patch_char_code(0x9100, 'F', ' ');

		patch_char_code(0x9000, 'D', 'U');
		patch_char_code(0x9100, 'U', 'R');
		patch_char_code(0x9000, 'R', ' ');

		patch_char_code(0x8c00, 'T', 'E');
		patch_char_code(0x9000, 'E', 'C');
		patch_char_code(0x8c00, 'C', ' ');

		patch_char_code(0x9000, 'H', 'P');
		patch_char_code(0x9000, 'P', ' ');

		/* n-M, m-M (ItmMat, WpnMat). */
		patch_char_code(0x8a00, 'n', 'M');
		patch_char_code(0x8f00, 'm', 'M');

		/* V.E. */
		patch_char_code(0x9100, 'V', '.');
		patch_char_code(0x9000, 'E', ' ');
		patch_char_code(0x9000, 'E', ',');
		patch_char_code(0x9000, 'E', '!');

		/* Hm.. */
		patch_char_code(0x9000, 'H', 'm');
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

static void
translate_main_menu(void)
{
	/* First menu. */
	patch_str(0x000bacf0,  8, "Equip"  );   /* equipment */
	patch_str(0x000bace4, 12, "Support");
	patch_str(0x000bacd8, 12, "Item  " );
	patch_str(0x000bacd0,  8, "Magic"  );
	patch_str(0x000bacc8,  8, "Weapon" );
	patch_str(0x000bacbc, 12, "Status" );

	/* Second menu. */
	patch_str(0x000bad38,  8, "Quest"  );   /* quest items */
	patch_str(0x000bad2c, 12, "Rank"   );   /* craft rank */
	patch_str(0x000bad24,  8, "Tech"   );   /* techniques */
	patch_str(0x000bad1c,  8, "Spec"   );   /* special attack */
	patch_str(0x000bad10, 12, "Effect" );
	patch_str(0x000bad04, 12, "Beasts" );   /* bestiary */
	patch_str(0x000bacf8, 12, "Config" );   /* options */

	/* Rank/Techniques submenu. */
	patch_str(0x000bad78,  8, "Sword"  );
	patch_str(0x000bad70,  8, "Axe"    );
	patch_str(0x000bad68,  8, "Spear"  );
	patch_str(0x000bad5c, 12, "Knuckle");
	patch_str(0x000bad54,  8, "Drill"  );
	patch_str(0x000bad4c,  8, "Bow"    );

	/* Item types. */
	patch_str(0x000baeb4,  8, "Recovr");    /* recover */
	patch_str(0x000baeac,  8, "ItmMat");    /* item material */
	patch_str(0x000baea4,  8, "Spec");      /* special */
	patch_str(0x000bae9c,  8, "WpnMat");    /* weapon material */
	patch_str(0x000bae94,  8, "Imbue");     /* imbue material */
	/* Note: 'equipment' comes from the string at 0x000bacf0. */

	/* Forge. */
	patch_str(0x000baf1c,  8, "Create");
	patch_str(0x000baf00,  8, "Strgth");    /* strengthen */
	/* Note: 'imbue' comes from the string at 0x000bae94. */
	patch_str(0x000baef8,  8, "Disass");    /* disassemble */
	patch_str(0x000baee4,  8, "Repair");

	/* Spell types. */
	patch_str(0x000baf34,  8, "Any");       /* any recover */
	patch_str(0x000baf24,  8, "Field");     /* field support */
	patch_str(0x000baf44,  8, "Aux");       /* battle/field support */
	patch_str(0x000baf2c,  8, "Battle");    /* battle attack/support */
	patch_str(0x000baf3c,  8, "Attack");    /* battle attack */
	patch_str(0x000baf4c,  8, "Attack");    /* battle attack */

	/* Equip self/guardian beast. */
	patch_str(0x000baf5c,  8, "Equip");     /* equipment */
	patch_str(0x000baf64,  8, "Magic");
	/* Note: 'item' comes from the string at 0x000bacd8. */
	patch_str(0x000baf54,  8, "Remove");    /* unequip/remove */

	/* Shop menu. */
	patch_str(0x000baf7c,  8, "Buy");
	patch_str(0x000baf74,  8, "Sell");
	patch_str(0x000baf6c,  8, "Make");
}

static void
translate_items(void)
{
	patch_table(0x00bbca9c +  0, 84, NUM_ITEMS, 18, k_item_name);
	patch_table(0x00bbca9c + 44, 84, NUM_ITEMS, 38, k_item_desc);
}

static void
translate_magics(void)
{
	patch_table(0x00bc73dc +  0, 64, NUM_MAGICS, 18, k_magic_name);
	patch_table(0x00bc73dc + 24, 64, NUM_MAGICS, 38, k_magic_desc);
}

static void
translate_weapons(void)
{
	patch_table(0x00bc1e9c +  0, 88, NUM_WEAPONS, 18, k_weapon_name);
	patch_table(0x00bc1e9c + 50, 88, NUM_WEAPONS, 38, k_weapon_desc);
}

static void
translate_specials(void)
{
	patch_table(0x00bc81dc +  0, 68, NUM_SPECIALS, 18, k_special_name);
	patch_table(0x00bc81dc + 28, 68, NUM_SPECIALS, 38, k_special_desc);
}

static void
translate_effects(void)
{
	patch_table(0x00bc9100 +  0, 68, NUM_EFFECTS, 18, k_effect_name);
	patch_table(0x00bc9100 + 28, 68, NUM_EFFECTS, 38, k_effect_desc);
}

static void
translate_bestiary(void)
{
	patch_table(0x00b75114 +  0, 120, NUM_BEASTS, 18, k_beast_name);
	patch_table(0x00b75114 + 64, 120, NUM_BEASTS, 56, k_beast_desc);

	patch_table(0x00b75114 - 120 * 99, 120, NUM_BOSSES, 18, k_boss_name);
}

static void
translate_dialogue(void)
{
	int i;

	for (i = 0; k_script[i] != NULL; i++) {
		patch_dlg(k_script[i]);
	}
}

/*--------------------------------------------------------------*/

int
main(int argc, char *argv[])
{
	(void)argc, (void)argv;

	read_rom("sncsm3.gba");

	create_font();
	translate_name_entry_menu();
	translate_main_menu();
	translate_items();
	translate_magics();
	translate_weapons();
	translate_specials();
	translate_effects();
	translate_bestiary();
	translate_dialogue();

	write_rom("out.gba");

	return 0;
}
