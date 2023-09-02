SDL2INC="D:/libraries/SDL2-2.28.2/include/"
SDL2LIB="D:/libraries/SDL2-2.28.2/lib/x64/"

win_all: src/main.c
	@cp "$(SDL2LIB)"\SDL2.dll .
	@cl /W4 /sdl /nologo \
		/std:c17 \
		/Zi \
		/EHsc \
		/I$(SDL2INC) \
		/Feseamap-trader.exe \
		src/display.c \
		src/map_generator.c \
		src/color.c \
		src/main.c \
		src/win_rand.c \
		shell32.lib \
		User32.lib \
		Advapi32.lib \
		/link /LIBPATH:"$(SDL2LIB)" \
					SDL2.lib SDL2main.lib

win_run:
	3drenderer.exe

win_clean:
	@del *.obj *.exe *.ilk *.pdb *.dll *.lib *~

