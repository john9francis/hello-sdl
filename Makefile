SRCDIR = src
INCLUDEDIR = include
SDLDIR = sdl
WIN_DIST_DIR = win
WEB_DIST_DIR = web

SRCS = $(wildcard $(SRCDIR)/*.cc)

all:
	@echo to build for windows, run 'make windows'

windows:
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

web:
	if exist $(WEB_DIST_DIR) rmdir /s /q $(WEB_DIST_DIR)
	mkdir $(WEB_DIST_DIR)
	emcc main.cc $(SRCS) -o $(WEB_DIST_DIR)/index.html \
	-I$(INCLUDEDIR) \
	-I$(SRCDIR) \
	-I$(SDLDIR)/SDL2-2.30.2/x86_64-w64-mingw32/include \
	-L$(SDLDIR)/SDL2-2.30.2/x86_64-w64-mingw32/lib  \
	-lmingw32 \
	-lSDL2main \
	-lSDL2
	-s USE_SDL=2
	copy $(SDLDIR)\SDL2-2.30.2\x86_64-w64-mingw32\bin\SDL2.dll $(WEB_DIST_DIR)