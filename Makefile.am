export libdir

SUBDIRS = . modules
ACLOCAL_AMFLAGS = -I m4

# libesl
lib_LTLIBRARIES = libesl.la
libesl_la_SOURCES = lib/misc/symbol.cc \
		    lib/context.cc lib/context.hh \
		    lib/extension.cc lib/extension.hh \
		    lib/params.cc lib/params.hh \
		    lib/module.cc lib/module.hh \
		    lib/function.cc lib/function.hh \
		    lib/exception.cc lib/exception.hh \
		    lib/stack-delimiter.cc lib/stack-delimiter.hh \
		    lib/type/int.cc lib/type/int.hh \
		    lib/type/string.cc lib/type/string.hh \
		    lib/type/array.cc lib/type/array.hh \
		    lib/type/type.cc lib/type/type.hh \
		    lib/type/squeleton.cc lib/type/squeleton.hh \
		    lib/type/object.cc lib/type/object.hh \
		    lib/type/int-object.cc lib/type/int-object.hh \
		    lib/type/array-object.cc lib/type/array-object.hh \
		    lib/type/string-object.cc lib/type/string-object.hh \
		    src/execute/vm.cc src/execute/vm.hh src/execute/vm.hxx \
		    lib/gc/memory-object.hh

libesl_la_LDFLAGS = -version-info 1:0:0
libesl_la_CXXFLAGS = -Ilib -Wall -Wextra -std=c++0x -Wno-delete-non-virtual-dtor

# esl
bin_PROGRAMS= esl

esl_SOURCES =  src/parser/parser.yy \
		src/parser/lexer.ll \
		src/ast/ast.cc src/ast/ast.hh \
		src/ast/dec.cc \
		src/ast/var-dec.cc \
		src/ast/var-dec-list.cc \
		src/ast/attribut-dec.cc \
		src/ast/function-dec.cc \
		src/ast/method-dec.cc \
		src/ast/import-dec.cc \
		src/ast/exp.cc \
		src/ast/exp-list.cc \
		src/ast/op-exp.cc \
		src/ast/if-exp.cc \
		src/ast/visitor.cc \
		src/ast/pretty-printer.cc \
		src/utils/utils.cc src/utils/utils.hh \
		src/utils/bytecode.cc src/utils/bytecode.hh \
		src/utils/ro-data.cc src/utils/ro-data.hh \
		src/parser/driver.cc src/parser/driver.hh \
		src/main.cc
#src/compile/compiler.cc src/compile/compiler.hh \
#EXTRA_esl_YACCdir = src/parser

esl_CXXFLAGS = -Isrc -Ilib -Wall -Wextra -std=c++0x -Wno-delete-non-virtual-dtor
esl_LDFLAGS = -lfl
esl_YFLAGS = -d -W -Wall --report=all
esl_LDADD = libesl.la

#esl_YACC_HEADERS = stack.hh location.hh position.hh

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
	rm -rf doc/doc/

count:
	cat lib/*.{hh,cc} lib/type/*.{cc,hh} lib/gc/*.{hh,hxx} src/main.cc \
	    src/**/*.{cc,hh,hxx} modules/**/*.{cc,hh} | wc -l

esl-doc:
	make -C doc

TESTS=	./check/io/io_check.sh \
	./check/int/int_check.sh \
	./check/strings/strings_check.sh \
	./check/datastruct/datastruct_check.sh \
	./check/control/control_check.sh \
	./check/loops/loops_check.sh \
	./check/functions/functions_check.sh \
	./check/array/array_check.sh \
	./check/comment/comment_check.sh \
	./check/oo/oo_check.sh \
	./check/mix/mix_check.sh \
	./check/sys/sys_check.sh \
	./check/esl/esl_check.sh
