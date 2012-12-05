all: bytecode bytecode.css
	dot build.dot -Tpng -obuild.png
	pandoc -s -S --toc bytecode -c bytecode.css -o output.html
	pandoc -s -S --toc bytecode -o output.tex
	pdflatex output.tex

clean:
	rm -f output.*
	rm -f build.png
