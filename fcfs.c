//Sheduling algorithm_fcfs
#include<stdio.h>
void main(){
	int i,n;
	printf("Enter number of processes : ");
	scanf("%d",&n);
	float T[n],G[n+1],wt=0,tat=0;
	for(i=0;i<n;i++){
		printf("\nEnter the CPU burst time of P%d :",i);
		scanf("%f",&T[i]);	
	}
	G[0]=0;
	printf("\n___________________\nProcess  wt\ttat\n");
	for(i=1;i<=n;i++){
		G[i]=G[i-1]+T[i-1];
		printf(" %d\t%3.1f\t%3.1f \n",i-1,G[i-1],G[i]);
		if(i!=n){
			wt=wt+G[i];
		}
		tat=tat+G[i];
	}
 	printf("-------------------\nRESULTS :\nTotal Waiting Time : %3.2f \n",wt);
	printf("Average Waiting Time : %3.2f \n",wt/n);
 	printf("Total Turn Arouund Time : %3.2f \n",tat);
 	printf("Average Turn Around Time : %3.2f \n",tat/n);
return;
}
