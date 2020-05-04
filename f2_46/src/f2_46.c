/*
 ============================================================================
 Name        : f2_46.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Textbook Figure 2-46, P.169
 	 	 	 	 Processes scheduling problem
 	 	 	 	 A NON-solution to the dining philosophers problem

				(1) Problem description:
					Five philosophers are seated around a circular table. Each
					philosopher has a plate of spaghetti. The spaghetti is so
					slippery that a philosopher needs two forks to eat it.
					Between each pair of plates is one fork.
					The life of a philosopher consists of alternating periods
					of eating and thinking. When a philosopher gets sufficiently
					hungry, she tries to acquire her left and right forks,
					one at a time, in either order. If successful in acquiring
					two forks, she eats for a while, then puts down the forks,
					and continues to think.
				(2) Fatal problem of this solution:
					Suppose that all five philosophers take their left forks
					simultaneously. None will be able to take their right
					forks, and there will be a deadlock.
				(3) An easy modification is still failing
					(3.1) Modification:
					after taking the left fork, the program checks to see if
					the right fork is available. If it is not, the philosopher
					puts down the left one, waits for some time, and then
					repeats the whole process.
					(3.2) Why fails:
					 With a little bit of bad luck, all the philosophers could
					 start the algorithm simultaneously, picking up their left
					 forks, seeing that their right forks were not available,
					 putting down their left forks, waiting, picking up their
					 left forks again simultaneously, and so on, forever.
					(3.3) for (3.2) philosophers would just wait a random time
					instead of the same time after failing to acquire the
					right-hand fork, in practice this solution works fine.
					However, in a few applications one would prefer a solution
					that always works and cannot fail due to an unlikely series
					of random numbers.


 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define N 5						// number of philosophers
typedef int semaphore;			// semaphore is a special kind of int

semaphore forks[5];

void philosopher(int i){
	while(1){
		think();				// philosopher is thinking
		take_fork(i);			// philosopher is taking left fork
		take_fork((i+1)%N);		// philosopher is taking right fork
		eat();					// philosopher is eating
		put_fork(i);			// philosopher put left fork
		put_fork((i+1)%N);		// philosopher put right fork
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
