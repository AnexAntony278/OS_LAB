//RoundRobin
#include<stdio.h>
#define ts 4
#define MAX 30

struct process{
	int id;	
	float burst,wt,tat,rt;
}Q[MAX],G[MAX],current;
		
void main(){
	int i,j,k,rear=-1,front=-1,n;
	float t;
	printf("Enter Number of Processes : ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		current.id=i;
		printf("\nEnter burst time of Process %d : ",i);
		scanf("%f",&current.burst);
		current.rt=current.burst;
		Q[++rear]=current;
	}front=0;
	printf("\nGANTT CHART : \n 0   ");
	while(front<=rear){
		current=Q[front++];
		if(current.rt==current.burst){
			current.wt=t;
			}
		if(current.rt>ts){
			current.rt-=ts;
			t=t+ts;
			Q[++rear]=current;
		}
		else{
			t=t+current.rt;
			current.rt=0;
			current.tat=t;
			G[k++]=current;
		}
		printf("[P%d]  %3.1f  ",current.id,t);
	}
	for(i=0;i<=n;i++){
		printf("\n[P%d]  %3.1f %3.1f %3.1f ",G[i].id,G[i].burst,G[i].wt,G[i].tat);
		}
return;
}
