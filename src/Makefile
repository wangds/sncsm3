CC := gcc
CFLAGS := -I.
CFLAGS += -W -Wall -Wmissing-prototypes -Wstrict-prototypes

OBJS := main.o	\
	rom.o	\
	table/font.o	\
	table/item.o	\
	table/kanji.o

all: sncsm3trans

sncsm3trans: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

.PHONY: clean
clean:
	$(RM) sncsm3trans
	$(RM) $(OBJS)
