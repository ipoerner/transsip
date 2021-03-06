#
# Makefile for transsip
# Author: Daniel Borkmann
#

include ../definitions.mk

INCLUDE     = -I.. -I.
LIBS        = -lspeexdsp -lasound -lcelt0 -lm

core-objs   = transsip.o
lib-objs    = xmalloc.o		\
	      dht.o		\
	      stun.o		\
	      alsa.o		\
	      strlcpy.o

target      = transsip

all: clean gen-version build doc
debug: all
develop: all

gen-version:
	@cd .. && cat ../VERSION | xargs ./gen_build_info.pl

build: $(lib-objs) $(core-objs)
	@$(LD) $(target) $(core-objs) $(all-objs) $(LIBS)
	@strip $(target)

doc:
#	@cd ../../Documentation && make clean
#	@cd ../../Documentation && make transsip
#	@cp ../../Documentation/man/* .
#	@cp ../../Documentation/pdf/* .
#	@cp ../../Documentation/html/* .

%.o: ../%.c
	@$(CC) $(CFLAGS) $(INCLUDE) $<

clean:
	@rm *.o *~ $(target) ../version.h *.gz *.pdf *.html *.8 *.css  \
	../parser.tab.c ../parser.tab.h ../lex.yy.c *.rc               \
	$(DIR_SND)/*.o $(DIR_COD)/*.o $(DIR_CRY)/*.o > /dev/null 2>&1 || true

install:
	@install -D $(target) $(DESTDIR)/$(BINDIR)/$(target)
	@install -D $(target).8.gz $(DESTDIR)/usr/share/man/man8/$(target).8.gz

uninstall:
	@rm $(DESTDIR)/$(BINDIR)/$(target) || true
	@rm $(DESTDIR)/usr/share/man/man8/$(target).8.gz || true

help:
	@echo 'Cleaning targets:'
	@echo '  clean           - Remove generated files'
	@echo 'Building targets:'
	@echo '  all             - Build transsip (default)'
	@echo '  debug           - Build transsip for debugging _only_'
	@echo 'Setup targets:'
	@echo '  install         - Install transsip'
	@echo '  uninstall       - Uninstall transsip'
	@echo 'Other targets:'
	@echo '  help            - Print this help'

