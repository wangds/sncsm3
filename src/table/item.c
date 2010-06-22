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
};
