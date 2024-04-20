#include<stdio.h>
#include<pthread.h>

//Global variable
int MAX=10;
int count=1;

//Declare mutex and condition varaible
pthread_mutex_t thr;
pthread_cond_t cond;

//create 1st thread
void *odd(void *arg)
{
    while (count < MAX) {
    	pthread_mutex_lock(&thr);
	if(count % 2 == 0) {
		pthread_cond_wait(&cond, &thr);
	}
		printf("o%d ", count);
		count++;
		pthread_mutex_unlock(&thr);
		pthread_cond_signal(&cond);
    }
    pthread_exit(0);
}

//create 2nd thread
void *even(void *arg)
{
    while (count < MAX) {
    	pthread_mutex_lock(&thr);
	if(count % 2 != 0) {
		pthread_cond_wait(&cond, &thr);
	}
		printf("e%d ", count);
		count++;
		pthread_mutex_unlock(&thr);
		pthread_cond_signal(&cond);
    }
    pthread_exit(0);
}


int main()
{
   pthread_t thread1, thread2;

   //initiliaze mutex and cond variable
   pthread_mutex_init(&thr, 0);
   pthread_cond_init(&cond, 0);

   //creating threads
   pthread_create(&thread1, 0, &even, NULL);
   pthread_create(&thread2, 0, &odd, NULL);

   //waiting for thread closure
   pthread_join(thread1, 0);
   pthread_join(thread2, 0);

   pthread_mutex_destroy(&thr);
   pthread_cond_destroy(&cond);

   return 0;

}
