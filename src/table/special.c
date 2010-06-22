/* special.c
 */

#include "table/special.h"

const char * const k_special_name[NUM_SPECIALS] = {
	/*           123456789-123456 */
	/*   0 */   "Thunder Shot"
	/*   1 */ , "Thunder Spike"
	/*   2 */ , "Thunder Burst"
	/*   3 */ , "Flame Shot"
	/*   4 */ , "Flame Blow"
	/*   5 */ , "Flame Burst"
	/*   6 */ , "Water Shot"
	/*   7 */ , "Water Bash"
	/*   8 */ , "Water Burst"
	/*   9 */ , "Aero Shot"
	/*  10 */ , "Aero Storm"
	/*  11 */ , "Aero Burst"
	/*  12 */ , "Shine Shot"
	/*  13 */ , "Shine Bash"
	/*  14 */ , "Shine Burst"

	/*  15 */ , "~2 Hit Combo"
	/*  16 */ , "~3 Hit Combo"
	/*  17 */ , "~4 Hit Combo"
	/*  18 */ , "~5 Hit Combo"
	/*  19 */ , "Fast~3 Hit Combo"
	/*  20 */ , "Fast~5 Hit Combo"

	/*  21 */ , "Vacuum Slash"
	/*  22 */ , "Vibrating Wave"
	/*  23 */ , "Mach Spin"
	/*  24 */ , "Throw"
	/*  25 */ , "Hundred Fists"
	/*  26 */ , "Drill Hurricane"
	/*  27 */ , "Power Shot"
	/*  28 */ , "Rapid Shot"
	/*  29 */ , "Arrow Fall"

	/*  30 */ , "DUR Attack"
	/*  31 */ , "Trick Attack"
	/*  32 */ , "Leap Attack"
	/*  33 */ , "Footbash"
	/*  34 */ , "Cutbash"
	/*  35 */ , "Charge"
	/*  36 */ , "Quick Movement"
	/*  37 */ , "Defense Up"
	/*  38 */ , "Attack Up"
	/*  39 */ , "Speed Up"

	/*  40 */ , "Off DUR Shield"
	/*  41 */ , "Def DUR Shield"
	/*  42 */ , "DUR Divider"
	/*  43 */ , "HP Convert"
};

const char * const k_special_desc[NUM_SPECIALS] = {
	/*           123456789-123456789-123456789-123456 */
	/*   0 */   "Fires a small L-ranged Thunder ball"
	/*   1 */ , "Fires a large M-ranged Thunder ball"
	/*   2 */ , "Creates a S-ranged Thunder attack"
	/*   3 */ , "Fires a small L-ranged Fire ball"
	/*   4 */ , "Fires a large M-ranged Fire ball"
	/*   5 */ , "Creates a S-ranged Fire attack"
	/*   6 */ , "Fires a small L-ranged Water ball"
	/*   7 */ , "Fires a large M-ranged Water ball"
	/*   8 */ , "Creates a S-ranged Water attack"
	/*   9 */ , "Fires a small L-ranged Wind ball"
	/*  10 */ , "Fires a large M-ranged Wind ball"
	/*  11 */ , "Creates a S-ranged Wind attack"
	/*  12 */ , "Fires a small L-ranged Light ball"
	/*  13 */ , "Fires a large M-ranged Light ball"
	/*  14 */ , "Creates a S-ranged Light attack"

	/*  15 */ , "Attacks ~2 times consecutively"
	/*  16 */ , "Attacks ~3 times consecutively"
	/*  17 */ , "Attacks ~4 times consecutively"
	/*  18 */ , "Attacks ~5 times consecutively"
	/*  19 */ , "Attacks ~3 times consecutively"
	/*  20 */ , "Attacks ~5 times consecutively"

	/*  21 */ , "Creates a S-ranged shock wave"
	/*  22 */ , "Creates a S-ranged violent tremor"
	/*  23 */ , "A continuous spear spin attack"
	/*  24 */ , "Throws an enemy"
	/*  25 */ , "Launches a number of attacks"
	/*  26 */ , "Creates a hurricane"
	/*  27 */ , "Fires a powerful L-ranged attack"
	/*  28 */ , "Fires multiple arrows frontward"
	/*  29 */ , "Fires multiple arrows in the air"

	/*  30 */ , "Damages the opponent's DUR"
	/*  31 */ , "Attacks with all equipped weapons"
	/*  32 */ , "A leaping upward attack"
	/*  33 */ , "Blows the enemy away"
	/*  34 */ , "Sends the enemy to the air"
	/*  35 */ , "Amasses energy for the next attack"
	/*  36 */ , "Moving forward at high speed"
	/*  37 */ , "Temporarily boosts DEF, lowers ATK"
	/*  38 */ , "Temporarily boosts ATK, lowers DEF"
	/*  39 */ , "Temporarily increases AGL"

	/*  40 */ , "Attacking uses no DUR temporarily"
	/*  41 */ , "Blocking uses no DUR temporarily"
	/*  42 */ , "Divides DUR with equipped weapons"
	/*  43 */ , "Recovers HP as DUR bar depletes"
};
