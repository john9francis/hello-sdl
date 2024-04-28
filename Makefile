SRCDIR = src
INCLUDEDIR = include

SDLDIR = sdl

SRCS = $(wildcard $(SRCDIR)/*.cc)

all:
	g++ main.cc $(SRCS) -o main \
	-I$(INCLUDEDIR) \
	-I$(SRCDIR) \
	-I$(SDLDIR)/SDL2-2.30.2/x86_64-w64-mingw32/include \
	-L$(SDLDIR)/SDL2-2.30.2/x86_64-w64-mingw32/lib  \
	-lmingw32 \
	-lSDL2main \
	-lSDL2