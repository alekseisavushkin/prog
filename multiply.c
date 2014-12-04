#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/time.h>

struct matr{
	int numb;
	int str;
	int* val;
};

int main(int argc, char** argv)
{
	struct timeval* mytime = (struct timeval*)calloc(2, sizeof(struct timeval));
	gettimeofday(mytime, NULL);
	if(argc != 2)
	{
		printf("wrong nubmer of arguments\n");
		return -1;
	}
	int i, j;
	
    
	struct matr* readfile(struct matr);

	struct matr* pthr(char** argv); 
	
	int* calculate(struct matr*);

	
	gettimeofday(mytime + 1, NULL);
	printf("%ld - start\n %ld - stop\n", mytime[0].tv_sec * 1000000 + mytime[0].tv_usec, mytime[1].tv_sec * 1000000 + mytime[1].tv_usec);
	printf("working time = %ld\n", mytime[1].tv_usec - mytime[0].tv_usec + 1000000 * (mytime[1].tv_sec - mytime[0].tv_sec));
	return 0;
}
