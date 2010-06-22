/* font.c
 *
 * Font from Summon Night: Swordcraft Story 2.
 * Each letter is 6x12.
 */

#include "table/font.h"

const char k_font_space[12][6] = {
	"      ",
	"      ",
	"      ",
	"      ",
	"      ",
	"      ",
	"      ",
	"      ",
	"      ",
	"      ",
	"      ",
	"      "
};

const char k_font_comma[12][6] = {
	"      ",
	"      ",
	"      ",
	"      ",
	"      ",
	"      ",
	"      ",
	"      ",
	" xx   ",
	"  x   ",
	" x    ",
	"      "
};

const char k_font_period[12][6] = {
	"      ",
	"      ",
	"      ",
	"      ",
	"      ",
	"      ",
	"      ",
	"      ",
	"  x   ",
	"  x   ",
	"      ",
	"      "
};

const char k_font_semicolon[12][6] = {
	"      ",
	"      ",
	"      ",
	"  x   ",
	"  x   ",
	"      ",
	"      ",
	"  x   ",
	"  x   ",
	" x    ",
	"      ",
	"      "
};

const char k_font_question[12][6] = {
	"      ",
	" xxx  ",
	"x   x ",
	"x   x ",
	"   x  ",
	"  x   ",
	"  x   ",
	"      ",
	"  x   ",
	"  x   ",
	"      ",
	"      "
};

const char k_font_exclamation[12][6] = {
	"      ",
	"  x   ",
	"  x   ",
	"  x   ",
	"  x   ",
	"  x   ",
	"      ",
	"      ",
	"  x   ",
	"  x   ",
	"      ",
	"      "
};

const char k_font_apostrophe[12][6] = {
	" xx   ",
	"  x   ",
	" x    ",
	"      ",
	"      ",
	"      ",
	"      ",
	"      ",
	"      ",
	"      ",
	"      ",
	"      "
};

const char k_font_dash[12][6] = {
	"      ",
	"      ",
	"      ",
	"      ",
	"      ",
	"xxxxx ",
	"      ",
	"      ",
	"      ",
	"      ",
	"      ",
	"      "
};

const char k_font_upper_a[12][6] = {
	"      ",
	"  x   ",
	" x x  ",
	"x   x ",
	"x   x ",
	"x   x ",
	"xxxxx ",
	"x   x ",
	"x   x ",
	"x   x ",
	"      ",
	"      "
};

const char k_font_upper_b[12][6] = {
	"      ",
	"xxxx  ",
	"x   x ",
	"x   x ",
	"x   x ",
	"xxxx  ",
	"x   x ",
	"x   x ",
	"x   x ",
	"xxxx  ",
	"      ",
	"      "
};

const char k_font_upper_c[12][6] = {
	"      ",
	" xxx  ",
	"x   x ",
	"x   x ",
	"x     ",
	"x     ",
	"x     ",
	"x   x ",
	"x   x ",
	" xxx  ",
	"      ",
	"      "
};

const char k_font_upper_d[12][6] = {
	"      ",
	"xxx   ",
	"x  x  ",
	"x   x ",
	"x   x ",
	"x   x ",
	"x   x ",
	"x   x ",
	"x  x  ",
	"xxx   ",
	"      ",
	"      "
};

const char k_font_upper_e[12][6] = {
	"      ",
	"xxxxx ",
	"x     ",
	"x     ",
	"x     ",
	"xxxx  ",
	"x     ",
	"x     ",
	"x     ",
	"xxxxx ",
	"      ",
	"      "
};

const char k_font_upper_f[12][6] = {
	"      ",
	"xxxxx ",
	"x     ",
	"x     ",
	"x     ",
	"xxxx  ",
	"x     ",
	"x     ",
	"x     ",
	"x     ",
	"      ",
	"      "
};

const char k_font_upper_g[12][6] = {
	"      ",
	" xxx  ",
	"x   x ",
	"x   x ",
	"x     ",
	"x xxx ",
	"x   x ",
	"x   x ",
	"x   x ",
	" xxxx ",
	"      ",
	"      "
};

const char k_font_upper_h[12][6] = {
	"      ",
	"x   x ",
	"x   x ",
	"x   x ",
	"x   x ",
	"xxxxx ",
	"x   x ",
	"x   x ",
	"x   x ",
	"x   x ",
	"      ",
	"      "
};

const char k_font_upper_i[12][6] = {
	"      ",
	" xxx  ",
	"  x   ",
	"  x   ",
	"  x   ",
	"  x   ",
	"  x   ",
	"  x   ",
	"  x   ",
	" xxx  ",
	"      ",
	"      "
};

const char k_font_upper_j[12][6] = {
	"      ",
	"    x ",
	"    x ",
	"    x ",
	"    x ",
	"    x ",
	"x   x ",
	"x   x ",
	"x   x ",
	" xxx  ",
	"      ",
	"      "
};

const char k_font_upper_k[12][6] = {
	"      ",
	"x   x ",
	"x   x ",
	"x  x  ",
	"x x   ",
	"xx    ",
	"x x   ",
	"x  x  ",
	"x   x ",
	"x   x ",
	"      ",
	"      "
};

const char k_font_upper_l[12][6] = {
	"      ",
	"x     ",
	"x     ",
	"x     ",
	"x     ",
	"x     ",
	"x     ",
	"x     ",
	"x     ",
	"xxxxx ",
	"      ",
	"      "
};

const char k_font_upper_m[12][6] = {
	"      ",
	"xx xx ",
	"x x x ",
	"x x x ",
	"x x x ",
	"x x x ",
	"x x x ",
	"x x x ",
	"x x x ",
	"x x x ",
	"      ",
	"      "
};

const char k_font_upper_n[12][6] = {
	"      ",
	"x   x ",
	"xx  x ",
	"xx  x ",
	"x x x ",
	"x x x ",
	"x  xx ",
	"x  xx ",
	"x   x ",
	"x   x ",
	"      ",
	"      "
};

const char k_font_upper_o[12][6] = {
	"      ",
	" xxx  ",
	"x   x ",
	"x   x ",
	"x   x ",
	"x   x ",
	"x   x ",
	"x   x ",
	"x   x ",
	" xxx  ",
	"      ",
	"      "
};

const char k_font_upper_p[12][6] = {
	"      ",
	"xxxx  ",
	"x   x ",
	"x   x ",
	"x   x ",
	"xxxx  ",
	"x     ",
	"x     ",
	"x     ",
	"x     ",
	"      ",
	"      "
};

const char k_font_upper_q[12][6] = {
	"      ",
	" xxx  ",
	"x   x ",
	"x   x ",
	"x   x ",
	"x   x ",
	"x x x ",
	"x  xx ",
	"x   x ",
	" xxx x",
	"      ",
	"      "
};

const char k_font_upper_r[12][6] = {
	"      ",
	"xxxx  ",
	"x   x ",
	"x   x ",
	"x   x ",
	"xxxx  ",
	"x x   ",
	"x  x  ",
	"x  x  ",
	"x   x ",
	"      ",
	"      "
};

const char k_font_upper_s[12][6] = {
	"      ",
	" xxx  ",
	"x   x ",
	"x     ",
	"x     ",
	" xxx  ",
	"    x ",
	"    x ",
	"x   x ",
	" xxx  ",
	"      ",
	"      "
};

const char k_font_upper_t[12][6] = {
	"      ",
	"xxxxx ",
	"  x   ",
	"  x   ",
	"  x   ",
	"  x   ",
	"  x   ",
	"  x   ",
	"  x   ",
	"  x   ",
	"      ",
	"      "
};

const char k_font_upper_u[12][6] = {
	"      ",
	"x   x ",
	"x   x ",
	"x   x ",
	"x   x ",
	"x   x ",
	"x   x ",
	"x   x ",
	"x   x ",
	" xxx  ",
	"      ",
	"      "
};

const char k_font_upper_v[12][6] = {
	"      ",
	"x   x ",
	"x   x ",
	"x   x ",
	"x   x ",
	"x   x ",
	"x   x ",
	" x x  ",
	" x x  ",
	"  x   ",
	"      ",
	"      "
};

const char k_font_upper_w[12][6] = {
	"      ",
	"x   x ",
	"x x x ",
	"x x x ",
	"x x x ",
	"x x x ",
	"x x x ",
	"x x x ",
	"x x x ",
	" x x  ",
	"      ",
	"      "
};

const char k_font_upper_x[12][6] = {
	"      ",
	"x   x ",
	"x   x ",
	" x x  ",
	" x x  ",
	"  x   ",
	" x x  ",
	" x x  ",
	"x   x ",
	"x   x ",
	"      ",
	"      "
};

const char k_font_upper_y[12][6] = {
	"      ",
	"x   x ",
	"x   x ",
	" x x  ",
	" x x  ",
	"  x   ",
	"  x   ",
	"  x   ",
	"  x   ",
	"  x   ",
	"      ",
	"      "
};

const char k_font_upper_z[12][6] = {
	"      ",
	"xxxxx ",
	"    x ",
	"   x  ",
	"   x  ",
	"  x   ",
	" x    ",
	" x    ",
	"x     ",
	"xxxxx ",
	"      ",
	"      "
};

const char k_font_lower_a[12][6] = {
	"      ",
	"      ",
	"      ",
	"      ",
	"xxxx  ",
	"    x ",
	" xxxx ",
	"x   x ",
	"x   x ",
	" xxxx ",
	"      ",
	"      "
};

const char k_font_lower_b[12][6] = {
	"      ",
	"x     ",
	"x     ",
	"x     ",
	"xxxx  ",
	"x   x ",
	"x   x ",
	"x   x ",
	"x   x ",
	"xxxx  ",
	"      ",
	"      "
};

const char k_font_lower_c[12][6] = {
	"      ",
	"      ",
	"      ",
	"      ",
	" xxx  ",
	"x   x ",
	"x     ",
	"x     ",
	"x   x ",
	" xxx  ",
	"      ",
	"      "
};

const char k_font_lower_d[12][6] = {
	"      ",
	"    x ",
	"    x ",
	"    x ",
	" xxxx ",
	"x   x ",
	"x   x ",
	"x   x ",
	"x   x ",
	" xxxx ",
	"      ",
	"      "
};

const char k_font_lower_e[12][6] = {
	"      ",
	"      ",
	"      ",
	"      ",
	" xxx  ",
	"x   x ",
	"xxxxx ",
	"x     ",
	"x   x ",
	" xxx  ",
	"      ",
	"      "
};

const char k_font_lower_f[12][6] = {
	"      ",
	"   xx ",
	"  x   ",
	"  x   ",
	"xxxxx ",
	"  x   ",
	"  x   ",
	"  x   ",
	"  x   ",
	"  x   ",
	"      ",
	"      "
};

const char k_font_lower_g[12][6] = {
	"      ",
	"      ",
	"      ",
	"      ",
	" xxxx ",
	"x  x  ",
	"x  x  ",
	" xx   ",
	"x     ",
	"xxxx  ",
	"x   x ",
	" xxx  "
};

const char k_font_lower_h[12][6] = {
	"      ",
	"x     ",
	"x     ",
	"x     ",
	"xxxx  ",
	"x   x ",
	"x   x ",
	"x   x ",
	"x   x ",
	"x   x ",
	"      ",
	"      "
};

const char k_font_lower_i[12][6] = {
	"      ",
	"  x   ",
	"  x   ",
	"      ",
	"  x   ",
	"  x   ",
	"  x   ",
	"  x   ",
	"  x   ",
	"  x   ",
	"      ",
	"      "
};

const char k_font_lower_j[12][6] = {
	"      ",
	"  x   ",
	"  x   ",
	"      ",
	"  x   ",
	"  x   ",
	"  x   ",
	"  x   ",
	"  x   ",
	"  x   ",
	"  x   ",
	"xx    "
};

const char k_font_lower_k[12][6] = {
	"      ",
	"x     ",
	"x     ",
	"x     ",
	"x  x  ",
	"x x   ",
	"xx    ",
	"x x   ",
	"x  x  ",
	"x   x ",
	"      ",
	"      "
};

const char k_font_lower_l[12][6] = {
	"      ",
	"  x   ",
	"  x   ",
	"  x   ",
	"  x   ",
	"  x   ",
	"  x   ",
	"  x   ",
	"  x   ",
	"  x   ",
	"      ",
	"      "
};

const char k_font_lower_m[12][6] = {
	"      ",
	"      ",
	"      ",
	"      ",
	"xxxx  ",
	"x x x ",
	"x x x ",
	"x x x ",
	"x x x ",
	"x x x ",
	"      ",
	"      "
};

const char k_font_lower_n[12][6] = {
	"      ",
	"      ",
	"      ",
	"      ",
	"xxxx  ",
	"x   x ",
	"x   x ",
	"x   x ",
	"x   x ",
	"x   x ",
	"      ",
	"      "
};

const char k_font_lower_o[12][6] = {
	"      ",
	"      ",
	"      ",
	"      ",
	" xxx  ",
	"x   x ",
	"x   x ",
	"x   x ",
	"x   x ",
	" xxx  ",
	"      ",
	"      "
};

const char k_font_lower_p[12][6] = {
	"      ",
	"      ",
	"      ",
	"      ",
	"xxxx  ",
	"x   x ",
	"x   x ",
	"x   x ",
	"x   x ",
	"xxxx  ",
	"x     ",
	"x     "
};

const char k_font_lower_q[12][6] = {
	"      ",
	"      ",
	"      ",
	"      ",
	" xxxx ",
	"x   x ",
	"x   x ",
	"x   x ",
	"x   x ",
	" xxxx ",
	"    x ",
	"    x "
};

const char k_font_lower_r[12][6] = {
	"      ",
	"      ",
	"      ",
	"      ",
	"x xxx ",
	"xx    ",
	"x     ",
	"x     ",
	"x     ",
	"x     ",
	"      ",
	"      "
};

const char k_font_lower_s[12][6] = {
	"      ",
	"      ",
	"      ",
	"      ",
	" xxx  ",
	"x   x ",
	" xx   ",
	"   x  ",
	"x   x ",
	" xxx  ",
	"      ",
	"      "
};

const char k_font_lower_t[12][6] = {
	"      ",
	"      ",
	"  x   ",
	"  x   ",
	"xxxxx ",
	"  x   ",
	"  x   ",
	"  x   ",
	"  x   ",
	"   xx ",
	"      ",
	"      "
};

const char k_font_lower_u[12][6] = {
	"      ",
	"      ",
	"      ",
	"      ",
	"x   x ",
	"x   x ",
	"x   x ",
	"x   x ",
	"x  xx ",
	" xx x ",
	"      ",
	"      "
};

const char k_font_lower_v[12][6] = {
	"      ",
	"      ",
	"      ",
	"      ",
	"x   x ",
	"x   x ",
	"x   x ",
	" x x  ",
	" x x  ",
	"  x   ",
	"      ",
	"      "
};

const char k_font_lower_w[12][6] = {
	"      ",
	"      ",
	"      ",
	"      ",
	"x   x ",
	"x x x ",
	"x x x ",
	"x x x ",
	"x x x ",
	" x x  ",
	"      ",
	"      "
};

const char k_font_lower_x[12][6] = {
	"      ",
	"      ",
	"      ",
	"      ",
	"x   x ",
	" x x  ",
	"  x   ",
	"  x   ",
	" x x  ",
	"x   x ",
	"      ",
	"      "
};

const char k_font_lower_y[12][6] = {
	"      ",
	"      ",
	"      ",
	"      ",
	"x   x ",
	"x   x ",
	"x   x ",
	" x x  ",
	" x x  ",
	"  x   ",
	"  x   ",
	"xx    "
};

const char k_font_lower_z[12][6] = {
	"      ",
	"      ",
	"      ",
	"      ",
	"xxxxx ",
	"    x ",
	"   x  ",
	"  x   ",
	" x    ",
	"xxxxx ",
	"      ",
	"      "
};
