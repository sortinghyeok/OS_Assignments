CC = gcc
CFLAGS=-g -Wall
TARGET = myShell.exe
OBJS = myShell_12172133.o

myShell_exe : myShell_12172133.o myShell_12172133.c
	gcc -o myShell_exe myShell_12172133.o
myShell_12172133.o : myShell_12172133.c
	gcc -c -o myShell_12172133.o myShell_12172133.c


clean :
	rm $(OBJS) $(TARGET)
