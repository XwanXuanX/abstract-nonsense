# =============================================================================
# LaTeX Multi-File Build Script with Centralized Output Directory (build/)
# =============================================================================
# USAGE:
#   make
#       - Builds PDFs for all .tex files in the current directory.
#
#   make clean
#       - Removes auxiliary files for all .tex files (from build/).
#
#   make distclean
#       - Removes all auxiliary files and PDFs from build/.
#
# OUTPUT:
#   - All generated files (.pdf, .aux, .log, .bbl, etc.) are placed in the build/ subdirectory.
#
# REQUIREMENTS:
#   - latexmk must be installed and available in your PATH.
#
# NOTES:
#   - The Makefile automatically creates the build/ directory if it doesn't exist.
#   - Auxiliary files are cleaned only from the build/ directory.
# =============================================================================

TEXFILES := $(wildcard *.tex)
PDFS := $(addprefix build/,$(TEXFILES:.tex=.pdf))

# Ensure build directory exists before building
$(shell mkdir -p build)

all: $(PDFS)

build/%.pdf: %.tex
	latexmk -pdf -outdir=build $<

clean:
	latexmk -C -outdir=build
	rm -f build/*.bbl build/*.blg build/*.run.xml build/*.bcf build/*.out

distclean: clean
	rm -f build/*.pdf

.PHONY: all clean distclean
