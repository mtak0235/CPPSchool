#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
const int count = 200000;
int sum = 0;		// global variable, shared data
bool lock1 = false; // lock1
bool lock2 = false; // lock2
void *myThread1(void *p)
{
	for (int i = 0; i < count; i++)
	{
		lock1 = true;
		while (lock2 == true)
			; // critical section
		sum += 1;
		lock1 = false;
	}
	return 0;
}
void *myThread2(void *p)
{
	for (int i = 0; i < count; i++)
	{
		lock2 = true;
		while (lock1 == true)
			; // critical section
		sum -= 1;
		lock2 = false;
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
