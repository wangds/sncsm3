/* beast.c
 */

#include <stdlib.h>
#include "table/beast.h"

const char * const k_beast_name[NUM_BEASTS] = {
	/*           123456789-123456 */
	/*   0 */   "Slime"
	/*   1 */ , NULL
	/*   2 */ , "Spinner"
	/*   3 */ , "Hopdog"
	/*   4 */ , "Escaroo"
	/*   5 */ , "Strawboy"
	/*   6 */ , NULL
	/*   7 */ , "Crystanare"
	/*   8 */ , "Bugball"
	/*   9 */ , "Gazaille"
	/*  10 */ , NULL
	/*  11 */ , NULL
	/*  12 */ , "Striker"
	/*  13 */ , "Wolgan"
	/*  14 */ , NULL
	/*  15 */ , "Popper"
	/*  16 */ , NULL
	/*  17 */ , NULL
	/*  18 */ , "Gremlin"
	/*  19 */ , "Cuckoo"
	/*  20 */ , "Kero Ninja"
	/*  21 */ , "Defender"
	/*  22 */ , NULL
	/*  23 */ , NULL
	/*  24 */ , NULL
	/*  25 */ , NULL
	/*  26 */ , "Cattan"
	/*  27 */ , "Gunnerhead"
	/*  28 */ , NULL
	/*  29 */ , "Red Pincher"
	/*  30 */ , "Yasha Spider"
	/*  31 */ , "Pumpkeeno"
	/*  32 */ , "Jumper"
	/*  33 */ , NULL
	/*  34 */ , "Titanper"
	/*  35 */ , "Kero Oyabun"
	/*  36 */ , NULL
	/*  37 */ , "Boulderhide"
	/*  38 */ , NULL
	/*  39 */ , "Red Gremlin"
	/*  40 */ , NULL
	/*  41 */ , NULL
	/*  42 */ , "Hound"
	/*  43 */ , NULL
	/*  44 */ , "Clobber Rex"
	/*  45 */ , "Brute Monk"
	/*  46 */ , NULL
	/*  47 */ , NULL
	/*  48 */ , NULL
	/*  49 */ , "Duston"

	/*           123456789-123456 */
	/*  50 */ , "Mud Boxer"
	/*  51 */ , NULL
	/*  52 */ , NULL
	/*  53 */ , "Grappler"
	/*  54 */ , "Octaco"
	/*  55 */ , "Ikaroo"
	/*  56 */ , "TeruTeru"
	/*  57 */ , "Sahagin"
	/*  58 */ , NULL
	/*  59 */ , NULL
	/*  60 */ , NULL
	/*  61 */ , "Giant Serpent"
	/*  62 */ , NULL
	/*  63 */ , "Dragon Puppy"
	/*  64 */ , "Onibi"
	/*  65 */ , NULL
	/*  66 */ , "Fire Mage"
	/*  67 */ , NULL
	/*  68 */ , NULL
	/*  69 */ , "Red Dragon"
	/*  70 */ , NULL
	/*  71 */ , NULL
	/*  72 */ , "Bolt Striker"
	/*  73 */ , NULL
	/*  74 */ , NULL
	/*  75 */ , NULL
	/*  76 */ , NULL
	/*  77 */ , NULL
	/*  78 */ , "Pomdog"
	/*  79 */ , NULL
	/*  80 */ , "Smoggro"
	/*  81 */ , "Brownie"
	/*  82 */ , "Windleon"
	/*  83 */ , "Lizardio"
	/*  84 */ , NULL
	/*  85 */ , "Tsuchigumo"
	/*  86 */ , "Headache"
	/*  87 */ , "Spirit"
	/*  88 */ , "Squibolt"
	/*  89 */ , NULL
	/*  90 */ , NULL
	/*  91 */ , NULL
	/*  92 */ , "Dark Demon"
	/*  93 */ , "Tumbler"
	/*  94 */ , NULL
	/*  95 */ , NULL
	/*  96 */ , NULL
	/*  97 */ , "Clock Knight"
	/*  98 */ , "Iron Giant"
	/*  99 */ , "Kijo Spider"

	/*           123456789-123456 */
	/* 100 */ , "Heavy Metal"
	/* 101 */ , "Grudge Fish"
	/* 102 */ , NULL
	/* 103 */ , NULL
	/* 104 */ , NULL
	/* 105 */ , NULL
	/* 106 */ , NULL
	/* 107 */ , NULL
	/* 108 */ , NULL
	/* 109 */ , NULL
	/* 110 */ , NULL
	/* 111 */ , NULL
	/* 112 */ , "Hannya"
	/* 113 */ , NULL
	/* 114 */ , "Flame Mage"
	/* 115 */ , NULL
	/* 116 */ , NULL
	/* 117 */ , "Dark Dragon"
	/* 118 */ , "Winderdog"
	/* 119 */ , NULL
	/* 120 */ , "Foggro"
	/* 121 */ , NULL
	/* 122 */ , "Chamedeon"
	/* 123 */ , NULL
	/* 124 */ , NULL
	/* 125 */ , "Onigumo"
	/* 126 */ , "Death Head"
	/* 127 */ , NULL
	/* 128 */ , NULL
	/* 129 */ , NULL
	/* 130 */ , NULL
	/* 131 */ , "Death Manty"
	/* 132 */ , NULL
	/* 133 */ , NULL
	/* 134 */ , NULL
	/* 135 */ , NULL
	/* 136 */ , NULL
	/* 137 */ , NULL
	/* 138 */ , NULL
	/* 139 */ , NULL
	/* 140 */ , "Death Manty"
};

const char * const k_beast_desc[NUM_BEASTS] = {
	/*           123456789-123456789-123456789-123456789-123456789-1234 */
	/*   0 */   "Odd life form   that can freely   change its shape"
	/*   1 */ , NULL
	/*   2 */ , "Propeller blades  constantly spin   to stay aloft"
	/*   3 */ , "Fluffy dog that   flies with its  ears"
	/*   4 */ , "This bug used to  a treat for some  but not anymore"
	/*   5 */ , "Can't compete   in debates"
	/*   6 */ , NULL
	/*   7 */ , "Not aerodynamic,  but can fly   anyway"
	/*   8 */ , "It hates going  to the dentist"
	/*   9 */ , "Usually gentle,   but may breathe   fire when mad"
	/*  10 */ , NULL
	/*  11 */ , NULL
	/*  12 */ , "Watch the sky,  cuz here comes  Striker!"
	/*  13 */ , NULL
	/*  14 */ , NULL
	/*  15 */ , "Highly mobile   robot designed  to stop thieves"
	/*  16 */ , NULL
	/*  17 */ , NULL
	/*  18 */ , "Though it looks   cuddly, it's not  friendly at all"
	/*  19 */ , "Ill-tempered  bird; protective  of its territory"
	/*  20 */ , "It looks like a   frog, but it's  a real ninja!"
	/*  21 */ , "Mechanoid built   to defend from  intruders"
	/*  22 */ , NULL
	/*  23 */ , NULL
	/*  24 */ , NULL
	/*  25 */ , NULL
	/*  26 */ , "Tiny, but hard  as nails"
	/*  27 */ , "Caution!  Armed and   dangerous"
	/*  28 */ , NULL
	/*  29 */ , "It's huge and   hard, but it's  still just a bug"
	/*  30 */ , "A ferocious   spider with the   face of a demon"
	/*  31 */ , "A cursed pumpkin  that hops around"
	/*  32 */ , "Has the highest   jumping ability   of its class"
	/*  33 */ , NULL
	/*  34 */ , "Ex-construction   worker, now   tuned to destroy"
	/*  35 */ , "Kero Ninja with   real ultimate   power"
	/*  36 */ , NULL
	/*  37 */ , "This monster  has a problem   with dry skin"
	/*  38 */ , NULL
	/*  39 */ , "Also known as   the Demon Kid,  even if grown-up"
	/*  40 */ , NULL
	/*  41 */ , NULL
	/*  42 */ , "A vicious wolf  with fangs that   pierce steel"
	/*  43 */ , NULL
	/*  44 */ , "Big jaws and  spiky tail make   a mean combo"
	/*  45 */ , "Mighty brute  that heeds to   no blade"
	/*  46 */ , NULL
	/*  47 */ , NULL
	/*  48 */ , NULL
	/*  49 */ , "Said to respond   to voice  commands"

	/*           123456789-123456789-123456789-123456789-123456789-1234 */
	/*  50 */ , "Its body is   made entirely of  mud and slime"
	/*  51 */ , NULL
	/*  52 */ , NULL
	/*  53 */ , "He will,  he will,  shock you!"
	/*  54 */ , "The pot on its  head was found  on the seafloor"
	/*  55 */ , "A squid   living in a   snail shell"
	/*  56 */ , "A monster that  chases rain   clouds away"
	/*  57 */ , "A savage marine   race that fights  any outsiders"
	/*  58 */ , NULL
	/*  59 */ , NULL
	/*  60 */ , NULL
	/*  61 */ , "Unpopular fish  among fishermen;  it tastes bad"
	/*  62 */ , NULL
	/*  63 */ , "It's cute, but  don't forget  it's a dragon"
	/*  64 */ , "A fire-breathing  floating..mask?"
	/*  65 */ , NULL
	/*  66 */ , "Always angry,   there's no room   for talk"
	/*  67 */ , NULL
	/*  68 */ , NULL
	/*  69 */ , "Its fiery breath  will burn past  your defense"
	/*  70 */ , NULL
	/*  71 */ , NULL
	/*  72 */ , "It loves to fly   so much that it   never lands"
	/*  73 */ , NULL
	/*  74 */ , NULL
	/*  75 */ , NULL
	/*  76 */ , NULL
	/*  77 */ , NULL
	/*  78 */ , "Don't be fooled;  it's not a  stuffed animal"
	/*  79 */ , NULL
	/*  80 */ , "A smoke monster   said to be born   from pollution"
	/*  81 */ , "Mischievous   and sly little  fellow"
	/*  82 */ , "Powerful wings  flap to attack  with whirlwinds"
	/*  83 */ , "A martial artist  lizard man that   trains everyday"
	/*  84 */ , NULL
	/*  85 */ , "Having~4 arms is  very handy, even  out of combat"
	/*  86 */ , "It used to have   a body..but   now it's gone"
	/*  87 */ , "Uses lightning  to shock foes"
	/*  88 */ , "Sometimes used  as a living   battery"
	/*  89 */ , NULL
	/*  90 */ , NULL
	/*  91 */ , NULL
	/*  92 */ , "Carries a big   scythe that   reaps souls"
	/*  93 */ , "When you see  it rolling, run!"
	/*  94 */ , NULL
	/*  95 */ , NULL
	/*  96 */ , NULL
	/*  97 */ , "Gets wound up   easily"
	/*  98 */ , "Pink, but   still dangerous"
	/*  99 */ , "Evil red spider   that curses you   when cornered"

	/*           123456789-123456789-123456789-123456789-123456789-1234 */
	/* 100 */ , "Clamps down   on double   parked cars"
	/* 101 */ , "An odd fish   that learned to   live in snow"
	/* 102 */ , NULL
	/* 103 */ , NULL
	/* 104 */ , NULL
	/* 105 */ , NULL
	/* 106 */ , NULL
	/* 107 */ , NULL
	/* 108 */ , NULL
	/* 109 */ , NULL
	/* 110 */ , NULL
	/* 111 */ , NULL
	/* 112 */ , "A mask of fire  that burns like   mad"
	/* 113 */ , NULL
	/* 114 */ , "Only you can  prevent Stray   Summon fire"
	/* 115 */ , NULL
	/* 116 */ , NULL
	/* 117 */ , "Loves the dark  and never goes  under the sun"
	/* 118 */ , "Likes to throw  children down   wells"
	/* 119 */ , NULL
	/* 120 */ , "Its body is fog   but its fist is   hard and fierce"
	/* 121 */ , NULL
	/* 122 */ , "Watch its tongue  or you'll be  licked"
	/* 123 */ , NULL
	/* 124 */ , NULL
	/* 125 */ , "Loves to wear   tall sandals  when going out"
	/* 126 */ , "One bite and it   will knock you  out for a month"
	/* 127 */ , NULL
	/* 128 */ , NULL
	/* 129 */ , NULL
	/* 130 */ , NULL
	/* 131 */ , "There's no  reasoning with  this lunatic"
	/* 132 */ , NULL
	/* 133 */ , NULL
	/* 134 */ , NULL
	/* 135 */ , NULL
	/* 136 */ , NULL
	/* 137 */ , NULL
	/* 138 */ , NULL
	/* 139 */ , NULL
	/* 140 */ , "There's no  reasoning with  this lunatic"
};
