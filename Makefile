BISON = bison
BISONFLAGS = --defines --report=all

FLEX = flex
FLEXFLAGS =

CC = clang++
CFLAGS = -Wall -Wextra -Isrc -std=c++11

OBJ =   src/utils/esl_ast.o src/utils/esl_bytecode.o src/utils/utils.o\
	src/parser/parser.o src/parser/lexer.o src/parser/eslxx_driver.o \
	src/compile/esl_compiler.o \
	src/execute/esl_vm.o src/execute/esl_context.o \
	src/execute/esl_variable.o src/execute/esl_value.o \
	src/execute/esl_stack_obj.o \
	src/main.o

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
	src/parser/stack.hh src/parser/parser.hpp src/parser/parser.cpp \
	src/parser/lexer.cpp tree.dot tree.png esl *.eslc *core*

## ------------ ##
## Test suite.  ##
## ------------ ##

ast: check
	dot tree.dot -Tpng -otree.png
	sxiv tree.png

check: all
	./esl check/test.esl

byte: check
	cat byte.eslc
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
