#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 4
#define MAX_NUM 20

pthread_mutex_t mutex;              // Mutex for synchronization
pthread_cond_t condition_variable;  // Condition variable to control thread execution
int current_number = 1;             // Shared variable to track the current number

void* printNumbers(void* thread_id) {
    int id = *(int*)thread_id;
    
    while (1) {
        pthread_mutex_lock(&mutex);
        
        // Check if it's this thread's turn to print
        if (current_number % NUM_THREADS == id) {
            if (current_number <= MAX_NUM) {
                printf("Thread %d: %d\n", id, current_number);
                current_number++;
            } else {
                pthread_mutex_unlock(&mutex);
                pthread_exit(NULL);
            }
        } else {
            pthread_mutex_unlock(&mutex);
            continue;
        }
        
        pthread_mutex_unlock(&mutex);
        
        // Signal the next thread to print
        //pthread_cond_broadcast(&condition_variable);
        pthread_cond_signal(&condition_variable);
    }
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&condition_variable, NULL);

    // Create four threads
    for (int i = 0; i < NUM_THREADS; ++i) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, printNumbers, &thread_ids[i]);
    }

    // Join the threads
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex and condition variable
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&condition_variable);

    return 0;
}

