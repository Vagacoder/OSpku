/*
 ============================================================================
 Name        : thread.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Check the address space of threads
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	int value = atoi(argv[1]);
	while(1){
		printf("value is %d, loc 0x%lx\n", value, (long)&value);
	}


	return EXIT_SUCCESS;
}
