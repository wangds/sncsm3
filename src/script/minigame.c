/* minigame.c
 *
 * 0x0172234c: Fishing mini-game.
 */

#include <assert.h>
#include "dialogue.h"
#include "rom.h"
#include "script/minigame.h"

/*--------------------------------------------------------------*/

static void
tr_fishing_minigame(void)
{
	dlg_t *c;

	/* No fishing rod. */
	c = dlg_find(0x017223ae);
	c = dlg_wr(c, "The basic rod!");

	c = dlg_skip(c, 4);
	c = dlg_wr(c, "Then talk about it");

	/* Fishing menu. */
	c = dlg_find(0x01722422);
	c = dlg_wr(c, "What should I do?");

	c = dlg_skip(c, 6);
	c = dlg_wr(c, "Fish");

	c = dlg_skip(c, 6);
	c = dlg_wr(c, "Prizes");

	c = dlg_skip(c, 6);
	c = dlg_wr(c, "Cancel");

	/* No-bait menu. */
	c = dlg_seek(0x0172245b, 2);
	c = dlg_wr(c, "What should I do?");

	c = dlg_skip(c, 6);
	c = dlg_wr(c, "Prizes");

	c = dlg_skip(c, 6);
	c = dlg_wr(c, "Cancel");
}

void
tr_minigame(void)
{
	patch_dlg(0x0172234c, 0x017224ac, tr_fishing_minigame);
}
