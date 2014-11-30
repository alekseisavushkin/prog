#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int main(int argc, char** argv)
{
	if(argc != 2)
		perror("wrong number of arguments\n");
	//write random numbers in massive
	int numb = atoi(argv[1]); // from char to int 
	int* array = (int*)calloc(2 * numb * numb, sizeof(int)); // memory
	int i = 0;
	int k = 0;
	for(i = 0; i < 2 * numb; i++)//writing 2n^2 numbers
	{
		for(k = 0; k < numb; k++)
		{
			array[i * numb + k] = rand();
		}
	}
	
	
	//writing in file
	int wr = 0;
	
	int fd = open("file.txt", O_WRONLY | O_CREAT, 0777); //create and open file
	if(fd < 0)
		perror("mistake in opening file\n");
	
	// AP: нужно воспользоваться своей библиотекой буферизованной записи и чтения - и везде пользоваться ей
	if(write(fd, &numb, sizeof(int)) != sizeof(int)) //write a first number
		perror("can't write number\n");
	
	
	if((wr = write(fd, array, 2 * numb * numb * sizeof(int))) != 2 * numb * numb * sizeof(int)) //write massive
		printf("was written only %d\n", wr);
	if(close(fd) < 0)
		perror("can't close file\n");
		
	free(array); //free massive
	return 0;
}
