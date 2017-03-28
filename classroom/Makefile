OBJS = main.o classRoom.o
CC = g++
DEBUG = -g
CFLAGS = -std=c++11 -Wall -c $(DEBUG)
LFLAGS = -std=c++11 -Wall $(DEBUG)
EXECUTALBES = main

#put rest of main functions in all to compile everything
all:main

main : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o main

classRoom.o : classRoom.h classRoom.cpp 
	$(CC) $(CFLAGS) classRoom.cpp

main.o : 
	$(CC) $(CFLAGS) main.cpp



clean:
	rm -f *.o main


tar:
	tar cfv main.tar main.h main.cpp classRoom.h classRoom.cpp 

program1:
	./main

	
