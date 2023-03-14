//Sheduling algorithm_SJF
#include<stdio.h>
void main(){
	int i,n;
	printf("Enter number of processes : ");
	scanf("%d",&n);
	
	float G[n+1],wt=0,tat=0;
	struct process{
		int name;
		float burst;
	}T[n],temp;
	
	for(i=0;i<n;i++){
		printf("\nEnter the CPU burst time of P%d :",i);
		T[i].name=i;
		scanf("%f",&T[i].burst);
		int j=i;
		while(j>0 && T[j].burst < T[j-1].burst){
			temp=T[j];
			T[j]=T[j-1];
			T[j-1]=temp;
			j--;
		}
	}
	G[0]=0;
	printf("\n_____________________________\nProcess  burst   wt\ttat\n_____________________________\n");
	for(i=1;i<=n;i++){
		G[i]=G[i-1]+T[i-1].burst;
		printf(" P%d \t%3.1f\t %3.1f \t %3.1f \n",T[i-1].name,T[i-1].burst,G[i-1],G[i]);
		if(i!=n){
			wt=wt+G[i];
		}
		tat=tat+G[i];
	}
 	printf("----------------------------\nRESULTS :\nTotal Waiting Time : %3.2f s \n",wt);
	printf("Average Waiting Time : %3.2f s\n",wt/n);
 	printf("Total Turn Arouund Time : %3.2f s\n",tat);
 	printf("Average Turn Around Time : %3.2f s\n",tat/n);
return;
}
