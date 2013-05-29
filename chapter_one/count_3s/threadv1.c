#include <stdio.h>
#include "threes.h"
#include <pthread.h>

void count_threes(void* args);

int count;
pthread_mutex_t m;

struct count_args {
        int* array;
        int length;
        int id;
};

int main(int argc, char* argv[]) {
        count = 0;
        int threadCount = 1;

        pthread_t* threads = malloc(sizeof(pthread_t) * threadCount);
        pthread_mutex_init(&m, NULL);

        array_t* array = create_array(100000000, 40);

        int length = array->length / threadCount;

        for(int i = 0; i < threadCount; ++i) {
                struct count_args args;
                args.array = array->values;
                args.length = length;
                args.id = i;

                pthread_create(&threads[0], NULL, (void*) &count_threes, (void*) &args);
        }

         for (int k = 0; k < threadCount; k++) {
                 pthread_join(threads[k], NULL);
         }

        printf("Threes: %d\n", count);

        free_array(array);
        return 0;
}

void count_threes(void* arg) {

        struct count_args* args = (struct count_args*)arg;
        int offset = args->length * args->id;

        for (int i = offset; i < offset + args->length; ++i) {
                if (3 == args->array[i]) {

                        // Obtain lock each time we update count.
                        pthread_mutex_lock(&m);
                        count++;
                        pthread_mutex_unlock(&m);
                }
        }
}
