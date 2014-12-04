#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h> 
#include "mlib.h" 


int main(int argc, char** argv)
{   int i,k = 0;
	int numb = atoi(argv[1]);
	int* array = (int*)calloc(2 * numb * numb, sizeof(int));
	
	
	numb = atoi(argv[1]); // from char to int 

	array = (int*)calloc(2 * numb * numb, sizeof(int));
	int* inbuf(int numb, char** argv);

	if(argc != 2)
		perror("wrong number of arguments\n");

    outbuf(array , argv);
	return 0;
}
