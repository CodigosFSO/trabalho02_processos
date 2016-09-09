#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "arguments_handler.h"
#include "vector_handler.h"
#include "thread_handler.h"

int main(int argc, char* argv[])
{
	int integers_amount;
	int second_step_threads_amount;
	int* vector_v;
	int* vector_w;
	pthread_t* threads_w;
	pthread_t* second_step_threads;
	struct thread_w_arguments* thread_w_args;

	if(argc < 3) {
		printf("número de argumentos inválido!\n");
		return 0;
	}
	else {
		integers_amount = find_integers_amount(argc, argv);
		second_step_threads_amount = (integers_amount * (integers_amount - 1) / 2);
		printf("Fator etapa 2: %d\n", second_step_threads_amount);
		vector_v = tranlaste_arguments_to_vector(integers_amount, argv);
	}

	vector_w = initialize_vectors(integers_amount);
	threads_w = initialize_thread_vectors(integers_amount);
	thread_w_args = initialize_thread_w_arguments_vectors(integers_amount, vector_w);

	create_threads_w(threads_w, thread_w_args, integers_amount);
	join_threads(threads_w, integers_amount);

	free(threads_w);
	free(thread_w_args);

	second_step_threads = initialize_thread_vectors(second_step_threads_amount);

	printf("Number of input values = %d\n", integers_amount);
	printf("Input values x = ");
	print_vector(vector_v, integers_amount);
	printf("After initialization w = ");
	print_vector(vector_w, integers_amount);

	free(second_step_threads);
	free(vector_v);
	free(vector_w);

	return 0;
}