CC = pandoc
SRC = doc/std_module_esl.html doc/std_module_sys.html

all: doc $(SRC)

doc:
	mkdir doc

doc/%.html: src/%.md
	pandoc -s -S --toc -c doc.css $< -o $@

clean:
	rm -rf doc/*.html
