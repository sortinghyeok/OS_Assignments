CC = gcc
CFLAGS= -g -lpthread
TARGET = synch_semaphore.exe
OBJS = synch_semaphore.o

synch_semaphore.exe : synch_semaphore.o synch_semaphore.c
	gcc -o synch_semaphore_exe synch_semaphore.o $(CFLAGS)
synch_semaphore.o : synch_semaphore.c
	gcc -c -o synch_semaphore.o synch_semaphore.c $(CFLAGS)


clean :
	rm $(OBJS) $(TARGET)
