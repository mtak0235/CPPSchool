#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
const int count = 200000;
int sum = 0; // global variable, shared data
pthread_mutex_t lock;
void *myThread1(void *p)
{
	for (int i = 0; i < count; i++)
	{
		pthread_mutex_lock(&lock); // entry
		sum += 1;
		pthread_mutex_unlock(&lock); // exit
	}
	printf("\033[33m thread1 \033[30m");
	return 0;
}
void *myThread2(void *p)
{
	for (int i = 0; i < count; i++)
	{
		pthread_mutex_lock(&lock); // entry
		sum -= 1;
		pthread_mutex_unlock(&lock); // exit
	}
	printf("\033[33m  thread2 \033[30m");
	return 0;
}
int main()
{
	pthread_t tid1, tid2; // thread id
	int count = 20;
	int *ret1, *ret2;
	printf("Start!\n");
	pthread_mutex_init(&lock, NULL); // init mutex
	pthread_create(&tid1, NULL, myThread1, NULL);
	pthread_create(&tid2, NULL, myThread2, NULL);
	printf("\033[32m  1 \033[30m");
	pthread_join(tid1, (void **)&ret1); // waiting for 'tid1'
	printf("\033[32m  2 \033[30m");
	pthread_join(tid2, (void **)&ret2); // waiting for 'tid2'
	printf("\033[32m  3 \033[30m");
	printf("sum = %d\n", sum);
	pthread_mutex_destroy(&lock); // destroy mutex
	return 0;
}