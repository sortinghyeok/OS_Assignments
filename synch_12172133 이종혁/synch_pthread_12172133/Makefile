CC = gcc
CFLAGS= -g -lpthread
TARGET = synch_pthread.exe
OBJS = synch_pthread.o

synch_pthread_exe : synch_pthread.o synch_pthread.c
	gcc -o Mutex12172133_exe Mutex_12172133.o $(CFLAGS)
synch_pthread.o : synch_pthread.c
	gcc -c -o synch_pthread.o synch_pthread.c $(CFLAGS)


clean :
	rm $(OBJS) $(TARGET)
