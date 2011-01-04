/* weapon.c
 */

#include <stdlib.h>
#include "table/weapon.h"

const char * const k_weapon_name[NUM_WEAPONS] = {
	/*           123456789-123456 */
	/*   0 */   "Amateur Knife"
	/*   1 */ , "Needle Rapier"
	/*   2 */ , "Hard Dagger"
	/*   3 */ , "Grave Edge"
	/*   4 */ , "Iron Sword"
	/*   5 */ , "Synthetic Blade"
	/*   6 */ , "Feather Knife"
	/*   7 */ , "Slicer Sabre"
	/*   8 */ , "Rage Sabre"
	/*   9 */ , "Punishment Sword"
	/*  10 */ , "Survival Sword"
	/*  11 */ , "Elegant Knife"
	/*  12 */ , "Ribbon Sabre"
	/*  13 */ , "Shell Sword"
	/*  14 */ , "Dark Kunai"
	/*  15 */ , "Vanity Foil"
	/*  16 */ , "Common Sabre"
	/*  17 */ , "Judgement Dagger"
	/*  18 */ , "Sash Sword"
	/*  19 */ , "Gimmick Buster"
	/*  20 */ , "Return Knife"
	/*  21 */ , "Iron Rod"
	/*  22 */ , "Celeb Killer"
	/*  23 */ , "Twin-Snake Blade"
	/*  24 */ , "Splendid Sword"
	/*  25 */ , "Excel Sabre"
	/*  26 */ , "High Blade"
	/*  27 */ , "Resist Sabre"
	/*  28 */ , "Grace Foil"
	/*  29 */ , "Rune Edge"
	/*  30 */ , "Sledge Eel"
	/*  31 */ , "Wise Edge"
	/*  32 */ , "Fang Sabre"
	/*  33 */ , "Gardenir"
	/*  34 */ , "Ninja Sword"
	/*  35 */ , "Nyan Buster"
	/*  36 */ , "Chain Sword"
	/*  37 */ , "Crimson Sword"
	/*  38 */ , "Curse Tailer"
	/*  39 */ , "Astral Edge"

	/*           123456789-123456 */
	/*  40 */ , "Amateur Axe"
	/*  41 */ , "Needle Axe"
	/*  42 */ , "Hard Axe"
	/*  43 */ , "Grave Axe"
	/*  44 */ , "Iron Axe"
	/*  45 */ , "Lead Axe"
	/*  46 */ , "Feather Axe"
	/*  47 */ , "Slicer Axe"
	/*  48 */ , "Rage Axe"
	/*  49 */ , "Punishment Axe"
	/*  50 */ , "Survival Axe"
	/*  51 */ , "Elegant Axe"
	/*  52 */ , "Ribbon Crusher"
	/*  53 */ , "Shell Axe"
	/*  54 */ , "Dark Kama"
	/*  55 */ , "Vanity Maul"
	/*  56 */ , "Common Axe"
	/*  57 */ , "Judgement Axe"
	/*  58 */ , "Sash Hammer"
	/*  59 */ , "Gimmick Bhuj"
	/*  60 */ , "Burning Axe"
	/*  61 */ , "Morning Star"
	/*  62 */ , "Celeb Crusher"
	/*  63 */ , "Twin-Snake Axe"
	/*  64 */ , "Splendid Axe"
	/*  65 */ , "Excel Axe"
	/*  66 */ , "High Axe"
	/*  67 */ , "Resist Axe"
	/*  68 */ , "Grace Basher"
	/*  69 */ , "Rune Zamber"
	/*  70 */ , "Sledge Judge"
	/*  71 */ , "Wise Axe"
	/*  72 */ , "Fang Axe"
	/*  73 */ , "Gardeninga"
	/*  74 */ , "Large Shuriken"
	/*  75 */ , "Nyaxs"
	/*  76 */ , "Gear Axe"
	/*  77 */ , "Crimson Axe"
	/*  78 */ , "Curse Madder"
	/*  79 */ , "Astral Axe"

	/*           123456789-123456 */
	/*  80 */ , "Amateur Spear"
	/*  81 */ , "Needle Spear"
	/*  82 */ , "Hard Pole"
	/*  83 */ , "Grave Spear"
	/*  84 */ , "Iron Pole"
	/*  85 */ , "Spear Vocal"
	/*  86 */ , "Feather Pole"
	/*  87 */ , "Slicer Pike"
	/*  88 */ , "Rage Pole"
	/*  89 */ , "Punishment Spear"
	/*  90 */ , "Survival Spear"
	/*  91 */ , "Elegant Pole"
	/*  92 */ , "Ribbon Staff"
	/*  93 */ , "Shell Spear"
	/*  94 */ , "Dark Halberd"
	/*  95 */ , "Vanity Lance"
	/*  96 */ , "Common Spear"
	/*  97 */ , "Judgement Spear"
	/*  98 */ , "Sash Pike"
	/*  99 */ , "Gimmick Spear"
	/* 100 */ , "Battle Fork"
	/* 101 */ , "Hexagonal Staff"
	/* 102 */ , "Celeb Spear"
	/* 103 */ , "Twin-Snake Lance"
	/* 104 */ , "Splendid Pike"
	/* 105 */ , "Excel Pike"
	/* 106 */ , "High Pole"
	/* 107 */ , "Resist Pole"
	/* 108 */ , "Grace Staff"
	/* 109 */ , "Rune Stinger"
	/* 110 */ , "Sledge Zephyr"
	/* 111 */ , "Wise Pole"
	/* 112 */ , "Fang Spear"
	/* 113 */ , "Garde-Pole"
	/* 114 */ , "Hook Pole"
	/* 115 */ , "Nyan Killer"
	/* 116 */ , "Metal Arm"
	/* 117 */ , "Crimson Halberd"
	/* 118 */ , "Curse Tirio"
	/* 119 */ , "Astral Pike"

	/*           123456789-123456 */
	/* 120 */ , "Amateur Knuckles"
	/* 121 */ , "Needle Claws"
	/* 122 */ , "Hard Knuckles"
	/* 123 */ , "Grave Knuckles"
	/* 124 */ , "Iron Claws"
	/* 125 */ , "Beat Knuckles"
	/* 126 */ , "Feather Knuckles"
	/* 127 */ , "Slicer Knuckles"
	/* 128 */ , "Rage Knuckles"
	/* 129 */ , "Punishment Gaunt"
	/* 130 */ , "SurvivalKnuckles"
	/* 131 */ , "Elegant Claws"
	/* 132 */ , "Ribbon Claws"
	/* 133 */ , "Shell Claws"
	/* 134 */ , "Dark Gauntlet"
	/* 135 */ , "Vanity Knuckles"
	/* 136 */ , "Common Tooth"
	/* 137 */ , "Judgement Gaunt"
	/* 138 */ , "Sash Claws"
	/* 139 */ , "Gimmick Knuckles"
	/* 140 */ , "Quilt Knuckles"
	/* 141 */ , "IronBallGauntlet"
	/* 142 */ , "Celeb Knuckles"
	/* 143 */ , "Twin-Snake Claws"
	/* 144 */ , "Splendid Blow"
	/* 145 */ , "Excel Knuckles"
	/* 146 */ , "High Tusks"
	/* 147 */ , "Resist Claws"
	/* 148 */ , "Grace Grabber"
	/* 149 */ , "Rune Gaunt"
	/* 150 */ , "Sledge Iric"
	/* 151 */ , "Wise Knuckles"
	/* 152 */ , "Fang Claws"
	/* 153 */ , "Garde-Nick"
	/* 154 */ , "Kagitzume"
	/* 155 */ , "Catickles"
	/* 156 */ , "Shaft Knuckles"
	/* 157 */ , "Crimson Claws"
	/* 158 */ , "Curse Nogiru"
	/* 159 */ , "Astral Arm"

	/*           123456789-123456 */
	/* 160 */ , "Amateur Drill"
	/* 161 */ , "Needle Rotor"
	/* 162 */ , "Hard Rotor"
	/* 163 */ , "Grave Rotor"
	/* 164 */ , "Iron Drill"
	/* 165 */ , "Beat Rotor"
	/* 166 */ , "Feather Drill"
	/* 167 */ , "Slicer Drill"
	/* 168 */ , "Rage Drill"
	/* 169 */ , "Punishment Motor"
	/* 170 */ , "Survival Turbine"
	/* 171 */ , "Elegant Drill"
	/* 172 */ , "Ribbon Rotor"
	/* 173 */ , "Shell Motor"
	/* 174 */ , "Dark Motor"
	/* 175 */ , "Vanity Rotor"
	/* 176 */ , "Common Drill"
	/* 177 */ , "Judgement Drill"
	/* 178 */ , "Sash Rotor"
	/* 179 */ , "Gimmick Drill"
	/* 180 */ , "Hell Mixer"
	/* 181 */ , "Iron Cutter"
	/* 182 */ , "Celeb Rotor"
	/* 183 */ , "Twin-Snake Rotor"
	/* 184 */ , "Splendid Drill"
	/* 185 */ , "Excel Rotor"
	/* 186 */ , "High Needle"
	/* 187 */ , "Resist Rotor"
	/* 188 */ , "Grace Mixer"
	/* 189 */ , "Rune Mixer"
	/* 190 */ , "Sledge Eater"
	/* 191 */ , "Wise Rotor"
	/* 192 */ , "Fang Rotor"
	/* 193 */ , "Gardenitor"
	/* 194 */ , "Ninja Motor"
	/* 195 */ , "Nyarill"
	/* 196 */ , "Gear Rotor"
	/* 197 */ , "Crimson Tool"
	/* 198 */ , "Curse Tale"
	/* 199 */ , "Astral Spinner"

	/*           123456789-123456 */
	/* 200 */ , "Amateur Bow"
	/* 201 */ , "Needle Bow"
	/* 202 */ , "Hard Bow"
	/* 203 */ , "Grave Arrow"
	/* 204 */ , "Iron Arrow"
	/* 205 */ , "Beat Arrow"
	/* 206 */ , "Feather Bow"
	/* 207 */ , "Slicer Arrow"
	/* 208 */ , "Rage Bow"
	/* 209 */ , "Punishment Yumi"
	/* 210 */ , "Survival Bow"
	/* 211 */ , "Elegant Arrow"
	/* 212 */ , "Ribbon Arrow"
	/* 213 */ , "Shell Yumi"
	/* 214 */ , "Dark Yumi"
	/* 215 */ , "Vanity Arrow"
	/* 216 */ , "Common Arrow"
	/* 217 */ , "Judgement Yumi"
	/* 218 */ , "Sash Bow"
	/* 219 */ , "Gimmick Bow"
	/* 220 */ , "Spoon Arrow"
	/* 221 */ , "Iron Ball Yumi"
	/* 222 */ , "Celeb Arrow"
	/* 223 */ , "Twin-Snake Arrow"
	/* 224 */ , "Splendid Bow"
	/* 225 */ , "Excel Arrow"
	/* 226 */ , "High Arrow"
	/* 227 */ , "Resist Arrow"
	/* 228 */ , "Grace Bow"
	/* 229 */ , "Rune Deeper"
	/* 230 */ , "Seldge Volver"
	/* 231 */ , "Wise Bow"
	/* 232 */ , "Fang Arrow"
	/* 233 */ , "Garde-Gun"
	/* 234 */ , "Ninja Yumi"
	/* 235 */ , "Nyarrow"
	/* 236 */ , "Clock Arrow"
	/* 237 */ , "Crimson Yumi"
	/* 238 */ , "Curse Cherry"
	/* 239 */ , "Astral Arrow"

	/*           123456789-123456 */
	/* 240 */ , "Sword Shapestone"
	/* 241 */ , "Axe Shapestone"
	/* 242 */ , "Spear Shapestone"
	/* 243 */ , "Fist Shapestone"
	/* 244 */ , "Drill Shapestone"
	/* 245 */ , "Bow Shapestone"
};

const char * const k_weapon_desc[NUM_WEAPONS] = {
	/*           123456789-123456789-123456789-123456 */
	/*   0 */   "Basic, multi-purpose knife"
	/*   1 */ , NULL
	/*   2 */ , "A tad heavy, but easy to handle"
	/*   3 */ , NULL
	/*   4 */ , NULL
	/*   5 */ , NULL
	/*   6 */ , NULL
	/*   7 */ , NULL
	/*   8 */ , NULL
	/*   9 */ , NULL
	/*  10 */ , NULL
	/*  11 */ , NULL
	/*  12 */ , "Light and elegant"
	/*  13 */ , "This blade is harder than steel"
	/*  14 */ , NULL
	/*  15 */ , NULL
	/*  16 */ , NULL
	/*  17 */ , NULL
	/*  18 */ , NULL
	/*  19 */ , NULL
	/*  20 */ , NULL
	/*  21 */ , NULL
	/*  22 */ , NULL
	/*  23 */ , NULL
	/*  24 */ , NULL
	/*  25 */ , NULL
	/*  26 */ , NULL
	/*  27 */ , NULL
	/*  28 */ , NULL
	/*  29 */ , NULL
	/*  30 */ , NULL
	/*  31 */ , NULL
	/*  32 */ , NULL
	/*  33 */ , NULL
	/*  34 */ , "It's the real thing!"
	/*  35 */ , "What a cute sword.."
	/*  36 */ , NULL
	/*  37 */ , NULL
	/*  38 */ , NULL
	/*  39 */ , "The last sword you'll ever want"

	/*           123456789-123456789-123456789-123456 */
	/*  40 */ , "A light beginner's axe"
	/*  41 */ , NULL
	/*  42 */ , "Heavy, so it cuts deeper"
	/*  43 */ , NULL
	/*  44 */ , NULL
	/*  45 */ , NULL
	/*  46 */ , NULL
	/*  47 */ , NULL
	/*  48 */ , NULL
	/*  49 */ , NULL
	/*  50 */ , NULL
	/*  51 */ , NULL
	/*  52 */ , "Ribbons give it a glamorous touch"
	/*  53 */ , "More powerful than a steel axe"
	/*  54 */ , NULL
	/*  55 */ , NULL
	/*  56 */ , NULL
	/*  57 */ , "Great axe of judgement"
	/*  58 */ , NULL
	/*  59 */ , NULL
	/*  60 */ , NULL
	/*  61 */ , NULL
	/*  62 */ , NULL
	/*  63 */ , NULL
	/*  64 */ , NULL
	/*  65 */ , NULL
	/*  66 */ , NULL
	/*  67 */ , NULL
	/*  68 */ , NULL
	/*  69 */ , NULL
	/*  70 */ , NULL
	/*  71 */ , NULL
	/*  72 */ , NULL
	/*  73 */ , NULL
	/*  74 */ , NULL
	/*  75 */ , "A must have for cat lovers"
	/*  76 */ , "Tune the gears right for max power"
	/*  77 */ , NULL
	/*  78 */ , NULL
	/*  79 */ , "A legendary axe of divinity"

	/*           123456789-123456789-123456789-123456 */
	/*  80 */ , "Easy to grip, beginner's spear"
	/*  81 */ , NULL
	/*  82 */ , "Not quite a trident, but it works"
	/*  83 */ , NULL
	/*  84 */ , NULL
	/*  85 */ , NULL
	/*  86 */ , NULL
	/*  87 */ , NULL
	/*  88 */ , NULL
	/*  89 */ , NULL
	/*  90 */ , NULL
	/*  91 */ , NULL
	/*  92 */ , "Fancy and powerful"
	/*  93 */ , "More powerful than a steel spear"
	/*  94 */ , NULL
	/*  95 */ , NULL
	/*  96 */ , NULL
	/*  97 */ , "Long spear of judgement"
	/*  98 */ , NULL
	/*  99 */ , NULL
	/* 100 */ , NULL
	/* 101 */ , NULL
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
	/* 112 */ , NULL
	/* 113 */ , NULL
	/* 114 */ , NULL
	/* 115 */ , "For the lover of cats"
	/* 116 */ , NULL
	/* 117 */ , NULL
	/* 118 */ , NULL
	/* 119 */ , "Divine lance of the heavens"

	/*           123456789-123456789-123456789-123456 */
	/* 120 */ , "Beginner's knuckles"
	/* 121 */ , NULL
	/* 122 */ , NULL
	/* 123 */ , NULL
	/* 124 */ , NULL
	/* 125 */ , NULL
	/* 126 */ , NULL
	/* 127 */ , NULL
	/* 128 */ , NULL
	/* 129 */ , "Punishment gauntlet"
	/* 130 */ , NULL
	/* 131 */ , NULL
	/* 132 */ , "Don't be fooled by the ribbons"
	/* 133 */ , "More powerful than steel"
	/* 134 */ , NULL
	/* 135 */ , NULL
	/* 136 */ , NULL
	/* 137 */ , "Judgement gauntlet"
	/* 138 */ , NULL
	/* 139 */ , "Surprisingly useful"
	/* 140 */ , NULL
	/* 141 */ , NULL
	/* 142 */ , NULL
	/* 143 */ , NULL
	/* 144 */ , NULL
	/* 145 */ , NULL
	/* 146 */ , NULL
	/* 147 */ , NULL
	/* 148 */ , NULL
	/* 149 */ , NULL
	/* 150 */ , NULL
	/* 151 */ , NULL
	/* 152 */ , NULL
	/* 153 */ , NULL
	/* 154 */ , NULL
	/* 155 */ , "Cat scratch fever!"
	/* 156 */ , NULL
	/* 157 */ , NULL
	/* 158 */ , NULL
	/* 159 */ , "The glove of champions!"

	/*           123456789-123456789-123456789-123456 */
	/* 160 */ , "Beginner's drill"
	/* 161 */ , NULL
	/* 162 */ , "Spins quickly for better stability"
	/* 163 */ , NULL
	/* 164 */ , NULL
	/* 165 */ , NULL
	/* 166 */ , NULL
	/* 167 */ , NULL
	/* 168 */ , NULL
	/* 169 */ , NULL
	/* 170 */ , NULL
	/* 171 */ , NULL
	/* 172 */ , "Ribbons disguise its deadliness"
	/* 173 */ , "Reduced heat from friction"
	/* 174 */ , NULL
	/* 175 */ , NULL
	/* 176 */ , NULL
	/* 177 */ , NULL
	/* 178 */ , NULL
	/* 179 */ , NULL
	/* 180 */ , NULL
	/* 181 */ , NULL
	/* 182 */ , NULL
	/* 183 */ , NULL
	/* 184 */ , NULL
	/* 185 */ , NULL
	/* 186 */ , NULL
	/* 187 */ , NULL
	/* 188 */ , NULL
	/* 189 */ , NULL
	/* 190 */ , NULL
	/* 191 */ , NULL
	/* 192 */ , NULL
	/* 193 */ , NULL
	/* 194 */ , "Silenced for stealth operations"
	/* 195 */ , "For the feline geologist"
	/* 196 */ , "Gear positioned for dual action"
	/* 197 */ , NULL
	/* 198 */ , NULL
	/* 199 */ , "The acme of all drillhood"

	/*           123456789-123456789-123456789-123456 */
	/* 200 */ , "Beginner's bow"
	/* 201 */ , NULL
	/* 202 */ , NULL
	/* 203 */ , NULL
	/* 204 */ , NULL
	/* 205 */ , NULL
	/* 206 */ , NULL
	/* 207 */ , NULL
	/* 208 */ , NULL
	/* 209 */ , NULL
	/* 210 */ , NULL
	/* 211 */ , NULL
	/* 212 */ , NULL
	/* 213 */ , "More powerful than a steel bow"
	/* 214 */ , NULL
	/* 215 */ , NULL
	/* 216 */ , NULL
	/* 217 */ , NULL
	/* 218 */ , NULL
	/* 219 */ , NULL
	/* 220 */ , NULL
	/* 221 */ , NULL
	/* 222 */ , NULL
	/* 223 */ , NULL
	/* 224 */ , NULL
	/* 225 */ , NULL
	/* 226 */ , NULL
	/* 227 */ , NULL
	/* 228 */ , NULL
	/* 229 */ , NULL
	/* 230 */ , NULL
	/* 231 */ , NULL
	/* 232 */ , NULL
	/* 233 */ , NULL
	/* 234 */ , NULL
	/* 235 */ , NULL
	/* 236 */ , NULL
	/* 237 */ , NULL
	/* 238 */ , NULL
	/* 239 */ , NULL

	/*           123456789-123456789-123456789-123456 */
	/* 240 */ , "Base material for swords"
	/* 241 */ , "Base material for axes"
	/* 242 */ , "Base material for spears"
	/* 243 */ , "Base material for knuckles"
	/* 244 */ , "Base material for drills"
	/* 245 */ , "Base material for bows"
};
