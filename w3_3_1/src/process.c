/*
 ============================================================================
 Name        : process.c
 Author      : Vagacoder
 Version     :
 Copyright   : Your copyright notice
 Description : Online course example: Study Unix/Linux System Call fork(),
 	 	 	 	 which creates a new process from parent process,
 	 	 	 	 in parent process, the return value is pid of child process;
 	 	 	 	 in child process, the return value is 0.

 	 	 	 	 Parent waits for child complete;
 ============================================================================
 */

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */

	pid_t pid;
	pid = fork();
	if(pid == 0){
		printf("parent is waiting for child...\n");
		wait(NULL);
		printf("child complete!");
	} else if (pid > 0){
		printf("child is working!\n");
		execlp("bin/ls", "ls", NULL);
		printf("child is done!\n");
		exit(0);
	} else{
		printf("fork error!\n");
	}

	return EXIT_SUCCESS;
}
