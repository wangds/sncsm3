/* item.c
 */

#include <stdlib.h>
#include "item.h"

const char * const k_item_name[NUM_ITEMS] = {
	/*           123456789-123456 */
	/*   0 */   "Bandage"
	/*   1 */ , "Kicker Potion"
	/*   2 */ , "Heartleaf Potion"
	/*   3 */ , "Softboiled Egg"
	/*   4 */ , "Egg Fried Rice"
	/*   5 */ , "Spicy Curry"
	/*   6 */ , "Med Kit"
	/*   7 */ , "Rubstone"
	/*   8 */ , "Whetstone"
	/*   9 */ , "Grinding Stone"
	/*  10 */ , "Anywhere Diary"
	/*  11 */ , "Portal Stone"
	/*  12 */ , "Repellent Amulet"
	/*  13 */ , "Lure Charm"
	/*  14 */ , "Kicker Berry"
	/*  15 */ , "Heartleaf Berry"
	/*  16 */ , "El Fruit"
	/*  17 */ , "Sticky Tree Sap"
	/*  18 */ , "Ripe Berry"
	/*  19 */ , "Flat Stone"
	/*  20 */ , "Polish Stone"
	/*  21 */ , "Zasso Leaf"
	/*  22 */ , "Fluff Grass"
	/*  23 */ , "Premium Paper"
	/*  24 */ , "Tree Branch"
	/*  25 */ , "Clean Paper"
	/*  26 */ , "Stinky Garlic"
	/*  27 */ , "Flower Syrup"
	/*  28 */ , "Soft Fur"
	/*  29 */ , "Durable Fur"
	/*  30 */ , "Quality Fur"
	/*  31 */ , "Flaming Spice"
	/*  32 */ , "Mystery Powder"
	/*  33 */ , "Pure Water"
	/*  34 */ , "Mystery Egg"
	/*  35 */ , "Pretty Egg"
	/*  36 */ , "Small Worm"
	/*  37 */ , "Yam"
	/*  38 */ , "Dried Shrimp"
	/*  39 */ , "Lobster"
	/*  40 */ , "Gourmet Clam"
	/*  41 */ , "Small Bomb"
	/*  42 */ , "Medium Bomb"
	/*  43 */ , "Large Bomb"
	/*  44 */ , "Poison Bomb"
	/*  45 */ , "Paralysis Bomb"
	/*  46 */ , "Sleep Bomb"
	/*  47 */ , "Rust Bomb"
	/*  48 */ , "Lucky Ticket"
	/*  49 */ , NULL

	/*           123456789-123456 */
	/*  50 */ , "Iron Ore"
	/*  51 */ , "Slend Gemstone"
	/*  52 */ , "Katyn Ore"
	/*  53 */ , "Akineel Ore"
	/*  54 */ , "Large Ore"
	/*  55 */ , "Elvin Gem"
	/*  56 */ , "Wing Fossil"
	/*  57 */ , "Slicer Ore"
	/*  58 */ , "Large Iron Ore"
	/*  59 */ , "Heavy Metal Ore"
	/*  60 */ , "Ranger Ore"
	/*  61 */ , "Yuuga Crystal"
	/*  62 */ , "Cute Gemstone"
	/*  63 */ , "Shell Fossil"
	/*  64 */ , "Black Ore"
	/*  65 */ , "Illusion Ore"
	/*  66 */ , "Common Gem"
	/*  67 */ , "Vanish Ore"
	/*  68 */ , "Sash Ore"
	/*  69 */ , "Gallia Ore"
	/*  70 */ , "Kitchen Ore"
	/*  71 */ , "Iron Edge Stone"
	/*  72 */ , "Nouvil Gem"
	/*  73 */ , "Twin-Snake Ore"
	/*  74 */ , "Splend Crystal"
	/*  75 */ , "Excel Ore"
	/*  76 */ , "Tree Fossil"
	/*  77 */ , "Resist Gem"
	/*  78 */ , "Yubis Crystal"
	/*  79 */ , "SecretRune Stone"
	/*  80 */ , "Wild Ore"
	/*  81 */ , "Wise Blade Ore"
	/*  82 */ , "Steel Fang Ore"
	/*  83 */ , "Gardening Ore"
	/*  84 */ , "Ninja Ore"
	/*  85 */ , "Paw Fossil"
	/*  86 */ , "Mecha Gem"
	/*  87 */ , "Red Lotus Ore"
	/*  88 */ , "Cursed Ore"
	/*  89 */ , "Shining Ore"
	/*  90 */ , NULL
	/*  91 */ , NULL
	/*  92 */ , NULL
	/*  93 */ , NULL
	/*  94 */ , NULL
	/*  95 */ , NULL
	/*  96 */ , NULL
	/*  97 */ , NULL
	/*  98 */ , NULL
	/*  99 */ , NULL

	/*           123456789-123456 */
	/* 100 */ , "Battery"
	/* 101 */ , "Lightning Charm"
	/* 102 */ , "Thunder Shard"
	/* 103 */ , "Thunder Crystal"
	/* 104 */ , "Ignition Device"
	/* 105 */ , "Flame Charm"
	/* 106 */ , "Fire Shard"
	/* 107 */ , "Fire Crystal"
	/* 108 */ , "Water Tank"
	/* 109 */ , "Flow Charm"
	/* 110 */ , "Water Shard"
	/* 111 */ , "Water Crystal"
	/* 112 */ , "Ventilator"
	/* 113 */ , "Gale Charm"
	/* 114 */ , "Wind Shard"
	/* 115 */ , "Wind Crystal"
	/* 116 */ , "Back Light"
	/* 117 */ , "Flash Amulet"
	/* 118 */ , "Blood Pump"
	/* 119 */ , "Dark Sunglasses"
	/* 120 */ , "Wind-up key"
	/* 121 */ , "Accelerator"
	/* 122 */ , "Spirit Headband"
	/* 123 */ , "Four-Leaf Clover"
	/* 124 */ , "Spare Switch"
	/* 125 */ , "Secret Scroll"
	/* 126 */ , "Combat Scroll"
	/* 127 */ , "Alteration Guide"
	/* 128 */ , "Distribution Dev"
	/* 129 */ , "Switch of Ruin"
	/* 130 */ , "Paralysis Powder"
	/* 131 */ , "Poison Powder"
	/* 132 */ , "Sleeping Powder"
	/* 133 */ , "Rust Powder"
	/* 134 */ , "Power Crest"
	/* 135 */ , "Endurance Crest"
	/* 136 */ , "Expertise Crest"
	/* 137 */ , "Legendary Spring"
	/* 138 */ , "Insight Glasses"
	/* 139 */ , "Fighting Manual"
	/* 140 */ , "Lucky Charm"
	/* 141 */ , "Healthy Sandals"
	/* 142 */ , "Legendary Bamboo"
	/* 143 */ , "Old Rubstone"
	/* 144 */ , "Repair Parts"
	/* 145 */ , "Legendary Needle"
	/* 146 */ , "Will of Love"
	/* 147 */ , "Ultimate Motor"
	/* 148 */ , NULL
	/* 149 */ , NULL

	/*           123456789-123456 */
	/* 150 */ , "Metal Ring"
	/* 151 */ , "Katyn Ring"
	/* 152 */ , "Steel Ring"
	/* 153 */ , "Slicer Ring"
	/* 154 */ , "Survival Ring"
	/* 155 */ , "Shell Ring"
	/* 156 */ , "Common Ring"
	/* 157 */ , "Gallia Ring"
	/* 158 */ , "Celeb Ring"
	/* 159 */ , "High Ring"
	/* 160 */ , "Rune Ring"
	/* 161 */ , "Metal Bracelet"
	/* 162 */ , "Katyn Bracelet"
	/* 163 */ , "Steel Bracelet"
	/* 164 */ , "Slicer Bracelet"
	/* 165 */ , "SurvivalBracelet"
	/* 166 */ , "Shell Bracelet"
	/* 167 */ , "Common Bracelet"
	/* 168 */ , "Gallia Bracelet"
	/* 169 */ , "Celeb Bracelet"
	/* 170 */ , "High Bracelet"
	/* 171 */ , "Rune Bracelet"
	/* 172 */ , "Metal Boots"
	/* 173 */ , "Katyn Boots"
	/* 174 */ , "Steel Boots"
	/* 175 */ , "Slicer Boots"
	/* 176 */ , "Survival Boots"
	/* 177 */ , "Shell Boots"
	/* 178 */ , "Common Boots"
	/* 179 */ , "Gallia Boots"
	/* 180 */ , "Celeb Boots"
	/* 181 */ , "High Boots"
	/* 182 */ , "Rune Boots"
	/* 183 */ , "Vicious Boots"
	/* 184 */ , "Escape Boots"
	/* 185 */ , "Extension Ring"
	/* 186 */ , "Reextension Ring"
	/* 187 */ , "Assurance Ring"
	/* 188 */ , "Speed Bracelet"
	/* 189 */ , "Guard Bracelet"
	/* 190 */ , "Attack Bracelet"
	/* 191 */ , "Ability Ring"
	/* 192 */ , "Magic Bracelet"
	/* 193 */ , "Active Ring"
	/* 194 */ , "Insomnia Ring"
	/* 195 */ , "Detox Ring"
	/* 196 */ , "Plated Ring"
	/* 197 */ , NULL /* unused? */
	/* 198 */ , NULL /* unused? */
	/* 199 */ , "Smith Ring"

	/*           123456789-123456 */
	/* 200 */ , "Fishing Rod"
	/* 201 */ , "Fine Fishing Rod"
	/* 202 */ , "Legendary Rod"
	/* 203 */ , NULL /* unused? */
	/* 204 */ , NULL /* unused? */
	/* 205 */ , NULL /* unused? */
	/* 206 */ , "Member Pass"
	/* 207 */ , NULL /* unused? */
	/* 208 */ , NULL /* unused? */
	/* 209 */ , NULL /* unused? */
	/* 210 */ , NULL /* unused? */
	/* 211 */ , NULL /* unused? */
	/* 212 */ , NULL /* unused? */
	/* 213 */ , NULL /* unused? */
	/* 214 */ , NULL /* unused? */
	/* 215 */ , NULL /* unused? */
	/* 216 */ , NULL /* unused? */
	/* 217 */ , NULL /* unused? */
	/* 218 */ , NULL /* unused? */
	/* 219 */ , NULL /* unused? */
	/* 220 */ , NULL /* unused? */
	/* 221 */ , NULL /* unused? */
	/* 222 */ , NULL /* unused? */
	/* 223 */ , NULL /* unused? */
	/* 224 */ , "Axe Mastery"
	/* 225 */ , "Knuckle Mastery"
	/* 226 */ , "Sword Mastery"
	/* 227 */ , "Bow Mastery"
	/* 228 */ , "Spear Mastery"
	/* 229 */ , NULL /* unused? */
	/* 230 */ , "Drill Mastery"
	/* 231 */ , NULL /* unused? */
	/* 232 */ , "AquaDragon Scale"
};

const char * const k_item_desc[NUM_ITEMS] = {
	/*           123456789-123456789-123456789-123456 */
	/*   0 */   "Recovers  ~2~0~0 HP"
	/*   1 */ , "Recovers  ~3~5~0 HP"
	/*   2 */ , "Recovers  ~4~5~0 HP"
	/*   3 */ , "It has an addictive soft texture"
	/*   4 */ , "So good that you'll want to eat more"
	/*   5 */ , "It has an exciting spicy taste"
	/*   6 */ , "Resurrects you when you fall"
	/*   7 */ , "Recovers  ~5~0 DUR"
	/*   8 */ , "Recovers  ~1~5~0 DUR"
	/*   9 */ , "Recovers  ~3~0~0 DUR"
	/*  10 */ , "Allows you to save the game any time"
	/*  11 */ , "Warps you back to last visted town"
	/*  12 */ , "Lowers random encounter rate"
	/*  13 */ , "Raises random encounter rate"
	/*  14 */ , "Slightly sour, with a nice fragrance"
	/*  15 */ , "A hard, delightful-tasting fruit"
	/*  16 */ , "Very sweet fruit with medical uses"
	/*  17 */ , "Sticky, Sticky, and Sticky Tree Sap"
	/*  18 */ , "A tasteless over ripe fruit"
	/*  19 */ , "A thin soft textured stone"
	/*  20 */ , "Stone fragment for repairing weapons"
	/*  21 */ , "A leaf that grows anywhere"
	/*  22 */ , "A very soft frass with medical uses"
	/*  23 */ , "Durable paper, good for books"
	/*  24 */ , "A handy twig that can be held easily"
	/*  25 */ , "An extremely clean pure white cloth"
	/*  26 */ , "Smelly, but good for the body"
	/*  27 */ , "Nectar with a really sweet smell"
	/*  28 */ , "A well crafted soft piece of fur"
	/*  29 */ , "Durable piece of fur, slightly hard"
	/*  30 */ , "Brilliant piece of quality fur"
	/*  31 */ , "Spice with a strong smell"
	/*  32 */ , "A mysterious white powder"
	/*  33 */ , "Clear and nutritious natural water"
	/*  34 */ , "Common but don't know what it's from"
	/*  35 */ , "A pretty egg with a different colour"
	/*  36 */ , "Fish bait"
	/*  37 */ , "Fish bait"
	/*  38 */ , "Fish bait"
	/*  39 */ , "Fish bai~t/ Fit for a king"
	/*  40 */ , "Fish bai~t/ Expensive food item"
	/*  41 */ , NULL
	/*  42 */ , NULL
	/*  43 */ , NULL
	/*  44 */ , NULL
	/*  45 */ , NULL
	/*  46 */ , NULL
	/*  47 */ , NULL
	/*  48 */ , NULL
	/*  49 */ , NULL

	/*           123456789-123456789-123456789-123456 */
	/*  50 */ , "A small clump of iron"
	/*  51 */ , NULL
	/*  52 */ , NULL
	/*  53 */ , NULL
	/*  54 */ , NULL
	/*  55 */ , NULL
	/*  56 */ , NULL
	/*  57 */ , NULL
	/*  58 */ , NULL
	/*  59 */ , "A strong and dense metal"
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
	/*  75 */ , NULL
	/*  76 */ , "Quality tree fossil"
	/*  77 */ , NULL
	/*  78 */ , NULL
	/*  79 */ , NULL
	/*  80 */ , NULL
	/*  81 */ , NULL
	/*  82 */ , NULL
	/*  83 */ , NULL
	/*  84 */ , NULL
	/*  85 */ , NULL
	/*  86 */ , NULL
	/*  87 */ , NULL
	/*  88 */ , NULL
	/*  89 */ , NULL
	/*  90 */ , NULL
	/*  91 */ , NULL
	/*  92 */ , NULL
	/*  93 */ , NULL
	/*  94 */ , NULL
	/*  95 */ , NULL
	/*  96 */ , NULL
	/*  97 */ , NULL
	/*  98 */ , NULL
	/*  99 */ , NULL

	/*           123456789-123456789-123456789-123456 */
	/* 100 */ , "A box that discharges electricity"
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
	/* 115 */ , NULL
	/* 116 */ , NULL
	/* 117 */ , NULL
	/* 118 */ , NULL
	/* 119 */ , NULL
	/* 120 */ , NULL
	/* 121 */ , NULL
	/* 122 */ , NULL
	/* 123 */ , NULL
	/* 124 */ , NULL
	/* 125 */ , NULL
	/* 126 */ , NULL
	/* 127 */ , NULL
	/* 128 */ , "Distribution device"
	/* 129 */ , NULL
	/* 130 */ , NULL
	/* 131 */ , NULL
	/* 132 */ , NULL
	/* 133 */ , NULL
	/* 134 */ , NULL
	/* 135 */ , NULL
	/* 136 */ , NULL
	/* 137 */ , NULL
	/* 138 */ , NULL
	/* 139 */ , NULL
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

	/*           123456789-123456789-123456789-123456 */
	/* 150 */ , NULL
	/* 151 */ , NULL
	/* 152 */ , NULL
	/* 153 */ , NULL
	/* 154 */ , NULL
	/* 155 */ , NULL
	/* 156 */ , NULL
	/* 157 */ , NULL
	/* 158 */ , NULL
	/* 159 */ , NULL
	/* 160 */ , NULL
	/* 161 */ , NULL
	/* 162 */ , NULL
	/* 163 */ , NULL
	/* 164 */ , NULL
	/* 165 */ , NULL
	/* 166 */ , NULL
	/* 167 */ , NULL
	/* 168 */ , NULL
	/* 169 */ , NULL
	/* 170 */ , NULL
	/* 171 */ , NULL
	/* 172 */ , NULL
	/* 173 */ , NULL
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
	/* 185 */ , "Extends summon duration briefly"
	/* 186 */ , "Extends summon duration moderately"
	/* 187 */ , "Extends summon duration greatly"
	/* 188 */ , "Enhance the nimbleness of a friend"
	/* 189 */ , "Enhance the protection of a friend"
	/* 190 */ , "Enhance the power of a friend"
	/* 191 */ , NULL
	/* 192 */ , NULL
	/* 193 */ , "Provides resistance to paralysis"
	/* 194 */ , "Provides resistance to sleep"
	/* 195 */ , "Provides resistance to poison"
	/* 196 */ , "Provides resistance to rust"
	/* 197 */ , NULL /* unused? */
	/* 198 */ , NULL /* unused? */
	/* 199 */ , NULL

	/*           123456789-123456789-123456789-123456 */
	/* 200 */ , NULL
	/* 201 */ , "Expensive fishing rod"
	/* 202 */ , "Legendary fishing rod"
	/* 203 */ , NULL /* unused? */
	/* 204 */ , NULL /* unused? */
	/* 205 */ , NULL /* unused? */
	/* 206 */ , NULL
	/* 207 */ , NULL /* unused? */
	/* 208 */ , NULL /* unused? */
	/* 209 */ , NULL /* unused? */
	/* 210 */ , NULL /* unused? */
	/* 211 */ , NULL /* unused? */
	/* 212 */ , NULL /* unused? */
	/* 213 */ , NULL /* unused? */
	/* 214 */ , NULL /* unused? */
	/* 215 */ , NULL /* unused? */
	/* 216 */ , NULL /* unused? */
	/* 217 */ , NULL /* unused? */
	/* 218 */ , NULL /* unused? */
	/* 219 */ , NULL /* unused? */
	/* 220 */ , NULL /* unused? */
	/* 221 */ , NULL /* unused? */
	/* 222 */ , NULL /* unused? */
	/* 223 */ , NULL /* unused? */
	/* 224 */ , NULL
	/* 225 */ , NULL
	/* 226 */ , NULL
	/* 227 */ , NULL
	/* 228 */ , NULL
	/* 229 */ , NULL /* unused? */
	/* 230 */ , NULL
	/* 231 */ , NULL /* unused? */
	/* 232 */ , NULL
};
