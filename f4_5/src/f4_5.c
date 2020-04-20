/*
 ============================================================================
 Name        : f4_5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Textbook P.274, Figure 4-5
 	 	 	 	 A simple program to copy a file.

 	 	 	 	 	 usage: copyfile abc xyz

 	 	 	 	 Copy the file abc to xyz. If xyz already exists, it will be
 	 	 	 	 overwritten. Otherwise, it will be created. The program must
 	 	 	 	 be called with exactly two arguments, both legal file names.
 	 	 	 	 The first is the source; the second is the output file.

 ============================================================================
 */

#include<sys/types.h>
#include<fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>

int main(int argc, char* argv[]);			// ANSI prototype

#define BUF_SIZE 4096						// set buffer size
#define OUTPUT_MODE 0700					// protection bits for output file

int main(int argc, char* argv[]) {

	int in_fd, out_fd, rd_count, wt_count;
	char buffer[BUF_SIZE];

	if(argc !=3){							// check parameter number
		exit(1);
	}

	// Open the input file and create the output file
	in_fd = open(argv[1], O_RDONLY);				// open source file
	if(in_fd < 0){									// if cannot open, exit
		exit(2);
	}
	out_fd = create(argv[2], OUTPUT_MODE);			// create new file
	if(out_fd < 0){									// if cannot create, exit
		exit(3);
	}

	// Copy loop
	while(1){
		rd_count = read(in_fd, buffer, BUF_SIZE);	// read a block of data
		if(rd_count <= 0){							// if end of file or error, exit loop
			break;
		}
		wt_count = write(out_fd, buffer, rd_count);	// write data
		if(wt_count <= 0){							// wt_count <= is an error, exit
			exit(4);
		}
	}

	// Close the files
	close(in_fd);
	close(out_fd);
	if(rd_count == 0){					// no error on last read
		exit(0);
	}else{								// error on last read
		exit(5);
	}



	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
