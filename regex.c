#include<sys/mman.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<regex.h>
int main(void){
	int fd;
	fd=open("url.txt",O_RDONLY);
	int size=lseek(fd,0,SEEK_END);
	char* mmap_ptr=NULL;
	char* copy_ptr=NULL;
	mmap_ptr=mmap(NULL,size,PROT_READ,MAP_PRIVATE,fd,0);
	close(fd);
	copy_ptr=mmap_ptr;
	char* regstr="<a[^>]+href=\"([^\"]+)\"[^>]*>([^<]+)</a>";;
	int regnum=3;
	regmatch_t match[regnum];
	regex_t reg;
	regcomp(&reg,regstr,REG_EXTENDED);
	char addr[1024];
	char title[1024];
	while(mmap_ptr<copy_ptr+size){
		if((regexec(&reg,mmap_ptr,regnum,match,0))!=0){
			char* next=NULL;
			char* curr=mmap_ptr+1;
			while(curr<copy_ptr+size-1){
			if(curr[0]=='<'&&curr[1]=='a'){
				next=curr;
				break;
			}
			curr++;
			}
			if(next==NULL)
				break;
				mmap_ptr=next;
				continue;
		}
		bzero(title,sizeof(title));
		bzero(addr,sizeof(addr));
		snprintf(title,match[1].rm_eo-match[1].rm_so+1,"%s",mmap_ptr+match[1].rm_so);
		snprintf(addr,match[2].rm_eo-match[2].rm_so+1,"%s",mmap_ptr+match[2].rm_so);
mmap_ptr+=match[0].rm_eo;
printf("%s\t%s\n",title,addr);
	}
    regfree(&reg);
	munmap(copy_ptr,size);
	printf("done.\n");
	return 0;
}
