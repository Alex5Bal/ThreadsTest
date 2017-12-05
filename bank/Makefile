all: dep-wd-race dep-wd-ok transfer-bad transfer-good PCTestV1

.PHONY: clean all		#declare these targets as phony

clean:
	rm -f *.o *.exe *stackdump dep-wd-race dep-wd-ok transfer-bad transfer-good PCTestV1

CFLAGS=-g -O1 -fno-ipa-sra -L../lib -I../h

# include files (forces recompile if changed)

dep-wd-race: dep-wd-race.o ../lib/tthreads.a
dep-wd-ok:  dep-wd-ok.o ../lib/tthreads.a
transfer-bad:  transfer-bad.o ../lib/tthreads.a
transfer-good: transfer-good.o ../lib/tthreads.a
PCTestV1: PCTestV1.o ..lib/tthreads.a
