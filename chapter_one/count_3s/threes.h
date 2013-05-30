#include <stdlib.h>
#include <time.h>

struct array_struct {
        int* values;
        int length;
} typedef array_t;

array_t* create_array(int length, int upperbound);

void free_array(array_t* array) {
        free(array->values);
        free(array);
}

array_t* create_array(int length, int upperbound) {
        srand(time(NULL));
        array_t* value = (array_t*)malloc(sizeof(array_t));
        value->values = (int*)calloc(length, sizeof(int));
        value->length = length;

        int i;
        for(i = 0; i < length; ++i) {
                value->values[i] = rand() % upperbound;
        }

        return value;
}
