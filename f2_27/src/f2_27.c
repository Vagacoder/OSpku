/*
 ============================================================================
 Name        : f2_27.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : textbook P.129 figure 2.27
 	 	 	 	 The producer-consumer problem with a !FATAL! race condition

 	 	 	 	 For this case:
 	 	 	 	 1. buffer is empty, count == 0;
 	 	 	 	 2. consumer read count and prepare to sleep, but not yet
 	 	 	 	 3. producer is switched and add a new item into buffer
 	 	 	 	 4. producer wakes up consumer
 	 	 	 	 5. switch back to consumer, it receives wakeup signal
 	 	 	 	 6. consumer ignore signal, since its already waked up
 	 	 	 	 7. consumer continue operation at step 2, to sleep
 	 	 	 	 8. producer won't send wakeup sinal again
 	 	 	     9. consumer sleep forever

 	 	 	 	 To solve the problem, add wakeup waiting bit:
 	 	 	 	 1. When a wakeup is sent to a process that is still awake,
 	 	 	 	 this bit is set;
 	 	 	 	 2. The consumer clears the wakeup waiting bit in every iteration
 	 	 	 	 of the loop.

 	 	 	 	 Or set 2 operations of checking and wakeup, checking and sleep
 	 	 	 	 as atomic, primitive operation

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define N 100

int count = 0;

void producer(void){
	int item;

	while(1){					// repeat forever
		item = produce_item();		// generate next item
		if(count == N){				// if buffer us full, go to s
			sleep();
		}
		insert_item(item);			// put item in buffer
		count++;					// increment count of items in buffer
		if(count == 1) {
			wakeup(consumer);		// was buffer empty
		}
	}
}

void consumer(void){
	int item;

	while(1){					// repeat forever
		if(count == 0){
			sleep();				// if buffer is empty, go to sleep
		}
		item = remove_item();		// take item from buffer
		count --;					// decrement count of items in buffer
		if(count == N -1) {			// was buffer full
			wakeup(producer);
		}
		consume_item(item);			// consume item
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
