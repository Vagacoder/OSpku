/*
 ============================================================================
 Name        : f2_32.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Textbook Figure 2-32, P. 138
 	 	 	 	 Using threads to solve the producer-consumer problem

				 Problem description:
				 (1) single buffer;
				 (2) 2 threads: producer and consumer;

				 Solution from pthread library:
				 (1) Mutex variable (the_mutex), can be lock and unlock, to guard
				 each CR;
				 (2) Condition variable (condp and condc) allows thread to be
				 blocked due to some condition is not met.
			 	 (3) pthread_cond_wait() has 3 major internal implementations:
			 	 (3.1) unlock mutex: allow other thread to access CR
			 	 (3.2) wait self (current thread) in waiting queue
			 	 (3.3) once receive wakeup signal from pthread_signal/pthread_broadcast
			 	 	 immediate lock mutex
			 	 (4) The loop enclosing pthread_cond_wait() is while loop, this
			 	 suggests pthread is using MESA monitor
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 1000000000						// how many numbers to produce
pthread_mutex_t the_mutex;					// mutex
pthread_cond_t condc, condp;				// conditional variables, used for signaling
int buffer = 0;								// buffer used between producer and consumer

void *producer(void *ptr){					// produce data
	int i;

	for(i=1; i<=MAX; i++){
		pthread_mutex_lock(&the_mutex);		// get exclusive access to buffer; lock access to buffer

		while(buffer !=0){					// if buffer is full, producer waits in waiting queue
			pthread_cond_wait(&condp, &the_mutex);	// 1) lock producer 2) unlock access to buffer
		}											// for details, check the part about cond_wait() in top notes

		buffer=i;							// put item in buffer
		pthread_cond_signal(&condc);		// wake up consumer
		pthread_mutex_unlock(&the_mutex);	// release access to buffer
	}
	pthread_exit(0);
}

void *consumer(void *ptr){					// consumer data
	int i;

	for(i=0; i<MAX;i++){
		pthread_mutex_lock(&the_mutex);

		while(buffer==0){
			pthread_cond_wait(&condc, &the_mutex)
		}

		buffer = 0;							// take item from buffer
		pthread_cond_signal(&condp);		// wake up producer
		pthread_mutex_unlock(&the_mutex);	// release access to buffer
	}
	pthread_exit(0);
}



int main(int argc, char **argv) {
	// initialization
	pthread_t pro, con;						// declare threads
	pthread_mutex_init(&the_mutex, 0);		// init mutex
	pthread_cond_init(&condc, 0);			// conditional variable for consumer
	pthread_cond_init(&condp, 0);			// conditional variable for producer
	pthread_create(&con, 0, consumer, 0);	// create consumer thread (child)
	pthread_create(&pro, 0, producer, 0);	// create producer thread (child)
	pthread_join(pro, 0);					// main thread is waiting for 2 children threads
	pthread_join(con, 0);
	pthread_cond_destroy(&condc);			// after 2 children are complete, clean up
	pthread_cond_destroy(&condp);
	pthread_mutex_destroy(&the_mutex);


	return EXIT_SUCCESS;
}
