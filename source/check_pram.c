#include<copy.h>
int check_pram(int argc,const char* srcfile,int pronum){
	if(argc<3){
		printf("参数数量错误，至少需要源文件和目标文件\n");
		return -1;
	}
     if(access(srcfile, F_OK) != 0) {
		printf("源文件 %s 不存在\n", srcfile);
        return -1;
    }
	if (pronum < 1 || pronum >= 100) {																 printf("进程数量必须在 1 到 99 之间\n");													  return 0;
	}																								 return 0;	
}
