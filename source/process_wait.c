#include<copy.h>
int process_wait(){
	pid_t zpid;
	while((zpid=wait(NULL))>0){
		printf("Parent: Reaped child process %d\n",zpid);
	}
	return 0;
}
