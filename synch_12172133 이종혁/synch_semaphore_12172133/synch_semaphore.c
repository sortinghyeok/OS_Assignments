#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#define MAX 30

void *producer(void *);
void *consumer(void *);
void put();
void get();

int x = 0;

sem_t mutex;
sem_t empty;
sem_t fill;


int main()
{
	printf("12172133 Lee Jonghyeok\n");
	sem_init(&mutex, 0 ,1);
	sem_init(&empty, 0, 30);
	sem_init(&fill, 0, 0);
	pthread_t threads[2];
	pthread_create(&threads[0], NULL, producer, NULL);
	pthread_create(&threads[1], NULL, consumer, NULL);

	

	pthread_join(threads[0], NULL);
	pthread_join(threads[1], NULL);
	if(x == 0)
	printf("The last one is : %d\n", x);
	return 0;
}

void *producer(void *arg) {
	int i;
	for(i = 0; i<1000; i++)
	{
		sem_wait(&empty);
		sem_wait(&mutex);
		printf("%u : %d\n", (unsigned int)pthread_self(), x);
		put();
		sem_post(&mutex);
		sem_post(&fill);
	
	}
}
void put()
{	
	x++;
}

void *consumer(void *arg) {
	int i;

	for(i = 0; i<1000; i++)
	{
		sem_wait(&fill);
		sem_wait(&mutex);
		printf("%u : %d\n", (unsigned int)pthread_self(), x);
		get();
		sem_post(&mutex);
		sem_post(&empty);
		
	}
}

void get()
{
	x--;
}
