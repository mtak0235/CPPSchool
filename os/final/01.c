#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>
#include <dispatch/dispatch.h>

#define N_COUNTER 4 // the size of a shared buffer
#define MILLI 1000	// time scale

void mywrite(int n);
int myread();

pthread_mutex_t critical_section;		// POSIX mutex
dispatch_semaphore_t semWrite, semRead; // POSIX semaphore
int queue[N_COUNTER];					// shared buffer
int wptr;								// write pointer for queue[]
int rptr;								// read pointer for queue[]

// producer thread function
void *producer(void *arg)
{
	for (int i = 0; i < 10; i++)
	{
		mywrite(i); /**** write i into the shared memory ****/
		printf("producer : wrote %d\n", i);

		// sleep m miliseconds
		int m = rand() % 10;
		usleep(MILLI * m * 10); // m*10
	}
	return NULL;
}

// consumer thread function
void *consumer(void *arg)
{
	for (int i = 0; i < 10; i++)
	{
		int n = myread(); /**** read a value from the shared memory ****/
		printf("\tconsumer : read %d\n", i);

		// sleep m miliseconds
		int m = rand() % 10;
		usleep(MILLI * m * 10); // m*10
	}
	return NULL;
}

// write n into the shared memory
void mywrite(int n)
{
	dispatch_semaphore_wait(semWrite, DISPATCH_TIME_FOREVER);
	pthread_mutex_lock(&critical_section);
	queue[wptr] = n;
	wptr = (wptr + 1) / N_COUNTER;
	pthread_mutex_unlock(&critical_section);
	dispatch_semaphore_signal(semRead);
}

// write a value from the shared memory
int myread()
{
	int n;
	dispatch_semaphore_wait(semRead, DISPATCH_TIME_FOREVER);
	pthread_mutex_lock(&critical_section);
	n = queue[rptr];
	rptr = (rptr + 1) / N_COUNTER;
	pthread_mutex_unlock(&critical_section);
	dispatch_semaphore_signal(semWrite);
	return n;
}

int main()
{
	pthread_t t[2]; // thread structure
	srand(time(NULL));

	//wptr, rptr 초기화 
	wptr  = 0;
	rptr = 0;
	pthread_mutex_init(&critical_section, NULL); // init mutex

	// init semaphore
	semWrite = dispatch_semaphore_create(4);
	semRead = dispatch_semaphore_create(0);

	// create the threads for the producer and consumer
	pthread_create(&t[0], NULL, producer, NULL);
	pthread_create(&t[1], NULL, consumer, NULL);

	for (int i = 0; i < 2; i++)
		pthread_join(t[i], NULL); // wait for the threads

	// destroy the semaphores
	dispatch_release(semWrite);
	dispatch_release(semRead);
	
	pthread_mutex_destroy(&critical_section); // destroy mutex
	return 0;
}
