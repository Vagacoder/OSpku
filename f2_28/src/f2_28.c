/*
 ============================================================================
 Name        : f2_28.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : textbook P. 131 Figure 2-28
 	 	 	 	 The producer-consumer problem using semaphore
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

P(semaphore s){
	s--;
	if(s < 0){
		// blocking, move this process to waiting queue; reschedule
	}
}

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