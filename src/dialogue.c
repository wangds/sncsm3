/* dialogue.c
 *
 * Manipulate compressed dialogue strings.
 */

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dialogue.h"
#include "rom.h"

static dlg_t *s_dialogue_str;
static dlg_t *s_dialogue_tail;

/*--------------------------------------------------------------*/

static int
dialogue_char_length(enum DIALOGUE_TYPE type)
{
	switch (type) {
		case CHAR_RAW:
			return 1;

		case CHAR_ADDRESS:
			return 2;

		default:
			assert(false);
			return 0;
	}
}

dlg_t *
dlg_find(int offset)
{
	dlg_t *c;

	for (c = s_dialogue_str; c != NULL; c = c->next) {
		if (c->offset == offset)
			return c;
	}

	assert(false);
	return NULL;
}

dlg_t *
dlg_skip(dlg_t *c, int sz)
{
	while (sz > 0) {
		sz -= dialogue_char_length(c->type);
		c = c->next;
	}

	return c;
}

dlg_t *
dlg_seek(int offset, int skip)
{
	return dlg_skip(dlg_find(offset), skip);
}

/*--------------------------------------------------------------*/

static dlg_t *
dialogue_append_raw(dlg_t *ref, int raw)
{
	dlg_t *c = malloc(sizeof(*c));
	assert(c != NULL);

	c->index = -1;
	c->offset = 0x7fffffff;
	c->type = CHAR_RAW;
	c->d.raw = raw;

	if (ref != NULL) {
		if (ref->next != NULL)
			ref->next->prev = c;

		c->next = ref->next;
		c->prev = ref;
		ref->next = c;
	}
	else {
		c->next = NULL;
		c->prev = NULL;
	}

	if (s_dialogue_str == NULL)
		s_dialogue_str = c;

	if (s_dialogue_tail == ref)
		s_dialogue_tail = c;

	return c;
}

static dlg_t *
dialogue_append_str(dlg_t *ref, const dlg_t *src, int len)
{
	dlg_t *c = ref;

	while (len > 0) {
		assert(src->type == CHAR_RAW);
		c = dialogue_append_raw(c, src->d.raw);

		src = src->next;
		len--;
	}

	return ref->next;
}

void
dlg_append(dlg_t *ref, int sz)
{
	while (sz > 0) {
		dialogue_append_raw(ref, 0xFF);
		sz--;
	}
}

static dlg_t *
dialogue_delete_1(dlg_t *c)
{
	dlg_t *nx = c->next;
	dlg_t *pv = c->prev;

	if (nx != NULL) nx->prev = pv;
	if (pv != NULL) pv->next = nx;

	free(c);
	return nx;
}

dlg_t *
dlg_delete(dlg_t *c, int sz)
{
	while (sz > 0) {
		c = dialogue_delete_1(c);
		sz--;
	}

	return c;
}

static void
free_dialogue(void)
{
	dlg_t *c;
	dlg_t *nx;

	for (c = s_dialogue_str; c != NULL; c = nx) {
		nx = c->next;
		free(c);
	}

	s_dialogue_str = NULL;
	s_dialogue_tail = NULL;
}

/*--------------------------------------------------------------*/

static void
dialogue_mark_address(dlg_t *c)
{
	dlg_t *nx = c->next;
	int addr;
	assert((nx != NULL) && (c->type == CHAR_RAW) && (nx->type == CHAR_RAW));

	addr = (nx->d.raw << 8) | c->d.raw;
	dialogue_delete_1(nx);

	c->type = CHAR_ADDRESS;
	c->d.addr = NULL;

	for (nx = c->next; nx != NULL; nx = nx->next) {
		if (nx->index == addr) {
			c->d.addr = nx;
			break;
		}
	}

	assert(c->d.addr != NULL);
}

dlg_t *
dlg_addr(int offset, int skip, int fst, int snd)
{
	dlg_t *c = dlg_seek(offset, skip);
	dlg_t *nx = c->next;
	assert(nx != NULL);
	assert((c->type == CHAR_RAW) && (nx->type == CHAR_RAW));
	assert((c->d.raw == fst) && (nx->d.raw == snd));

	dialogue_mark_address(c);
	return c;
}

/*--------------------------------------------------------------*/

static dlg_t *
copy_dialogue(dlg_t *c, int sz, const unsigned char *buf)
{
	int i;

	for (i = 0; i < sz; i++) {
		assert(c->type == CHAR_RAW);

		c->d.raw = buf[i];
		c = c->next;
	}

	return c;
}

dlg_t *
dlg_wr_ex(dlg_t *c, int orig_len, const char *str)
{
	unsigned char buf[128];
	int sz;

	patch_str_ex(buf, 0, sizeof(buf), str);
	for (sz = 0; buf[sz] != '\0'; sz++);

	if (orig_len < sz)
		dlg_append(c, sz-orig_len);

	c = copy_dialogue(c, sz, buf);

	if (sz < orig_len)
		c = dlg_delete(c, orig_len-sz);

	return c;
}

dlg_t *
dlg_wr(dlg_t *c, const char *str)
{
	const dlg_t *cc;
	int orig_len = 0;

	for (cc = c; cc != NULL; cc = cc->next) {
		if (cc->d.raw == 0x00)
			break;

		orig_len++;
	}

	assert((cc->next != NULL) && (cc->next->d.raw == 0x00));
	assert((orig_len & 0x01) == 0);

	return dlg_wr_ex(c, orig_len, str);
}

/*--------------------------------------------------------------*/

/* regenerate_dialogue:
 *
 * Reassigns the indices in the dialogue, which is used by 'goto'
 * functions.
 */
static void
regenerate_dialogue(void)
{
	dlg_t *c;
	int index;

	index = -16;
	for (c = s_dialogue_str; c != NULL; c = c->next) {
		c->index = index;
		index += dialogue_char_length(c->type);
	}
}

void
read_dialogue(const unsigned char *rom, int offset)
{
	dlg_t *c;
	int decoded_len;
	int count;
	assert((s_dialogue_str == NULL) && (s_dialogue_tail == NULL));

	{
		assert(rom[offset+0] == 0x10);
		assert(rom[offset+3] == 0x00);
		assert(rom[offset+5] == 'P');
		assert(rom[offset+6] == 'S');
		assert(rom[offset+7] == 'I');

		decoded_len = (rom[offset+2] << 8) + (rom[offset+1]);

		offset += 4;
	}

	count = -16;
	while ((offset > 0) && (16+count < decoded_len)) {
		int ss, i;

		ss = rom[offset];
		offset++;

		for (i = 0; (i < 8) && (16+count < decoded_len); i++) {
			if (ss & 0x80) {
				const dlg_t *src;
				int sz = 3 + (rom[offset] >> 4);
				int bt = ((rom[offset] & 0x0f) << 8) | rom[offset+1];

				src = s_dialogue_tail;
				while (bt > 0) {
					src = src->prev;
					bt--;
				}

				c = dialogue_append_str(s_dialogue_tail, src, sz);
				c->index = count;
				c->offset = offset;

				count += sz;
				offset += 2;
			}
			else {
				c = dialogue_append_raw(s_dialogue_tail, rom[offset]);
				c->index = count;
				c->offset = offset;

				count++;
				offset++;
			}

			ss <<= 1;
		}
	}

	regenerate_dialogue();
	fprintf(stdout, "Read ended at offset 0x%08x\n", offset);
}

/*--------------------------------------------------------------*/

/* flatten_dialogue:
 *
 * Converts all dialogue elements back to raw characters for writing.
 */
static void
flatten_dialogue(void)
{
	dlg_t *c;

	for (c = s_dialogue_str; c != NULL; c = c->next) {
		if (c->type == CHAR_RAW)
			continue;

		if (c->type == CHAR_ADDRESS) {
			int addr = c->d.addr->index;

			c->type = CHAR_RAW;
			c->d.raw = (addr & 0xff);
			c = dialogue_append_raw(c, (addr >> 8));
		}
	}
}

static int
score_compress(const dlg_t *c, const dlg_t *src)
{
	int count = 0;

	while ((count < 3+0xf) && (c != NULL) && (c->d.raw == src->d.raw)) {
		count++;
		c = c->next;
		src = src->next;
	}

	return (count < 3) ? 0 : count;
}

int
write_dialogue(unsigned char *rom, int offset)
{
	dlg_t *c;
	int decoded_len;
	int i;

	regenerate_dialogue();
	flatten_dialogue();

	{
		decoded_len = 16+s_dialogue_tail->index+1;

		rom[offset+ 1] = (decoded_len & 0xff);
		rom[offset+ 2] = (decoded_len >> 8);
		rom[offset+ 9] = (decoded_len & 0xff);
		rom[offset+10] = (decoded_len >> 8);

		offset += 4;
	}

	c = s_dialogue_str;
	while (c != NULL) {
		int ss_offset = offset;
		int ss = 0;

		offset++;

		for (i = 0; (i < 8) && (c != NULL); i++) {
			dlg_t *best_src = NULL;
			dlg_t *comp_src;
			int best_score = 0;
			int best_bt = 0;
			int comp_bt;

			/* Attempt greedy compression. */
			if (c->prev != NULL) {
				comp_src = c->prev->prev;
				comp_bt = 1;
			}
			else {
				comp_src = NULL;
			}

			while (comp_src != NULL) {
				int comp_score = score_compress(c, comp_src);

				if (best_score < comp_score) {
					best_score = comp_score;
					best_src = comp_src;
					best_bt = comp_bt;

					if (best_score >= 3+0xf)
						break;
				}

				comp_src = comp_src->prev;
				comp_bt++;
				if (comp_bt > 0xfff)
					break;
			}

			if (best_src != NULL) {
				rom[offset+0] = ((best_score-3) << 4) | (best_bt >> 8);
				rom[offset+1] = (best_bt & 0xff);

				while (best_score > 0) {
					c = c->next;
					best_score--;
				}

				ss = (ss << 1) | 1;
				offset += 2;
			}
			else {
				rom[offset] = c->d.raw;
				c = c->next;
				ss <<= 1;
				offset++;
			}
		}

		for (; i < 8; i++)
			ss <<= 1;

		rom[ss_offset] = ss;
	}

	free_dialogue();

	return offset;
}
