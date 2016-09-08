#ifndef THREAD_HANDLER_H
#define THREAD_HANDLER_H

struct thread_arguments
{
	int* vector;
	int vector_position;
};


void* fill_vector_w(void* thread_arguments);

#endif