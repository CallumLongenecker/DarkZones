OBJS	= DarkZone.o Queue.o Stack.o
SOURCE	= DarkZone.cpp Queue.cpp Stack.cpp
HEADER	= Queue.h Stack.h
OUT	= a.out
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

DarkZone.o: DarkZone.cpp
	$(CC) $(FLAGS) DarkZone.cpp -std=c++11

Queue.o: Queue.cpp
	$(CC) $(FLAGS) Queue.cpp -std=c++11

Stack.o: Stack.cpp
	$(CC) $(FLAGS) Stack.cpp -std=c++11


clean:
	rm -f $(OBJS) $(OUT)