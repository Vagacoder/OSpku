/*
 ============================================================================
 Name        : f2_47.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Textbook Figure 2-47, P.170
 	 	 	 	 A solution to the dining philosopher problem

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define N		5						// number of philosophers
#define LEFT	(i+N-1)%N				// number of i's left neighbor
#define RIGHT	(i+1)%N					// number of i's right neighbor
#define THINKING	0					// philosopher is thinking
#define HUNGRY	1						// philosopher is trying to get forks
#define EATING	2						// philosopher is eating

typedef int semaphore;					// semaphore is a special kind of int
int state[N];							// array to keep track of everyone's state
semaphore mutex = 1;					// mutual exclusion for critical region
semaphore s[N];							// one semaphore per philosopher

// Each process runs this procedure separately
void philosopher(int i){				// i: philosopher number, from 0 to N-1
	while(1){
		think();						// thinking
		take_forks(i);					// acquire two forks or block
		eat();
		put_forks(i);					// put both fork on table
	}
}

void take_forks(int i){				// i: philosopher number, from 0 to N-1
	P(&mutex);						// enter CR
	state[i] = HUNGRY;				// record the this philosopher is hungry
	test(i);						// try to acquire 2 forks
	V(&mutex);						// exit CR
	P(&s[i]);						// block if forks were not acquired
}

void put_forks(int i){				// i: philosopher number, from 0 to N-1
	P(&mutex);						// enter CR
	state[i] = THINKING;			// philosopher has finished eating
	test(LEFT);						// see if left neighbor can now eat
	test(RIGHT);					// see if right neighbor can now eat
	V(&mutex);						// exit CR
}

void eat(){}

void test(int i){
	if(state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING){
		state[i]=EATING;
		V(&s[i]);
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

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
