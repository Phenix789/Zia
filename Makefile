all: do view

do:
	doxygen doxyConfig

view:
	firefox docs/doxygen/html/index.html

clean:
	rm -rf docs/doxygen/html docs/doxygen/latex