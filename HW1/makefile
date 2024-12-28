COMP_FLAG = -std=c99 -Wall -pedantic-errors -Werror -Itool -I/home/mtm/public/2223a/ex1 -DNDEBUG
AsciiArtTool: tool/AsciiArtTool.o tool/main.o RLEList.o
	gcc $(COMP_FLAG) tool/AsciiArtTool.o tool/main.o RLEList.o -o AsciiArtTool

tool/AsciiArtTool.o: tool/AsciiArtTool.h tool/AsciiArtTool.c RLEList.h
	gcc $(COMP_FLAG) -c  tool/AsciiArtTool.c -o $@

tool/main.o: tool/main.c tool/AsciiArtTool.h
	gcc $(COMP_FLAG) -c  tool/main.c -o $@
    
RLEList.o: RLEList.c RLEList.h
	gcc $(COMP_FLAG) -c  RLEList.c -o $@

clean:
	rm -f tool/main.o RLEList.o tool/AsciiArtTool.o AsciiArtTool
