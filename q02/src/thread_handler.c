#include "thread_handler.h"
#include <stdio.h>

#include <stdlib.h>

void* fill_vector_w(void* thread_arguments)
{
	struct thread_arguments* thread_args = (struct thread_arguments*) thread_arguments;
	thread_args->vector[thread_args->vector_position] = 1;
	printf("Escrevendo 1 na posição %d do vetor w\n", thread_args->vector_position);
	return NULL;
}