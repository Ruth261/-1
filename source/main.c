#include"copy.h"
int main(int argc, char** argv){
	 if(argc < 3){
		printf("Usage: %s <srcfile> <destfile> [pronum]\n", argv[0]);
		return -1;
     }
    const char *srcfile = argv[1];
    const char *destfile = argv[2];
    int pronum;
    if(argc == 3){
	   pronum = 1;
	 } 																			else{
		 pronum = atoi(argv[3]);													}												
	if(check_pram(argc, srcfile, pronum) == -1){									 return -1;																}
	int blocksize = block_cur(srcfile, pronum);									if(blocksize == -1){														   return -1;
	}																		    if(process_create(srcfile, destfile, pronum, blocksize) == -1){				   return -1;
	}																		    process_wait();																																		    return 0;
}
