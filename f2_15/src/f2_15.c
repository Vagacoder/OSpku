/*
 ============================================================================
 Name        : f2_15.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Book P. 108 Figure 2-15, An example program using threads

 Using		 : Eclipse CDT does not find pthread_create, I use command line:
 	 	 	    $ gcc -pthread f2_15.c -o f2_15
 	 	 	    $ ./f2_15
 ============================================================================
 */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_THREADS 10

// this function prints the threads' identifier and then exits.
void *print_hello_world(void* tid){
	int* id = tid;
	printf("Hello World. Greeting from thread %d\n", *id);
	pthread_exit(NULL);
}

// main program creates 10 threads and then exits
int main(void) {

	pthread_t threads[NUMBER_OF_THREADS];
	int status, i;

	for(i=0; i<NUMBER_OF_THREADS;i++){
		printf("Main here. Create thread %d\n", i);
		status = pthread_create(&threads[i], NULL, print_hello_world, (void*)&i);

		if(status !=0){
			printf("Oops. pthread_create returned error code %d\n", status);
			exit(-1);
		}
	}

	return EXIT_SUCCESS;
}
