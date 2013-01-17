all:
	make -C io
	make -C array
	make -C stack

clean:
	make -C io clean
	make -C array clean
	make -C stack clean
	rm -rf .deps

distclean: clean

install:
	if [ ! -d $(libdir)/esl ]; then mkdir $(libdir)/esl; fi
	cp ../io.eslm $(libdir)/esl
	cp ../array.eslm $(libdir)/esl
	cp ../stack.eslm $(libdir)/esl

uninstall:
	rm -rf $(libdir)/esl

check:
