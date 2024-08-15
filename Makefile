CC = g++
SRC = main.cpp
TARGET = fqueue 

lightchatcli: $(SRC) lib
	$(CC) -o $(TARGET) $(SRC) -L. -lMyLib

lib: node.o
	ar rc libMyLib.a node.o

liblogger: node.cpp node.h
	$(CC) -o node.o node.cpp -c

clear:
	rm *.o *.a
