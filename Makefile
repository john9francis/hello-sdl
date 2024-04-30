SRCDIR = src
INCLUDEDIR = include

SDLDIR = sdl

WIN_DIST_DIR = win

SRCS = $(wildcard $(SRCDIR)/*.cc)

all:
	if exist $(WIN_DIST_DIR) rmdir /s /q $(WIN_DIST_DIR)
	mkdir $(WIN_DIST_DIR)
	g++ main.cc $(SRCS) -o $(WIN_DIST_DIR)/main \
	-I$(INCLUDEDIR) \
	-I$(SRCDIR) \
	-I$(SDLDIR)/SDL2-2.30.2/x86_64-w64-mingw32/include \
	-L$(SDLDIR)/SDL2-2.30.2/x86_64-w64-mingw32/lib  \
	-lmingw32 \
	-lSDL2main \
	-lSDL2
	copy $(SDLDIR)\SDL2-2.30.2\x86_64-w64-mingw32\bin\SDL2.dll $(WIN_DIST_DIR)