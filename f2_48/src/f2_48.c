/*
 ============================================================================
 Name        : f2_48.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Textbook P. 171 Figure 2-48
 	 	 	 	 A solution to reader and writer problem

 	 	 	 	 Reader and Writer Problem Description:
 	 	 	 	 (1) If a reader need access:
 	 	 	 	   (1.1) No other => this reader is allowed
 	 	 	 	   (1.2) other readers reading, writer WAITING => this reader is allowed
 	 	 	 	   (1.3) writer WRITING, other readers waiting => this reader is NOT allowed
 	 	 	 	 (2) If a writer need access:
 	 	 	 	   (2.1) No other => this writer is allowed
 	 	 	 	   (2.2) any reader reading => this writer is NOT allowed
 	 	 	 	   (2.3) any writer writing => this writer is NOT allowed

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
typedef int semaphore;
semaphore mutex = 1;			// access to rc, it is also a CR
semaphore db = 1;				// access to database, it is a critical region
int rc = 0;						// number of reader candidate(s), it is also a critical region

void reader(void){				// ! ONE or MORE readers can access to CR at the same time
	while(1){
		P(&mutex);				// rc is CR, so access to is need protection by semaphore

		rc++;					// increase number of readers currently accessing to database
		if(rc ==1){				// if this is the first reader
			P(&db);				// all readers can access database (CR)
		}

		V(&mutex);

		read_op();

		P(&mutex);

		rc--;					// decrease number of readers currently accessing to databse
		if(rc == 0){			// if this is the last reader
			V(&db);				// allow other process to access databse (CR)
		}

		V(&mutex);
	}
}

void writer(void){				// ! ONLY ONE writer can access to CR at any time
	while(1){
		P(&db);
		write_op();
		v(&db);
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

void read_op(){}

void write_op(){}

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
