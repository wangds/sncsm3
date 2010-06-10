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

static const char k_font_upper_a[12][6] = {
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

static const char k_font_upper_b[12][6] = {
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

static const char k_font_upper_c[12][6] = {
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

static const char k_font_upper_d[12][6] = {
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

static const char k_font_upper_e[12][6] = {
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

static const char k_font_upper_f[12][6] = {
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

static const char k_font_upper_g[12][6] = {
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

static const char k_font_upper_h[12][6] = {
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

static const char k_font_upper_i[12][6] = {
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

static const char k_font_upper_j[12][6] = {
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

static const char k_font_upper_k[12][6] = {
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

static const char k_font_upper_l[12][6] = {
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

static const char k_font_upper_m[12][6] = {
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

static const char k_font_upper_n[12][6] = {
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

static const char k_font_upper_o[12][6] = {
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

static const char k_font_upper_p[12][6] = {
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

static const char k_font_upper_q[12][6] = {
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

static const char k_font_upper_r[12][6] = {
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

static const char k_font_upper_s[12][6] = {
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

static const char k_font_upper_t[12][6] = {
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

static const char k_font_upper_u[12][6] = {
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

static const char k_font_upper_v[12][6] = {
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

static const char k_font_upper_w[12][6] = {
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

static const char k_font_upper_x[12][6] = {
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

static const char k_font_upper_y[12][6] = {
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

static const char k_font_upper_z[12][6] = {
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

static const char k_font_lower_a[12][6] = {
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

static const char k_font_lower_b[12][6] = {
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

static const char k_font_lower_c[12][6] = {
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

static const char k_font_lower_d[12][6] = {
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

static const char k_font_lower_e[12][6] = {
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

static const char k_font_lower_f[12][6] = {
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

static const char k_font_lower_g[12][6] = {
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

static const char k_font_lower_h[12][6] = {
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

static const char k_font_lower_i[12][6] = {
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

static const char k_font_lower_j[12][6] = {
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

static const char k_font_lower_k[12][6] = {
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

static const char k_font_lower_l[12][6] = {
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

static const char k_font_lower_m[12][6] = {
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

static const char k_font_lower_n[12][6] = {
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

static const char k_font_lower_o[12][6] = {
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

static const char k_font_lower_p[12][6] = {
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

static const char k_font_lower_q[12][6] = {
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

static const char k_font_lower_r[12][6] = {
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

static const char k_font_lower_s[12][6] = {
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

static const char k_font_lower_t[12][6] = {
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

static const char k_font_lower_u[12][6] = {
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

static const char k_font_lower_v[12][6] = {
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

static const char k_font_lower_w[12][6] = {
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

static const char k_font_lower_x[12][6] = {
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

static const char k_font_lower_y[12][6] = {
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

static const char k_font_lower_z[12][6] = {
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

const letter_t * const k_font_uppercase[26] = {
	&k_font_upper_a, &k_font_upper_b, &k_font_upper_c, &k_font_upper_d,
	&k_font_upper_e, &k_font_upper_f, &k_font_upper_g, &k_font_upper_h,
	&k_font_upper_i, &k_font_upper_j, &k_font_upper_k, &k_font_upper_l,
	&k_font_upper_m, &k_font_upper_n, &k_font_upper_o, &k_font_upper_p,
	&k_font_upper_q, &k_font_upper_r, &k_font_upper_s, &k_font_upper_t,
	&k_font_upper_u, &k_font_upper_v, &k_font_upper_w, &k_font_upper_x,
	&k_font_upper_y, &k_font_upper_z
};

const letter_t * const k_font_lowercase[26] = {
	&k_font_lower_a, &k_font_lower_b, &k_font_lower_c, &k_font_lower_d,
	&k_font_lower_e, &k_font_lower_f, &k_font_lower_g, &k_font_lower_h,
	&k_font_lower_i, &k_font_lower_j, &k_font_lower_k, &k_font_lower_l,
	&k_font_lower_m, &k_font_lower_n, &k_font_lower_o, &k_font_lower_p,
	&k_font_lower_q, &k_font_lower_r, &k_font_lower_s, &k_font_lower_t,
	&k_font_lower_u, &k_font_lower_v, &k_font_lower_w, &k_font_lower_x,
	&k_font_lower_y, &k_font_lower_z
};
