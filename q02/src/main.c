#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "arguments_handler.h"
#include "vector_handler.h"
#include "thread_handler.h"

int main(int argc, char* argv[])
{
	int integers_amount;
	int* vector_v;
	int* vector_w;
	pthread_t* threads_w;
	struct thread_arguments* thread_w_args;

	if(argc < 3) {
		printf("número de argumentos inválido!\n");
		return 0;
	}
	else {
		integers_amount = find_integers_amount(argc, argv);
		vector_v = tranlaste_arguments_to_vector(integers_amount, argv);
	}

	vector_w = initialize_vectors(integers_amount);
	threads_w = initialize_thread_vectors(integers_amount);
	thread_w_args = initialize_thread_arguments_vectors(integers_amount);

	int counter = 0;

	while(counter < integers_amount) {
		thread_w_args[counter].vector = vector_w;
		thread_w_args[counter].vector_position = counter;
		printf("Setando posição %d do vetor w\n", thread_w_args[counter].vector_position);
		pthread_create(&threads_w[counter], NULL, &fill_vector_w, &thread_w_args[counter]);
		counter++;
	}


	counter = 0;

	while(counter < integers_amount) {
		pthread_join(threads_w[counter], NULL);
		counter++;
	}

	print_vector(vector_v, integers_amount);
	print_vector(vector_w, integers_amount);

	free(vector_v);
	free(vector_w);
	free(threads_w);

	return 0;
}