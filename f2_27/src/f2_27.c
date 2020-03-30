/*
 ============================================================================
 Name        : f2_27.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : textbook P.129 figure 2.27
 	 	 	 	 The producer-consumer problem with a fatal race condition
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
