#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "vector_handler.h"
#include "thread_handler.h"

int* initialize_vectors(int integers_amount)
{
	int* vector = (int*) malloc(integers_amount * sizeof(int));

	return vector;
}

pthread_t* initialize_thread_vectors(int threads_amount)
{
	pthread_t* vector = (pthread_t*) malloc(threads_amount * sizeof(pthread_t));
	return vector;
}

struct thread_arguments* initialize_thread_arguments_vectors(int arguments_amount)
{
	struct thread_arguments* vector = (struct thread_arguments*) malloc(arguments_amount * sizeof(struct thread_arguments));
	return vector;
}

void print_vector(int* vector, int integers_amount)
{
	printf("imprimindo vetor: \n");
	int counter = 0;
	while(counter < integers_amount) {
		printf("%d ", vector[counter]);
		counter++;
	}

	printf("\n");

	return;
}