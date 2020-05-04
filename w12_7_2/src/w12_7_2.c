/*
 ============================================================================
 Name        : w12_7_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : A solution for dining philosopher problem (f2_46, f2_47):
 	 	 	 	 Using monitor for allocation of forks
 	 	 	 	 Note: original code is written in C++, here is only for
 	 	 	 	 demonstration.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define N 5						// number of philosophers
typedef int semaphore;			// semaphore is a special kind of int
typedef int cond;				// conditional variable

semaphore forks[5];

void philosopher(int i){
	while(1){
		think();
		get_forks(i);
		eat();
		release_forks(i);
	}

}

// monitor dining_controller;
cond ForkReady[5];
int fork[5] = {1};
void get_forks(int pid){
	int left = pid;
	int right = (++pid) % N;
	if(!fork(left)){
		cwait(ForkReady[left]);		// queue on conditional variable
	}
	forks[left] = 0;
	if(!fork(right)){
		cwait(ForkReady[right]);	// queue on conditional variable
	}
	forks[right] = 0;
}

void release_forks(int pid){
	int left = pid;
	int right = (++pid) % N;
	// release left fork
	if(empty(ForkReady[left])){
		forks[left] = 1;			// none is waiting for left fork
	}else{
		csignal(ForkReady[left]);	// awaken a process waiting for left fork
	}
	// release right fork
	if(empty(ForkReady[right])){
		forks[right] = 1;			// none is waiting for right fork
	}else{
		csignal(ForkReady[right]);	// awaken a process waiting for right fork
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
