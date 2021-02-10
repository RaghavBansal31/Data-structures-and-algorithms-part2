EXEC = run
CC = g++
CFLAGS = -c -Wall

$(EXEC) :Main.o Util.o heap.o
	$(CC) -o $(EXEC) Main.o Util.o heap.o


heap.o: heap.h heap.cpp
	$(CC) $(CFLAGS) heap.cpp

util.o: Util.h Util.cpp
	$(CC) $(CFLAGS) Util.cpp

main.o:Util.h Main.cpp
	$(CC) $(CFLAGS) Main.cpp

clean   :
	rm *.o
