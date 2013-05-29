#include <stdio.h>
#include "threes.h"

int count_threes(int* array, int length);

int main(int argc, char* argv[]) {
        array_t* array = create_array(100000000, 40);
        int threes = count_threes(array->values, array->length);

        printf("Threes: %d\n", threes);
        free_array(array);
        return 0;
}

int count_threes(int* array, int length) {

        int count = 0;

        while(length--) {
                if (3 == array[length]) {
                        ++count;
                }
        }

        return count;
}
