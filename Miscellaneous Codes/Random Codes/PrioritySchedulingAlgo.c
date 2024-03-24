#include<stdio.h>
#include<limits.h>
struct PriorityScheduling{
    char processName;
    int burstTime;
    int priority;
    int arrivalTime;
    int done;
};

int main(){
    int processCount;
    int total = 0;
    struct PriorityScheduling temporaryProcess;
    int ASCII_number = 65;
    int position;
    float averageWaitingTime;
    float averageTurnAroundTime;
    printf("Enter the total number of processes: ");
    scanf("%d",&processCount);

    struct PriorityScheduling process[processCount];
    printf("\nEnter the Burst Time and Priority of each process: \n");
    for(int i=0;i<processCount;i++){
        process[i].processName = (char)ASCII_number;
        process[i].done = 0;
        printf("Burst Time: ");
        scanf("%d",&process[i].burstTime);
        printf("Arrival Time: ");
        scanf("%d",&process[i].arrivalTime);
        printf("Priority: ");
        scanf("%d",&process[i].priority);

        ASCII_number++;
    }

    //Array Declaration
    int ganttChart[processCount+1];
    char jobs[processCount+1];
    int storeIndex[processCount];
    int WaitingTime[processCount];
    int TurnaroundTime[processCount];
    int ResponseTime[processCount];

    //Sorting on the basis of Arrival Time
    for(int i=0;i<processCount;i++){
        position=i;
        for(int j=i+1;j<processCount;j++){
            if(process[j].arrivalTime<process[position].arrivalTime)
                position=j;
        }
        temporaryProcess=process[i];
        process[i]=process[position];
        process[position]=temporaryProcess;
    }
    printf("\nSorted the Processes on the basis of their Arrival Time:");
    printf("\n\nProcessName \t Burst Time \t Arrival Time \t Priority\n");
    printf("----------------------------------------------------------\n");

    for(int i=0;i<processCount;i++){
        printf("\t %c \t\t %d \t\t %d \t\t %d\n",process[i].processName,process[i].burstTime,process[i].arrivalTime,process[i].priority);
    }

    int current = process[0].burstTime,k=0,l;
    ganttChart[0] = process[0].arrivalTime;
    process[0].done=1;
    jobs[0]=process[0].processName;
    storeIndex[0]=0;
    for(int i=1;i<processCount+1;i++){
        ganttChart[i]=ganttChart[i-1]+current;
        k=0;
        int min = INT_MAX;
        while(k<processCount && k<ganttChart[i]){
            if(min>process[k].priority && process[k].done==0){
                min=process[k].priority;
                current = process[k].burstTime;
                l=k;
            }
            k++;
        }
        process[l].done=1;
        storeIndex[i]=l;
        jobs[i]=process[l].processName;
    }

    for(int i=1;i<processCount+1;i++){
        WaitingTime[i-1] = ganttChart[i-1] - process[storeIndex[i-1]].arrivalTime;
        TurnaroundTime[i-1] = ganttChart[i] - process[storeIndex[i-1]].arrivalTime;
    }

    printf("\nGantt Chart: |");
    for(int i=0;i<processCount+1;i++){
        printf("%d|",ganttChart[i]);
    }

    printf("\n\nProcessName \t Waiting Time \t TurnAround Time \n");
    printf("---------------------------------------------------\n");

    for(int i=0;i<processCount;i++){
        printf("\t %c \t\t %d \t\t %d\n",jobs[i],WaitingTime[i],TurnaroundTime[i]);
    }






    // for(int i=1;i<processCount;i++){
    //     process[i].waitingTime = 0;
    //     for(int j=0;j<i;j++){
    //         process[i].waitingTime += process[j].burstTime;
    //     }
    //     total += process[i].waitingTime;    
    // }
    // averageWaitingTime = (float)total/(float)processCount;
    // total=0;

    // printf("\n\nProcessName \t Burst Time \t Waiting Time \t TurnAround Time \n");
    // printf("-----------------------------------------------------------------\n");

    // for(int i=0;i<processCount;i++){
    //     process[i].turnaroundTime = process[i].burstTime + process[i].waitingTime;
    //     total+=process[i].turnaroundTime;
    //     printf("\t %c \t\t %d \t\t %d \t\t %d \t\t %d\n",process[i].processName,process[i].burstTime,process[i].arrivalTime,process[i].waitingTime,process[i].turnaroundTime);
    // }
    // printf("\n Average Waiting Time: %f", averageWaitingTime);
    // printf("\n Average Turnaround TIme: %f\n", averageTurnAroundTime);
}