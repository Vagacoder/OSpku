/*
 ============================================================================
 Name        : f2_24.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Book figure 2.24 (P.125) Peterson's solution for achieving
 	 	 	 	 mutual exclusion.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define FALSE	0
#define TRUE	1
#define N	2				// number of processes

int turn;					// whose turn to run on cpu
int interested[N];			// process state list, all values initially 0 (FALSE)

void enter_region(int process){		// process is 0 or 1
	int other = 1 - process;		// the opposite of process
	interested[process] = TRUE;		// show current process is interested
	turn = process;					// set flag for current process to access critical region
	while(turn == process && interested[other] == TRUE){}	// null statement
}

void leave_region(int process){		// process is leaving
	interested[process] = FALSE;	// show current process is not interested
}


int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
