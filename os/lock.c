#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
const int count = 200000;
int sum = 0;	   // global variable, shared data
bool lock = false; // lock
void *myThread1(void *p)
{
	for (int i = 0; i < count; i++)
	{
		while (lock == true)
			; // critical section
		lock = true;
		sum += 1;
		lock = false;
	}
	return 0;
}
void *myThread2(void *p)
{
	for (int i = 0; i < count; i++)
	{
		while (lock == true)
			; // critical section
		lock = true;
		sum -= 1;
		lock = false;
	}
	return 0;
}
int main()
{
	pthread_t tid1, tid2; // thread id
	int count = 200000;
	int *ret1, *ret2;
	printf("Start!\n");
	pthread_create(&tid1, NULL, myThread1, NULL);
	pthread_create(&tid2, NULL, myThread2, NULL);
	pthread_join(tid1, (void **)&ret1); // waiting for 'tid1'
	pthread_join(tid2, (void **)&ret2); // waiting for 'tid2'
	printf("sum = %d\n", sum);
	return 0;
}