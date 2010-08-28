/* day0.c
 *
 * 0x017bcb2c: Kajishi!
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dialogue.h"
#include "rom.h"
#include "script/day0.h"

/*--------------------------------------------------------------*/

static void
tr_day0_start(void)
{
	dlg_t *c;

	/* Rif: That goes without saying! */
	c = dlg_find(0x017bce56);
	assert(c->type == CHAR_ADDRESS);
	c->d.addr = dlg_seek(0x017bce58,12);

	/* Kajishi! */
	c = dlg_find(0x017bcb5c);
	c = dlg_wr(c, " Kajishi!");

	/* __A title for one who has mastered__
	 * ______the art of weapon craft ______
	 * ______and the way of the blade______
	 */
	c = dlg_find(0x017bcb82);
	c = dlg_wr(c, "  A title for one who has mastered  ");

	c = dlg_skip(c, 4);
	c = dlg_wr(c, "      the art of weapon craft       ");

	c = c->prev; dlg_append(c, 40);
	c = c->next; c->d.raw = 0x00;
	c = c->next; c->d.raw = 0x00;
	c = c->next; c->d.raw = 0x08;
	c = c->next; c->d.raw = 0x03;
	c = c->next;
	c = dlg_wr_ex(c, 36, "      and the way of the blade      ");

	/* __ To one who continually hones ____
	 * his skills by forging and polishing
	 */
	c = dlg_seek(0x017bcbcc, 2);
	c = dlg_wr(c, "   To one who continually hones     ");

	c = dlg_skip(c, 4);
	c = dlg_wr(c, "his skills by forging and polishing ");

	c = dlg_delete(c, 40);

	/* V.E: Understood?
	 *      Ritchie...
	 */
	c = dlg_find(0x017bcc35);
	c = dlg_wr(c, "Understood? ");

	/* Ritchie: V.E, nee-chan ...
	 * Rif:     V.E, sis...
	 */
	c = dlg_seek(0x017bcca8, 2);
	c = dlg_wr(c, "V.E, nee-chan ..");

	c = dlg_skip(c, 14);
	c = dlg_wr(c, "V.E, sis..");

	/* V.E: You have done well enduring
	 *      the training to now.
	 *      You're really splendid
	 */
	c = dlg_seek(0x017bccee, 2);
	c = dlg_wr(c, "You have done well enduring ");

	c = dlg_skip(c, 4);
	c = dlg_wr(c, "the training until now");

	c = dlg_skip(c, 4);
	c = dlg_wr(c, "You're really splendid");

	/* Ritchie: Thank you! */
	c = dlg_seek(0x017bcd35, 2);
	c = dlg_wr(c, "Thank you!");

	/* V.E: Then,
	 *      let's start the final test
	 */
	c = dlg_seek(0x017bcd58, 2);
	c = dlg_wr(c, "Then, ");

	c = dlg_skip(c, 4);
	c = dlg_wr(c, "let's start the final test");

	/* Ritchie: ...Understood */
	c = dlg_find(0x017bcd7f);
	c = dlg_wr(c, "Understood");

	/* V.E: Ritchie
	 *      You have your hammer?
	 */
	c = dlg_seek(0x017bcd8c, 4);
	c = dlg_wr(c, "You have your hammer?");

	/* Ritchie: Of course! */
	c = dlg_seek(0x017bcd9f,14);
	c = dlg_wr(c, "Of course!");

	/* V.E: Fufu...
	 *      It is a great hammer.
	 *      It has your soul...
	 */
	c = dlg_seek(0x017bce22, 2);
	c = dlg_wr(c, "Fufu..");

	c = dlg_skip(c, 4);
	c = dlg_wr(c, "It is a great hammer.");

	c = dlg_skip(c, 4);
	c = dlg_wr(c, "It bears your soul..");

	/* Ritchie: That is without saying!
	 * Rif:     That is without saying!
	 */
	c = dlg_find(0x017bce5a);
	c = dlg_wr(c, "That is without saying!");

	c = dlg_skip(c, 6);
	c = dlg_delete(c, 22);
	c = dlg_delete(c, 1);   /* Delete address 0x1806. */

	/* Both: To the Kajishi, the hammer is... */
	c = dlg_find(0x017bce7b);
	c = dlg_wr(c, "To the Kajishi, the hammer is ");

	/* Both: Their friend!
	 *       Their power!
	 *       Their life!
	 */
	c = dlg_find(0x017bced0);
	c = dlg_wr(c, "Their friend!");

	c = dlg_seek(0x017bcedb, 14);
	c = dlg_wr(c, "Their strength!");

	c = dlg_seek(0x017bcee4, 14);
	c = dlg_wr(c, "Their life!");

	/* V.E: Then,
	 *      defeat me with your hammer!
	 */
	c = dlg_seek(0x017bcf40, 4);
	c = dlg_wr(c, "Then, ");

	c = dlg_skip(c, 4);
	c = dlg_wr(c, "defeat me with your hammer!");

	/* V.E: That will be your... */
	c = dlg_find(0x017bcf6f);
	c = dlg_wr(c, "That will be your ..");

	/* V.E: final test! */
	c = dlg_find(0x017bcf8e);
	c = dlg_wr(c, "final test!");
}

void
tr_day0(void)
{
	patch_dlg_old(0x017bcb2c, 0x017bd14c, tr_day0_start);
}
