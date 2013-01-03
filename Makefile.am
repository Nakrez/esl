export libdir

SUBDIRS = . modules
ACLOCAL_AMFLAGS = -I m4
# libesl
lib_LTLIBRARIES = libesl.la
libesl_la_SOURCES = lib/context.cc lib/context.hh \
		    lib/extension.cc lib/extension.hh \
		    lib/runtime.cc lib/runtime.hh \
		    lib/executable-context.cc lib/executable-context.hh \
		    lib/params.cc lib/params.hh \
		    lib/module.cc lib/module.hh \
		    lib/exception.cc lib/exception.hh \
		    lib/stack-delimiter.cc lib/stack-delimiter.hh \
		    lib/type/int.cc lib/type/int.hh \
		    lib/type/string.cc lib/type/string.hh \
		    lib/type/array.cc lib/type/array.hh \
		    lib/type/type.cc lib/type/type.hh \
		    lib/gc/memory-object.hh

libesl_la_LDFLAGS = -version-info 1:0:0
libesl_la_CXXFLAGS = -Wall -Wextra -std=c++0x -Wdelete-non-virtual-dtor

# esl
bin_PROGRAMS= esl

esl_SOURCES =   src/utils/ast.cc src/utils/ast.hh \
		src/utils/utils.cc src/utils/utils.hh \
		src/utils/bytecode.cc src/utils/bytecode.hh \
		src/utils/ro-data.cc src/utils/ro-data.hh \
		src/parser/parser.yy \
		src/parser/lexer.ll \
		src/parser/driver.cc src/parser/driver.hh \
		src/compile/compiler.cc src/compile/compiler.hh \
		src/execute/vm.cc src/execute/vm.hh src/execute/vm.hxx \
		src/execute/operation.cc src/execute/operation.hh \
		src/main.cc

esl_CXXFLAGS = -pedantic -Wall -Wextra -std=c++0x -Wdelete-non-virtual-dtor
esl_LDFLAGS = -lfl
esl_YFLAGS = -W -Wall --report=all
esl_LDADD = libesl.la

# Other rules
clear: distclean
	rm -f aclocal.m4
	rm -rf autom4te.cache
	rm -rf build
	rm -rf config.h.in
	rm -rf config.h.in~
	rm -rf configure
	rm -rf m4
	rm -f Makefile.in
	rm -f src/parser/esl-*
	rm -f position.hh
	rm -f stack.hh
	rm -f location.hh
	rm -f *.dot
	rm -rf src/.libs
	rm -f src/parser/lexer.cc
	rm -f *.eslc
	rm -f *.png
	rm -f tags
	rm -f src/tags

esl-check: all
	./check/check.sh

count:
	cat lib/*.{hh,cc} lib/type/*.{cc,hh} lib/gc/*.{hh,hxx} src/main.cc \
	    src/**/*.{cc,hh} src/execute/vm.hxx | wc -l
