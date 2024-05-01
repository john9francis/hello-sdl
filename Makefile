SRCDIR = src
INCLUDEDIR = include
SDLDIR = sdl
WIN_DIST_DIR = win
WEB_DIST_DIR = wasm

SRCS = $(wildcard $(SRCDIR)/*.cc)

all:
	@echo options:
	@echo 'make windows' for a windows build
	@echo 'make web' for a web build with wasm

windows:
	if exist $(WIN_DIST_DIR) rmdir /s /q $(WIN_DIST_DIR)
	mkdir $(WIN_DIST_DIR)
	g++ web_main.cc $(SRCS) -o $(WIN_DIST_DIR)/main \
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
	emcc web_main.cc $(SRCS) -o $(WEB_DIST_DIR)/index.js \
	-I$(INCLUDEDIR) \
	-I$(SRCDIR) \
	-s USE_SDL=2 \
	-s USE_SDL_IMAGE=2 \
	-s SDL2_IMAGE_FORMATS='["png"]'
	copy index.html $(WEB_DIST_DIR)