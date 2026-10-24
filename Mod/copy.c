#include<copy.h>
int main(int argc,char** argv){
	if(argc<5){
		printf("COPY参数不足\n");
		return -1;
	}
	const char* srcfile=argv[1];
	const char*destfile=argv[2];
	int offset=atoi(argv[3]);
	int blocksize=atoi(argv[4]);
	printf("Child PID: %d,offset: %d,blocksize: %d\n",getpid(),offset,blocksize);
	int srcfd=open(srcfile,O_RDONLY);
	int destfd=open(destfile,O_WRONLY|O_CREAT,0664);
	if(srcfd==-1||destfd==-1){
		perror("open");
		return -1;
		}
		lseek(srcfd,offset,SEEK_SET);
		lseek(destfd,offset,SEEK_SET);
		char* buffer=(char*)malloc(blocksize);
		memset(buffer,0,blocksize);
		int len=read(srcfd,buffer,blocksize);
		if(len>0){
			write(destfd,buffer,len);
		}
		free(buffer);
		close(srcfd);
		close(destfd);
		return 0;
}
