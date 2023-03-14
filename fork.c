#include<stdio.h>
#include<unistd.h>
void main(){
	int p=getpid();
	printf("Fork : %d\n",p);
	p=fork();
	
return;
}

