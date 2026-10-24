#include<copy.h>
int block_cur(const char* srcfile,int pronum){
	int fd=open(srcfile,O_RDONLY);
    if(fd==-1){
		perror("open");
		return -1;
	}
	int filesize=lseek(fd,0,SEEK_END);
	close(fd);
	if(filesize==0){
		printf("源文件为空\n");
		return -1;
	}
	int blocksize;
	if(filesize%pronum==0){
		blocksize=filesize/pronum;
	}
	else{
		blocksize=filesize/pronum+1;
	}
	return blocksize;
}
