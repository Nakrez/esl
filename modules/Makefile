all:
	make -C io
	make -C array

clean:
	make -C io clean
	make -C array clean
	rm -rf .deps

distclean: clean

install:
	if [ ! -d $(libdir)/esl ]; then mkdir $(libdir)/esl; fi
	cp ../io.eslm $(libdir)/esl
	cp ../array.eslm $(libdir)/esl

uninstall:
	rm -rf $(libdir)/esl
