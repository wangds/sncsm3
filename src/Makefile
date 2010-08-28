CC := gcc
CFLAGS := -I.
CFLAGS += -W -Wall -Wmissing-prototypes -Wstrict-prototypes

OBJS := main.o	\
	dialogue.o	\
	rom.o		\
	script/minigame.o	\
	script/teleporter.o	\
	table/beast.o	\
	table/font.o	\
	table/item.o	\
	table/effect.o	\
	table/kanji.o	\
	table/magic.o	\
	table/special.o	\
	table/weapon.o

all: sncsm3trans

sncsm3trans: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

.PHONY: clean
clean:
	$(RM) sncsm3trans
	$(RM) $(OBJS)
