CC = /home/noderyos/emsdk/upstream/emscripten/emcc
TARGET =game

all:
	$(CC) -o $(TARGET).html src/main.c ../raylib/src/libraylib.a \
		-Os -Wall \
		-Iinclude -I../raylib/src \
		-L../raylib/src \
		-s USE_GLFW=3 -s ASYNCIFY \
		--shell-file shell.html -DPLATFORM_WEB
	cp shell.html game.html
	sed -i 's/{{{ SCRIPT }}}/<script src=game.js async><\/script>/g' game.html
	cp game.* ../client/
	mv ../client/game.html ../client/index.html


clean:
	rm -fr $(TARGET).* obj
