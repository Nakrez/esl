all:
	make -C io
	make -C array
	make -C stack
	make -C sys
	make -C esl

clean:
	make -C io clean
	make -C array clean
	make -C stack clean
	make -C sys clean
	make -C esl clean
	rm -rf .deps

distclean: clean

install:
	if [ ! -d $(libdir)/esl ]; then mkdir $(libdir)/esl; fi
	cp ../io.eslm $(libdir)/esl
	cp ../array.eslm $(libdir)/esl
	cp ../stack.eslm $(libdir)/esl
	cp ../sys.eslm $(libdir)/esl
	cp ../esl.eslm $(libdir)/esl

uninstall:
	rm -rf $(libdir)/esl

check:
