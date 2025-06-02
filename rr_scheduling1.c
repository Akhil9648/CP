#include<stdio.h>
#define MAX 10 
struct tasks{
int id;
int arrivalTime;
int burstTime;
int timeLeft;
int waitTime;
int turnTime;
int isDone;
};
int readyQueue[MAX];
int head=-1,tail=-1;
void pushToQueue(int taskId){
if(tail==MAX-1) return;
readyQueue[++tail]=taskId;
if(head==-1)head=0;
}
int popFromQueue(){
if(head==-1||head>tail)return -1;
return readyQueue[head++];
}
int isInQueue(int taskId){
for(int i=head;i<=tail;i++){
if(readyQueue[i]==taskId)return 1;
}
return 0;
}
int main(){
int n,t;
printf("Enter number of tasks: ");
scanf("%d",&n);
struct tasks tasks[n];
for(int i=0;i<n;i++){
tasks[i].id=i;
printf("Enter Arrival and Burst Time for Task %d: ",i+1);
scanf("%d%d",&tasks[i].arrivalTime,&tasks[i].burstTime);
tasks[i].timeLeft=tasks[i].burstTime;
tasks[i].waitTime=0;
tasks[i].turnTime=0;
tasks[i].isDone=0;
}
printf("Enter Time Quantum: ");
scanf("%d",&t);
int clock=0,doneCount=0;
pushToQueue(0);
while(doneCount<n){
int currentId=popFromQueue();
if(currentId==-1){
clock++;
for(int i=0;i<n;i++){
if(tasks[i].arrivalTime<=clock && tasks[i].timeLeft>0 && !isInQueue(i)){
pushToQueue(i);
}
}
continue;
}
struct tasks *current = &tasks[currentId];
if(current->timeLeft > t){
current->timeLeft -= t;
clock += t;
}else{
clock += current->timeLeft;
current->timeLeft = 0;
current->isDone = 1;
current->turnTime = clock + t - current->arrivalTime; 
current->waitTime = current->turnTime - current->burstTime;
doneCount++;
}
for(int i=0;i<n;i++){
if(tasks[i].arrivalTime <= clock && tasks[i].timeLeft > 0 && !isInQueue(i)){
pushToQueue(i);
}
}
if(!current->isDone){
pushToQueue(currentId);
}
}
printf("\nTask\tArrival\tBurst\tWait\tTurnaround\n");
for(int i=0;i<n;i++){
printf("T%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,tasks[i].arrivalTime,tasks[i].burstTime,tasks[i].waitTime,tasks[i].turnTime);
}
return 0;
}