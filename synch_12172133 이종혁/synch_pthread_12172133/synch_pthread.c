#include <pthread.h>
#include <stdio.h>
#define MAX 30

void *producer(void *);
void *consumer(void *);
void put();
void get();

int x = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t empty = PTHREAD_COND_INITIALIZER;
pthread_cond_t fill = PTHREAD_COND_INITIALIZER;


int main()
{
	printf("12172133 Lee Jonghyeok\n");
	pthread_t threads[2];
	pthread_create(&threads[0], NULL, producer, NULL);
	pthread_create(&threads[1], NULL, consumer, NULL);

	pthread_join(threads[0], NULL);
	pthread_join(threads[1], NULL);

	if(x==0)
	printf("The last one is %d\n", x);
	return 0;
}

void *producer(void *arg) {
	int i;
	for(i = 0; i<1000; i++)
	{
		pthread_mutex_lock(&mutex);
		if (x == MAX -1)
			pthread_cond_wait(&empty, &mutex);
		printf("%u : %d\n", (unsigned int)pthread_self(), x);
		put();
		pthread_cond_signal(&fill);
		pthread_mutex_unlock(&mutex);	
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
		pthread_mutex_lock(&mutex);
		if (x == 0)
			pthread_cond_wait(&fill, &mutex);
		printf("%u : %d\n", (unsigned int)pthread_self(), x);
		get();
		pthread_cond_signal(&empty);
		pthread_mutex_unlock(&mutex);
		
	}
}

void get()
{
	x--;
}
