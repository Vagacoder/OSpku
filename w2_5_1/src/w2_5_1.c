/*
 ============================================================================
 Name        : w2_5_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : System call write is wrapped in C library to a same name function
  	  	  	  	  The compiled assembly result (for presentation, may not exactly
  	  	  	  	  same) would be:
  	  	  	  	  ```
  	  	  	  	  .section .data
  	  	  	  	  output:
  	  	  	  	  	  .ascii "Hello!\n"
				  output_end:
				  	  .equ len, output_end - output

				  .section .text
				  .globl _start
				  _start:
				  	  movl $4, %eax		# save system call # (4 for write) to register eax
				  	  movl $1, %ebx		# save arguments to other registers
				  	  movl $output, %exc
				  	  movl $len, %edx
				  	  int $0x80			# call system call
  	  	  	  	  end:
  	  	  	  	  	  movl $1, %eax		# system call # (1 for return) to register eax
  	  	  	  	  	  movl $0, %ebx
  	  	  	  	  	  int $0x80

  	  	  	  	  ```
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	char string[7]= {'H', 'e', 'l', 'l', 'o', '!', '\n'};
	write(1, string, 7);

	return EXIT_SUCCESS;
}
