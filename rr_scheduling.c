#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct req{
    int id;
    int arrival;
    int burst;
    int remaining;
    int waiting;
    int tat;
    int completed;
};
int queue[MAX];
int front=-1,rear=-1;
void enqueue(int data){
    if(rear==MAX-1){
        return;
    }
    rear++;
    queue[rear]=data;
    if(front==-1){
        front=0;
    }
}
int dequeue(){
    if(front==-1 || front>rear){
        return -1;
    }
    front++;
    return queue[front++];
}
int isqueue(int data){
    for(int i=front;i<=rear;i++)
    {
        if(queue[i]=data){
            return 1;
        }
    }
    return 0;
}
int main(){
    int n;
    printf("Enter the numbr of processes:\n");
    scanf("%d",&n);
    struct req r[n];
    for(int i=0;i<n;i++){
        r[i].id=i;
        printf("Enter arrival time and burst time:\n");
        scanf("%d %d",&r[i].arrival,&r[i].burst);
        r[i].remaining=r[i].burst;
        r[i].tat=0;
        r[i].completed=0;
        r[i].waiting=0;
    }
    printf("Input Time Quantum\n");
    int t=0,c=0;
    scanf("%d",&t);
    while(c<n){
        int current=dequeue();
        if(current==-1){
            t++;
        }
        for(int i=0;i<n;i++){
            if(r[i].arrival<=t && r[i].remaining>0 && !isqueue(i)){
                enqueue(i);
            }
        }
        continue;
    }
    struct req* re=&r[current];
    if(req->remaining>t){
        req->remaining-=t;
        time+=t;
    } 
    return 0;
}