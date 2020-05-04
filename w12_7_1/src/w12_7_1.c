/*
 ============================================================================
 Name        : w12_7_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : A solution for dining philosopher problem (f2_46, f2_47):
 	 	 	 	 Allow maximum 4 philosophers on table at the same time.
				 Proof: pigeon hole rules, 5 forks for 4 philosophers,
				 at least one philosopher can get 2 forks.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define N 5						// number of philosophers
typedef int semaphore;			// semaphore is a special kind of int

semaphore forks[5];
semaphore room = {4};			// new semaphore for room

void philosopher(int i){
	while(1){
		think();
		P(room);				// maximum allow 4 philosopher;
		take_fork(i);
		take_fork((i+1) % N);
		eat();
		put_fork((i+1) % N);
		take_fork(i);
		V(room);
	}
}

// thinking
void think(){}

// taking fork
void take_fork(int i){
	P(forks[i]);
}

// put fork
void put_fork(int i){
	V(forks[i]);
}

// eating
void eat(){}

// standard PV operation for semaphore
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

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
