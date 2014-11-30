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

void* multipl(void* arg)
{
	struct matr* matrix = (struct matr*)arg;
	int* array = (int*)calloc(matrix->numb, sizeof(int));
	int i, j;
	for(i = 0; i < matrix->numb; i++)
	{
		array[i] = 0;
		for(j = 0; j < matrix->numb; j++)
		{
			array[i] += matrix->val[matrix->numb * matrix->str + j] * matrix->val[matrix->numb * matrix->numb + matrix->numb * j + i];
		}
	}
	return (void*)array;
}



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
	

	//READING
	int fd = open("file.txt", O_RDONLY);
	if(fd < 0)
		perror("cant open file\n");
	int numb = 0;
	if(read(fd, &numb, sizeof(int)) != sizeof(int))
		perror("cant't read number");
	struct matr* matrix = (struct matr*)calloc(numb, sizeof(struct matr));
	for(i = 0; i < numb; i++)
	{
		matrix[i].val = (int*)calloc(2 * numb * numb, sizeof(int));
	}
	int* answer = (int*)calloc(numb * numb, sizeof(int));
        printf("number = %d\n", numb);

	int len = read(fd, matrix[0].val, 2 * numb * numb * sizeof(int));

	if(len != 2 * numb * numb * sizeof(int))
		printf("wrong number %d\n", len);

	for(j = 1; j < numb; j++)
	{
		matrix[j].numb = numb;
		for(i = 0; i < 2 * numb * numb; i++)
		{
			matrix[j].val[i] = matrix[0].val[i];
		}
	}

	matrix[0].numb = numb; 

	//USING ALL THREADS
	int m = atoi(argv[1]);
	if(m > numb)
		m = numb;
	pthread_t* thread = (pthread_t*)calloc(m, sizeof(pthread_t));
	for(i = 0; i < m; i++)
	{
		matrix[i].str = i;
		struct matr* send = matrix + i;
		pthread_create(thread + i, NULL, multipl, (void*)send); 
	}


	//CALCULATING OF THREADS
	for(; i < numb; i++)
	{
		int* mass = (int*)calloc(numb, sizeof(int));
		matrix[i].str = i;
		struct matr* send = matrix + i;
		mass = (int*)multipl((void*)send);
		for(j = 0; j < numb; j++)
		{
			answer[numb * i + j] = mass[j];
		}
	}
	

	void ** format = calloc (numb, sizeof(void*) );

	for(i = 0; i < m; i++)
	{   

		pthread_join(thread[i], format); 
		void* format1 = format[0];
		int* format2 = (int*)format1;
		for(j = 0; j < numb; j++)
		{
			answer[numb * i + j] = format2[j];
		}
	}

	int res = fork();
	// AP: ни в коем случае не записывайте printf - пользуйтесь своей библиотекой
	if(res)
	{
		close(1);
		int fd = open("resfile.txt", O_WRONLY | O_CREAT, 00777);
		int count = 1;
		for(i = 0; i < numb * numb; i++)
		{
			printf("%d ", answer[i]);
			if(i == numb * count - 1)
			{
				count++;
				printf("\n");
			}
		}
		close(fd);
		return 0;
	} 

	gettimeofday(mytime + 1, NULL);
	printf("%ld - start\n %ld - stop\n", mytime[0].tv_sec * 1000000 + mytime[0].tv_usec, mytime[1].tv_sec * 1000000 + mytime[1].tv_usec);
	printf("working time = %ld\n", mytime[1].tv_usec - mytime[0].tv_usec + 1000000 * (mytime[1].tv_sec - mytime[0].tv_sec));
	return 0;
}
