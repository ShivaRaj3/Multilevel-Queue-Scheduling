#include<stdio.h>
#include <stdlib.h>
struct process{
	int priority;
	int burst_time;
	int pid;
	int waiting_time;
	int turnaround_time;
	int remaining_time;
	int arrival_time;
};
void getInput();
void calcWaitingTime(struct process *q,int);
void calcTurnAroundTime(struct process *q,int);
void printQueue(struct process *q,int size);
void RoundRobin();
void PrioSorting();
void FCFS();
void printQueueI(struct process);
void printQueue(struct process *,int);

//Queues
//Q1 = Batch Process having Low Priority with FCFS Algorithm
//Q2 = Interactive Process having Medium Priority with Priority Based Sorting
//Q3 = System Process having High Priority with Round Robin Algorith Quantum Time=4
int q1_n=0,q2_n=0,q3_n=0,n=0; //N=Total Process
struct process *q1,*q2,*q3;
//Time Quantum
int time_quantum = 4;
void getInput(){
	printf("\n Total Number of Process:\t");
	scanf("%d",&n);
	//Allocatig Memory
	q1 = (struct process *)malloc(n*sizeof(struct process));
	q2 = (struct process *)malloc(n*sizeof(struct process));
	q3 = (struct process *)malloc(n*sizeof(struct process));
	for(int i=0;i<n;i++){
		struct process p;
		printf("\n\t\tProcess %d\n=============================================\n\n",i+1);
		p.arrival_time = (rand())%(n+1);				
		printf("PId:\t");
		scanf("%d",&p.pid);
		printf("Priority (1-9):\t");
		scanf("%d",&p.priority);
		printf("\nBurst Time: %d\t",p.burst_time);
		scanf("%d",&p.burst_time);
		p.remaining_time = p.burst_time;
		if(p.priority>0 && p.priority<=3){
			q1[q1_n++]  = p;
		}else if(p.priority>3 && p.priority<=6){
			q2[q2_n++] = p;
		}else{
			q3[q3_n++] = p;
		}		
	}
}
void printQueue(struct process *q,int size){	
	calcWaitingTime(q,size);
	calcTurnAroundTime(q,size);
	printf("\nPId\t\tPriority\t\tBurst Time\t\tWaiting Time\t\tTurnAround Time\t\tArrival");
	printf("\n================================================================================\n");
	for(int i=0;i<size;i++){
		printQueueI(q[i]);
	}
	printf("\n\n");
}
void printQueueI(struct process p){
	printf("\n%d\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t%d",p.pid,p.priority,p.burst_time,p.waiting_time,p.turnaround_time,p.arrival_time);
}
void calcWaitingTime(struct process *q,int size){
	q[0].waiting_time = 0;
	for(int i=1;i<size;i++){
		q[i].waiting_time = q[i-1].waiting_time + q[i-1].burst_time;
	}
}
void calcTurnAroundTime(struct process *q,int size){
	q[0].waiting_time = 0;
	for(int i=0;i<size;i++){
		q[i].turnaround_time = q[i].waiting_time + q[i].burst_time;
	}
}