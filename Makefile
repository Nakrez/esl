BISON = bison
BISONFLAGS = --defines --report=all

FLEX = flex
FLEXFLAGS =

CC = clang++
CFLAGS = -Wall -Wextra -g -Isrc

OBJ = src/parser.o src/lexer.o src/main.o src/eslxx_driver.o \
      src/utils/esl_ast.o

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
	rm -f $(OBJ) src/parser.output src/location.hh src/position.hh \
	src/stack.hh src/parser.hpp tree.dot tree.png esl src/parser.cpp


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
