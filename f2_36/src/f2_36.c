/*
 ============================================================================
 Name        : f2_36.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Textbook Figre 2-36 P.146
 	 	 	 	 The producer-consumer problem with N messages
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define N 100							// number of slots in buffer

typedef char message[];					// message buffer

void producer(void){
	int item;
	message m;							// initial message

	while(1){
		item = produce_item();			// generate item
		receive(consumer, &m);			// wait for an empty to arraive
		build_message(&m, item);		// construct a message to send
		send(consumer, &m);				// send message (built with item) to consumer
	}
}

void consumer(void){
	int item, i;
	message m;

	for(i=0; i<N; i++){
		send(producer, &m);				// send N empties
	}
	while(1){
		receive(producer, &m);			// get message containing item
		item = extract_item(&m);		// extract item from message
		send(producer, &m);				// send back empty reply
		consume_item(item);				// do something with item
	}
}


int produce_item(){
	return 1;
}


void consume_item( int a){

}

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
