/*
 ============================================================================
 Name        : f2_23.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : textbook P. 124 figure 2-23
 	 	 	 	 A proposed solution for critical-region problem.
 	 	 	 	 !Wrong solution!, since same process cannot continuously
 	 	 	 	 access to CR. Processes must access to CR in turn!
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int turn = 0;					// two process, 0 for one, 1 for another;

void access_CR(int processId){
	while(1){
		while(turn != processId){}	// busy waiting (aka spin lock)
		cr_op();
		turn = 1 - processId;	// switch to the other process,
		noncr_op();
	}
}

void cr_op(){}					// critical region operations

void noncr_op(){}					// non-critical region operations

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
