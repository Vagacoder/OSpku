/*
 ============================================================================
 Name        : f2_28.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : textbook P. 131 Figure 2-28
 	 	 	 	 The producer-consumer problem using semaphore

 	 	 	 	 Note:
 	 	 	 	 (1). In this example, semaphore is not same as described in
 	 	 	 	 textbook;
 	 	 	 	 	 	 	 	 This example		  Textbook
				 Init val		   1					1

				 P before test     s--					None
				 P test			  s<0					s>0		s==0
				 P test op		  sleep					s--		s-- and sleep

				 V before test	   s++					s++
				 V test 		  s<=0					s<=0
				 V test op		  wakeup				wakeup

				 (2) Can we invert P and V operations? Is there any deadlock?
				 2x P operations (before insert/remove) can NOT be inverted;
				 2x V operations (after insert/remove) can be inverted;

				 (3) Details for deadlock in (2), when 2x P ops are inverted:
				     Suppose that the two P ops in the producer’s code were
				   reversed in order, so mutex was decremented before empty
				   instead of after it. If the buffer were completely full,
				   the producer would block, with mutex set to 0.
				     Consequently, the next time the consumer tried to access
				   the buffer, it would do a P op on mutex, now 0, and block
				   too. Both processes would stay blocked forever and no more
				   work would ever be done.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define N 100				// number of slots in the buffer
typedef int semaphore;		// semaphores are a special kind of int
semaphore mutex = 1;		// controls access to critical region
semaphore empty = N;		// counts empty buffer slots
semaphore full = 0;		// counts full buffer slots

void producer(void){
	int item;

	while(1){
		item = produce_item();
		P(&empty);
		P(&mutex);
		insert_item(item);
		V(&mutex);
		V(&full);
	}
}

void consumer(void){
	int item;

	while(1){
		P(&full);
		P(&mutex);
		item = remove_item();
		V(&mutex);
		V(&empty);
		consume_item(item);
	}
}

// Note: the implementation is different from textbook
P(semaphore s){
	s--;
	if(s < 0){
		// blocking, move this process to waiting queue; reschedule
	}
}

// Note: the implementation id different from textbook
V(semaphore s){
	s++;
	if(s<=0){
		// wake one of related process,
	}
}



int produce_item(){
	return 1;
}

void insert_item(int a){

}

int remove_item(){
	return 2;
}

void consume_item( int a){

}


int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
