int* inbuf(int numb,char** argv){ 
	
	//FILLING
	numb = atoi(argv[1]);
	int* array=0;
	int i = 0;
	int k = 0;
	for(i = 0; i < 2 * numb; i++)
	{
		for(k = 0; k < numb; k++)
		{
			array[i * numb + k] = rand();
			printf("%d",array[i * numb + k]);
		}
	}	return  array;
}
	
	void outbuf(int* array, char** argv){
	
		
		int wr = 0;
		int numb = atoi(argv[1]);
		int i,k = 0;
		int fd = open("file.txt", O_WRONLY | O_CREAT, 0777);

		numb = atoi(argv[1]);
		if(fd < 0)
		perror("mistake in opening file\n");
		
		if(write(fd,  &numb, sizeof(int)) != sizeof(int))
			perror("can't write number\n");
	
		if((wr = write(fd, array, 2 * numb * numb * sizeof(int))) != 2 * numb * numb * sizeof(int))
		    printf("was written only %d\n", wr);
		/*int res = fork();
		if(res)
		{
			close(1);
			int fd = open("file.txt", O_WRONLY | O_CREAT, 0777);
			printf("%d", numb);
			for(i = 0; i < 2 * numb; i++)
			{
				for(k = 0; k < numb; k++)
				{
					array[i * numb + k] = rand();
					printf("%d",array[i * numb + k]);
				}
			}	
			close(fd);
		}*/
		
		
		free(array);

		
	}
