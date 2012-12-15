BISON = bison
BISONFLAGS = --defines --report=all

FLEX = flex
FLEXFLAGS =

CC = clang++
CFLAGS = -Wall -Wextra -g -Isrc -std=c++11

OBJ =   src/utils/ast.o src/utils/bytecode.o src/utils/utils.o \
	src/parser/parser.o src/parser/lexer.o src/parser/driver.o \
	src/compile/compiler.o \
	src/execute/vm.o \
	src/main.o

all: esl

esl: libesl libstd $(OBJ)
	$(CC) ./libesl.so $(OBJ) -o $@

libesl:
	make -C lib

libstd:
	make -C std

%.o: %.cc
	$(CC) $(CFLAGS) -c $< -o $@


%.cc: %.y
	$(BISON) $(BISONFLAGS) -o $@ $<

%.cc: %.l
	$(FLEX) $(FLEXFLAGS) -o $@ $<

clean:
	rm -f $(OBJ) src/parser/parser.output src/parser/location.hh \
	src/parser/position.hh \
	src/parser/stack.hh src/parser/parser.hpp src/parser/parser.cpp \
	src/parser/lexer.cpp tree.dot tree.png esl *.eslc *core* tags \
	libesl.so src/tags *.eslm
	make -C doc/vm clean
	make -C lib clean
	make -C std clean

## -------------- ##
## Documentation. ##
## -------------- ##

doc: doc_bytecode

doc_bytecode:
	make -C doc/vm

## ------------ ##
## Test suite.  ##
## ------------ ##

ast: check
	dot tree.dot -Tpng -otree.png
	sxiv tree.png

check: all
	./check/check.sh

byte: check
	cat byte.eslc

exec: all
	valgrind -v --leak-check=full ./esl check/test.esl
	./esl check/test.esl

## -------------- ##
## Distribution.  ##
## -------------- ##

PACKAGE = calc
VERSION = 2013
distdir = $(PACKAGE)-$(VERSION)
DISTFILES = scancalc.l parsecalc.y Makefile

distdir:
	rm -rf $(distdir)
	mkdir $(distdir)
	cp $(DISTFILES) $(distdir)

dist: distdir
	tar zcf $(distdir).tar.gz $(distdir)
	rm -rf $(distdir)

distcheck: dist
	rm -rf $(distdir)
	tar xf $(distdir).tar.gz
	make -C $(distdir)
	make -C $(distdir) check
	rm -rf $(distdir)
	@echo "!!!!!!!!!!!"
