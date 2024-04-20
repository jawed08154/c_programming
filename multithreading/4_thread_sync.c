#include<stdio.h>
#include<pthread.h>

//mutex 
pthread_mutex_t lock;


//thread functions 
void *fun1(void * args)
{
	pthread_mutex_lock(&lock);

	printf("Inside func 1\n");

	pthread_mutex_unlock(&lock);

	pthread_exit(NULL);
}


//thread functions 
void *fun2(void * args)
{
	pthread_mutex_lock(&lock);

	printf("Inside func 2\n");

	pthread_mutex_unlock(&lock);

	pthread_exit(NULL);

}

//thread functions 
void *fun3(void * args)
{
	pthread_mutex_lock(&lock);

	printf("Inside func 3\n");

	pthread_mutex_unlock(&lock);

	pthread_exit(NULL);
}


//thread functions 
void *fun4(void * args)
{
	pthread_mutex_lock(&lock);

	printf("Inside func 4\n");

	pthread_mutex_unlock(&lock);

	pthread_exit(NULL);
}

int main()
{
	pthread_t thread1, thread2,thread3, thread4;
        pthread_mutex_init(&lock, NULL);

	//create 4 threads , each executing diffrent function
	pthread_create(&thread1, NULL, fun1, NULL);
	pthread_create(&thread2, NULL, fun2, NULL);
	pthread_create(&thread3, NULL, fun3, NULL);
	pthread_create(&thread4, NULL, fun4, NULL);
        
	//TO run infinitely
        //while(1);

	//Wait for all threads to finish
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
	pthread_join(thread4, NULL);

	pthread_mutex_destroy(&lock);

	return 0;
}
