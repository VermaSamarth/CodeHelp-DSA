#include<stdio.h>
#include<conio.h>
#include<limits.h>

struct ShortestJobFirst{
    char processName;
    int burstTime;
    int arrivalTime;
    int waitingTime;
    int turnaroundTime;
    int done;
};

int main(){
    int processCount;
    int total;
    struct ShortestJobFirst temporaryProcess;
    int ASCII_number=65;
    int position;
    float averageWaitingTime;
    float averageTurnAroundTime;

    printf("Enter the number of process: ");
    scanf("%d",&processCount);
    struct ShortestJobFirst process[processCount];

    printf("Enter the burst time and arrival time of each process: \n");
    for(int i=0;i<processCount;i++){
        process[i].processName = (char)ASCII_number;
        process[i].done = 0;
        printf("Burst Time: ");
        scanf("%d",&process[i].burstTime);
        printf("Arrival Time: ");
        scanf("%d",&process[i].arrivalTime);
        ASCII_number++;
    }

    for(int i=0;i<processCount;i++){
        int position=i;
        for(int j=i+1;j<processCount;j++){
            if(process[j].arrivalTime<process[position].arrivalTime)
                position=j;
        }
        temporaryProcess=process[i];
        process[i]=process[position];
        process[position]=temporaryProcess;
    }
    

    process[0].waitingTime = process[0].arrivalTime;
    int current=process[0].arrivalTime,min=process[0].burstTime,k,l=0;
    process[0].done = 1;
    printf("\n\nProcessName \t Burst Time \t Arrival Time \t Waiting Time \t TurnAround Time \n");
    printf("---------------------------------------------------------------------------------\n");
    for(int i=0;i<processCount;i++){
        process[l].waitingTime = current;
        current = process[l].waitingTime+min;
        process[l].turnaroundTime = current - process[l].arrivalTime;
        printf("\t %c \t\t %d \t\t %d \t\t %d \t\t %d\n",process[l].processName,process[l].burstTime,process[l].arrivalTime,(process[l].waitingTime-process[l].arrivalTime),process[l].turnaroundTime);
        total += process[l].waitingTime;    
        min = INT_MAX;
        k=0;
        while(k<current && k<processCount){
            if(process[k].burstTime<min && process[k].done!=1){
                min = process[k].burstTime;
                l=k;
            }
            k++;
        }
        process[l].done=1;
    }
    for(int i=0;i<processCount;i++){
        
    }
}