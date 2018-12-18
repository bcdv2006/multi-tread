/*
 * How to build : gcc thread_race2.c -o thread_race2 -lpthread
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int global_var;

pthread_mutex_t a_mutex;

void *do_thread1(void *data);
void *do_thread2(void *data);

int main()
{
	int res;
	int i;
	pthread_t p_thread1;
	pthread_t p_thread2;

	res = pthread_mutex_init(&a_mutex, NULL);
	
	/*
		Another way to init mutex : 
			a_mutex = PTHREAD_MUTEX_INITIALIZER
	*/

	if(res != 0)
	{
		perror("Mutex create error");
		exit(EXIT_FAILURE);
	}

	/* Create thread 1 */
	res = pthread_create(&p_thread1, NULL, do_thread1, NULL);
	if(res != 0)
	{
		perror("Thread1 created error");
		exit(EXIT_FAILURE);
	}

	/* Create thread 2 */
	res = pthread_create(&p_thread2, NULL, do_thread2, NULL);
	if(res != 0)
	{
		perror("Thread2 created error");
		exit(EXIT_FAILURE);
	}

	/* Main thread of program */
	for(i=1; i<20; i++)
	{
		printf("Main thread waiting %d second...\n", i);
		sleep(1);
	}

	return 0;
}

void *do_thread1(void *data)
{
	int i;

	pthread_mutex_lock(&a_mutex); /* lock mutex */

	for(i=1; i<=5; i++)
	{
		printf("Thread 1 count: %d with global value %d \n", i, global_var++);
		sleep(1);
	}

	pthread_mutex_unlock(&a_mutex); /* unlock mutex */

	printf("Thread1 completed !\n");
}

void *do_thread2(void *data)
{
	int i;

	pthread_mutex_lock(&a_mutex); /* lock mutex */

	for(i=1; i<=5; i++)
	{
		printf("Thread 2 count : %d with global value %d \n", i, global_var--);
		sleep(2);
	}

	pthread_mutex_unlock(&a_mutex); /* unlock mutex */

	printf("Thread2 completed !\n"); 
}