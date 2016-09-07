#include <stdio.h>
#include <stdlib.h>

#include "vector_handler.h"

int* initialize_vectors(int integers_amount)
{
	int* vector = (int*) malloc(integers_amount * sizeof(int));

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