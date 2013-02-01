CC = pandoc
SRC = doc/intro.html doc/ctrl_flow.html doc/types.html doc/modules.html \
      doc/std_module_io.html doc/std_module_esl.html doc/std_module_sys.html

all: doc $(SRC)

doc:
	cp -r base doc

doc/%.html: src/%.md
	pandoc -s -S --toc -c doc.css $< -o $@

clean:
	rm -rf doc
