/* magic.c
 */

#include "table/magic.h"

const char * const k_magic_name[NUM_MAGICS] = {
	/*           123456789-123456 */
	/*   0 */   "Healing"
	/*   1 */ , "Escape"
	/*   2 */ , "Quick Move"
	/*   3 */ , "Astral Guard"
	/*   4 */ , "Weapon Shield"
	/*   5 */ , "Enchant Spark"
	/*   6 */ , "Enchant Flare"
	/*   7 */ , "Enchant Aqua"
	/*   8 */ , "Enchant Wind"

	/*   9 */ , "Revive"
	/*  10 */ , "Recover Weapon"
	/*  11 */ , "Vampirism"
	/*  12 */ , "Magic Barrier"

	/*  13 */ , "Tri-Spark"
	/*  14 */ , "Flare Burn"
	/*  15 */ , "Aqua Ball"
	/*  16 */ , "Burst Gale"
	/*  17 */ , "Thunder Chain"
	/*  18 */ , "Burning Wall"
	/*  19 */ , "Mega Splash"
	/*  20 */ , "Hurricane Wall"

	/*  21 */ , "Tag Partner"
	/*  22 */ , "Tag Partner"
	/*  23 */ , "Tag Partner"
	/*  24 */ , "Tag Partner"
	/*  25 */ , "Tag True Partner"
	/*  26 */ , "Tag True Partner"
	/*  27 */ , "Tag True Partner"
	/*  28 */ , "Tag True Partner"

	/*  29 */ , "Full Burst"
	/*  30 */ , "Tiger Blast"
	/*  31 */ , "Judgement Blade"
	/*  32 */ , "Sonic Dancer"
};

const char * const k_magic_desc[NUM_MAGICS] = {
	/*           123456789-123456789-123456789-123456 */
	/*   0 */   "Recovers HP"
	/*   1 */ , "Return to dungeon entrance"
	/*   2 */ , "Raises AGL for a brief duration"
	/*   3 */ , "Raises DEF for a brief duration"
	/*   4 */ , "Prevents DUR damage for a duration"
	/*   5 */ , "Enchant weapon with lightning"
	/*   6 */ , "Enchant weapon with fire"
	/*   7 */ , "Enchant weapon with water"
	/*   8 */ , "Enchant weapon with wind"

	/*   9 */ , "Recovers HP or revives when fallen"
	/*  10 */ , "DUR recovers when weapon breaks"
	/*  11 */ , "Damage inflicted recovers HP"
	/*  12 */ , "Damage caused by magic is reduced"

	/*  13 */ , "Mid-range lightning attack"
	/*  14 */ , "Mid-range fire attack"
	/*  15 */ , "Mid-range water attack"
	/*  16 */ , "Mid-range wind attack"
	/*  17 */ , "Wide-range lightning attack"
	/*  18 */ , "Wide-range fire attack"
	/*  19 */ , "Wide-range water attack"
	/*  20 */ , "Wide-range wind attack"

	/*  21 */ , "Switch to your partner"
	/*  22 */ , "Switch to your partner"
	/*  23 */ , "Switch to your partner"
	/*  24 */ , "Switch to your partner"
	/*  25 */ , "Switch to your true partner"
	/*  26 */ , "Switch to your true partner"
	/*  27 */ , "Switch to your true partner"
	/*  28 */ , "Switch to your true partner"

	/*  29 */ , "Powerful magic against all enemies"
	/*  30 */ , "Powerful magic against all enemies"
	/*  31 */ , "Powerful magic against all enemies"
	/*  32 */ , "Powerful magic against all enemies"
};
