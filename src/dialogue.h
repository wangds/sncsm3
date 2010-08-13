#ifndef DIALOGUE_H
#define DIALOGUE_H

enum DIALOGUE_TYPE {
	/* Encoded character is read as a raw character. */
	CHAR_RAW,

	/* Encoded character stores an address for goto's. */
	CHAR_ADDRESS
};

typedef struct DIALOGUE_CHAR {
	struct DIALOGUE_CHAR *next;
	struct DIALOGUE_CHAR *prev;

	/* Index in the buffer as used by goto commands. */
	int index;

	/* Offset in rom.  Only really used for searching. */
	int offset;

	enum DIALOGUE_TYPE type;
	union {
		int raw;
		struct DIALOGUE_CHAR *addr;
	} d;
} dlg_t;

extern dlg_t *dlg_find(int offset);
extern dlg_t *dlg_skip(dlg_t *c, int sz);
extern dlg_t *dlg_seek(int offset, int skip);

extern void dlg_append(dlg_t *ref, int sz);
extern dlg_t *dlg_delete(dlg_t *c, int sz);
extern dlg_t *dlg_addr(int addr, int offset, int fst, int snd);
extern dlg_t *dlg_wr_ex(dlg_t *c, int orig_len, const char *str);
extern dlg_t *dlg_wr(dlg_t *c, const char *str);

extern void read_dialogue(const unsigned char *rom, int offset);
extern int write_dialogue(unsigned char *rom, int offset);

#endif
