CC = g++
CPPFLAGS = -std=c++11 -Wall -g

main: main.o Song.o SongList.o

main.o: Song.h SongList.h main.cpp

Song.o: Song.h Song.cpp

SongList.o: Song.h SongList.h SongList.cpp

clean: 
	rm main *.o

check: 
	valgrind --leak-check=full ./main
