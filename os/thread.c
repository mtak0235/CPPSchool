#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum = 0;

void *thread1(void *p) {
	printf("thread1 start\n");
	int *i = (int *)malloc(sizeof(int));
	for (*i = 0; *i < (*(int *)p) ; (*i)++) {

		sum += 1;
	}
	printf("thread1: %d\n", sum);
	return (void *)i;
}
void *thread2(void *p) {
	printf("thread2 start\n");
	int *i = (int *)malloc(sizeof(int));
	for (*i = 0; *i < (*(int *)p) ; (*i)++) {

		sum -= 1;
	}
	printf("thread2: %d\n", sum);
	return (void *)i;
}
int main(int argc, char **av) {
	pthread_t tid1, tid2;
	int cnt = 200000;
	int *ret1, *ret2;
	pthread_create(&tid1, NULL, thread1, &cnt);
	printf("tid1: %lu\n", (unsigned long)tid1);
	pthread_create(&tid2, NULL, thread2, &cnt);
	printf("tid2: %lu\n", (unsigned long)tid2);

	pthread_join(tid1, (void **)&ret1);
	pthread_join(tid2, (void **)&ret2);

	printf("ret1 : %d \nret2: %d", *ret1, *ret2);
	printf("sum : %d\n", sum);
}