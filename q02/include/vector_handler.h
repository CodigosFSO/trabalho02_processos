#ifndef VECTOR_HANDLER_H
#define VECTOR_HANDLER_H

int* initialize_vectors(int integers_amount);
pthread_t* initialize_thread_vectors(int threads_amount);
struct thread_arguments* initialize_thread_arguments_vectors(int arguments_amount);
void print_vector(int* vector, int integers_amount);

#endif