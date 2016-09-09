#include "thread_handler.h"

#include <stdio.h>
#include <stdlib.h>

void* fill_vector_w(void* thread_arguments)
{
	struct thread_w_arguments* thread_args = (struct thread_w_arguments*) thread_arguments;
	thread_args->vector[thread_args->vector_position] = 1;
	return NULL;
}

void create_threads_w(pthread_t* threads, struct thread_w_arguments* thread_args, int threads_amount)
{
	int counter = 0;
	while(counter < threads_amount) {
		thread_args[counter].vector_position = counter;
		pthread_create(&threads[counter], NULL, &fill_vector_w, &thread_args[counter]);
		counter++;
	}
}

void join_threads(pthread_t* threads, int threads_amount)
{
	int counter = 0;

	while(counter < threads_amount) {
		pthread_join(threads[counter], NULL);
		counter++;
	}
}