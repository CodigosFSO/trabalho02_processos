#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "arguments_handler.h"
#include "vector_handler.h"

int main(int argc, char* argv[])
{
	int integers_amount;
	int* vector_v;

	if(argc < 3) {
		printf("número de argumentos inválido!\n");
		return 0;
	}
	else {
		integers_amount = find_integers_amount(argc, argv);
		vector_v = tranlaste_arguments_to_vector(integers_amount, argv);
	}

	print_vector(vector_v, integers_amount);

	return 0;
}