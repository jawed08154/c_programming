#include<stdio.h>
#include<pthread.h>
#define MAX 10

// Declaration of thread condition variable
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
 
// declaring mutex
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
 
int done = 0;

void *func1(void *vargp)
{
	int i;
   

        pthread_mutex_lock(&lock);
	if (done == 0) {
		pthread_cond_wait(&cond, &lock);
	}	
	for (i = 0; i < MAX; i++) {
		if(i % 2 == 0)
			printf("%d ", i);
		pthread_mutex_unlock(&lock);
	}
       
}

void *func2(void *vargp)
{
	int i;
	for (i = 0; i < MAX; i++) {
		if(i % 2 != 0) {
                       pthread_mutex_lock(&lock);
			printf("%d ", i);
		done = 1;
		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&lock);
		}	
	}
}


int main(void)
{

	pthread_t  tid1, tid2;
	
	// Create 2 threads 
	pthread_create(&tid1, NULL, func1, NULL);
	pthread_create(&tid2, NULL, func2, NULL);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

return 0;
}
