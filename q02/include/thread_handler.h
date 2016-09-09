#ifndef THREAD_HANDLER_H
#define THREAD_HANDLER_H

#include <pthread.h>

struct thread_w_arguments
{
	int* vector;
	int vector_position;
};


void* fill_vector_w(void* thread_arguments);
void create_threads_w(pthread_t* threads, struct thread_w_arguments* thread_args, int threads_amount);
void join_threads(pthread_t* threads, int threads_amount);

#endif