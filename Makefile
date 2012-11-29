BISON = bison
BISONFLAGS = --defines --report=all

FLEX = flex
FLEXFLAGS =

CC = clang++
CFLAGS = -Wall -Wextra -g -Isrc

OBJ = src/parser/parser.o src/parser/lexer.o src/parser/eslxx_driver.o \
	src/utils/esl_ast.o src/utils/esl_bytecode.o src/utils/utils.o\
	src/compile/esl_compiler.o \
	src/main.o

.PRECIOUS: src/parser/lexer.cpp
all: esl

esl: $(OBJ)
	$(CC) $(OBJ) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

%.cpp: %.y
	$(BISON) $(BISONFLAGS) -o $@ $<

%.cpp: %.l
	$(FLEX) $(FLEXFLAGS) -o $@ $<

clean:
	rm -f $(OBJ) src/parser/parser.output src/parser/location.hh \
	src/parser/position.hh \
	src/parser/stack.hh src/parser/parser.hpp src/parser.cpp \
	tree.dot tree.png esl *.eslc *core*

## ------------ ##
## Test suite.  ##
## ------------ ##

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
