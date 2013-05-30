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
        char padding[48];
};

struct local_count {
        char padding[60];
        int value;
};

struct local_count* counts;

int main(int argc, char* argv[]) {
        int threadCount = 4;
        counts = (struct local_count*)malloc(sizeof(struct local_count) * threadCount);
printf("Size: %lu\n", sizeof(int*));
        pthread_t* threads = malloc(sizeof(pthread_t) * threadCount);
        pthread_mutex_init(&m, NULL);

        array_t* array = create_array(100000000, 40);

        int length = array->length / threadCount;

        for(int i = 0; i < threadCount; ++i) {
                struct count_args args;
                args.array = array->values;
                args.length = length;
                args.id = i;

                pthread_create(&threads[i], NULL, (void*) &count_threes, (void*) &args);
        }

         for (int k = 0; k < threadCount; k++) {
                 pthread_join(threads[k], NULL);
         }

        for (int j = 0; j < threadCount; j++) {
                count += counts[j].value;
        }

        printf("Threes: %d\n", count);

        free(threads);
        free(counts);
        free_array(array);
        return 0;
}

void count_threes(void* arg) {

        struct count_args* args = (struct count_args*)arg;
        int id = args->id;
        int offset = args->length * id;

        counts[id].value = 0;

        for (int i = offset; i < offset + args->length; ++i) {
                if (3 == args->array[i]) {

                        ++counts[id].value;
                }
        }
}
