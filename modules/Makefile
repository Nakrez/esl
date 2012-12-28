all:
	make -C io

clean:
	make -C io clean
	rm -rf .deps

distclean: clean

install:
	if [ ! -d $(libdir)/esl ]; then mkdir $(libdir)/esl; fi
	cp ../io.eslm $(libdir)/esl

uninstall:
	rm -rf $(libdir)/esl
