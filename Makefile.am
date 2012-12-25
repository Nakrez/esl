AM_CFLAGS = 
SUBDIRS = . modules
ACLOCAL_AMFLAGS = -I m4

# libesl
lib_LTLIBRARIES = libesl.la
libesl_la_SOURCES = lib/class-def.cc lib/class-def.hh \
		    lib/content-object.cc lib/content-object.hh \
		    lib/context.cc lib/context.hh \
		    lib/extension.cc lib/extension.hh \
		    lib/object-instance.hh lib/object-instance.cc \
		    lib/runtime.cc lib/runtime.hh \
		    lib/value.cc lib/value.hh \
		    lib/executable-context.cc lib/executable-context.hh \
		    lib/params.cc lib/params.hh \
		    lib/object.cc lib/object.hh \
		    lib/module.cc lib/module.hh

libesl_la_LDFLAGS = -version-info 1:0:0
libesl_la_CXXFLAGS = -Wall -Wextra -std=c++0x

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
		src/main.cc

esl_CXXFLAGS = -pedantic -Wall -Wextra -std=c++0x
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

esl-check:
	./check/check.sh
