# Hello SDL

Development environment
- Windows 11
- SDL2-2.30.2

## Setting up development environment in Windows

How to set up g++ and make:


How to set up emscription:
- followed instructions [here](https://emscripten.org/docs/getting_started/downloads.html#platform-notes-installation-instructions-sdk)

How to set up SDL:
1. Download the latest release of SDL from the [SDL website.](https://www.libsdl.org/) make sure to download the 'devel' version for development.
2. create a directory called 'sdl' and place the entire release in that directory.
3. Find the dll file in the following location: sdl/SDL2\<version number\>/x86_64-w64-mingw32/bin/SDL2.dll
4. Copy this SDL2.dll file into the same directory as the main.cc file
5. run 'make' and '.\main' to compile and run.


# Goals:
- test all the capabilities of SDL including graphics, sound, and input bindings
- cross development and cross compilation!

# Todo:
1. figure out how to build for webasm using [emcc](https://developer.mozilla.org/en-US/docs/WebAssembly/C_to_Wasm)
 - [making a wasm game](https://robaboukhalil.medium.com/porting-games-to-the-web-with-webassembly-70d598e1a3ec)
2. build for mac
3. build for linux