void* multipl(void* arg,struct matr,int* array)
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
		int i, j;
	
    struct matr* readfile(struct matr)
	{
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
	}

	struct matr* pthr(char** argv){
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
	}

	int* calculate(struct matr*)
	{
	//CALCULATING OF THREADS
		matrix[0].numb = numb; 

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
	}

	
}
