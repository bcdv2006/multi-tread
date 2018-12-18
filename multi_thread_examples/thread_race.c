/*
 * How to build : gcc thread_race.c -o thread_race -lpthread
 */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

int global_var;

void *do_thread1(void *data);
void *do_thread2(void *data);

int main()
{
	int res;
	int i;
	pthread_t p_thread1;
	pthread_t p_thread2;

	res = pthread_create(&p_thread1, NULL, do_thread1, NULL);
	if(res != 0)
	{
		perror("Thread1 created error");
		exit(EXIT_FAILURE);
	}

	res = pthread_create(&p_thread2, NULL, do_thread2, NULL);
	if(res != 0)
	{
		perror("Thread2 created error");
		exit(EXIT_FAILURE);
	}

	for(i=1;i<20;i++)
	{
		printf("Main thread waiting %d second...\n", i);
		sleep(1);
	}

	return 0;
}

void *do_thread1(void *data)
{
	int i;

	for(i=1; i<=5; i++)
	{
		printf("Thread 1 count: %d with global value %d \n", i, global_var++);
		sleep(1);
	}

	printf("Thread1 1 completed !\n");
}

void *do_thread2(void *data)
{
	int i;

	for(i=1; i<=5; i++)
	{
		printf("Thread 2 count : %d with global value %d \n", i, global_var--);
		sleep(2);
	}

	printf("Thread 2 completed !\n"); 
}