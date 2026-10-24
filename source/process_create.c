#include<copy.h>
int process_create(const char* srcfile,const char* destfile,int pronum,int blocksize){
	pid_t pid;
	for(int i=0;i<pronum;i++){
		pid=fork();
		if(pid==-1){
			perror("fork");
			return -1;
		}
		else if(pid==0){
			int offset=i*blocksize;
			char str_offset[16];
			char str_blocksize[16];
			sprintf(str_offset,"%d",offset);
			sprintf(str_blocksize,"%d",blocksize);
			execl("/home/colin/20251018_5/process_copy/COPY","COPY",srcfile,destfile,str_offset,str_blocksize,NULL);
			perror("execl error");
			exit(1);
		}
	}
	return 0;
}

