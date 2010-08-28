/* teleporter.c
 *
 * 0x01721b4c: Portal.
 */

#include <assert.h>
#include "dialogue.h"
#include "rom.h"
#include "script/teleporter.h"

/*--------------------------------------------------------------*/

static void
tr_portal(void)
{
	dlg_t *c;

	/* No destination. */
	c = dlg_find(0x01721b97);
	c = dlg_wr(c, "It cannot be used because ");

	c = dlg_skip(c, 4);
	c = dlg_wr(c, "there are currently no connections");

	/* Portal menu. */
	c = dlg_find(0x01721be4);
	c = dlg_wr(c, "Where do you want to go?");

	c = dlg_find(0x01721c17);
	c = dlg_wr(c, "Dikkuru ");

	c = dlg_find(0x01721c35);
	c = dlg_wr(c, "Maneiru ");

	c = dlg_find(0x01721c55);
	c = dlg_wr(c, "Purosuban ");

	c = dlg_find(0x01721c75);
	c = dlg_wr(c, "Louise");

	c = dlg_find(0x01721c8d);
	c = dlg_wr(c, "Mishusu ");

	c = dlg_find(0x01721caf);
	c = dlg_wr(c, "Dungeon ");

	c = dlg_find(0x01721cbf);
	c = dlg_wr(c, "Cancel");
}

/*--------------------------------------------------------------*/

void
tr_teleporter(void)
{
	patch_dlg_old(0x01721b4c, 0x01721dfc, tr_portal);
}
