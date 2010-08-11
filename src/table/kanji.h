#ifndef TABLE_KANJI_H
#define TABLE_KANJI_H

enum {
	FIRST_CHAR_CODE = 0x889f,
	LAST_CHAR_CODE = 0x9872,
	NUM_CHAR_CODES = LAST_CHAR_CODE - FIRST_CHAR_CODE + 1
};

extern const int k_contiguous_kanji[];

#endif
