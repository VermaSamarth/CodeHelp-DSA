#include<stdio.h>
int main(){
        int jobs;
        float avgTat=0.0,avgRt=0.0,avgWt=0.0;
        printf("Enter the number of jobs: ");
        scanf("%d",&jobs);

        int BurstTime[jobs];
        int ArrivalTime[jobs];
        int TurnAroundTime[jobs];
        int WaitingTime[jobs];
        int ResponseTime[jobs];
        int GanttChart[jobs+1];

        for(int i=0;i<jobs;i++)
        {
                printf("Enter the process Details of the Process: %d\n",i+1);
                printf("Burst time: ");
                scanf("%d",&BurstTime[i]);
                printf("Arrival time: ");
                scanf("%d",&ArrivalTime[i]);
        }

        for(int i=0; i<jobs-1; i++){
                for(int j=0; j<jobs-1-i; j++){
                        if(ArrivalTime[j]>ArrivalTime[j+1]){
                                int temp = ArrivalTime[j];
                                ArrivalTime[j] = ArrivalTime[j+1];
                                ArrivalTime[j+1] = temp;

                                int tempBurst = BurstTime[j];
                                BurstTime[j] = BurstTime[j+1];
                                BurstTime[j+1] = tempBurst;
                        }
                }
        }
        for(int i=0;i<jobs;i++){
            printf("%d\n",BurstTime[i]);
        }
         //Construction of the Gantt Chart and filling the values in it.
        GanttChart[0]=ArrivalTime[0];
        for(int i=0;i<jobs;i++){
                GanttChart[i+1]=GanttChart[i]+BurstTime[i];
        }

        //Calculating the Turn Around time.
        for(int i=0;i<jobs;i++){
                TurnAroundTime[i]=GanttChart[i+1]-ArrivalTime[i];
        }

        //Calculating the Waiting Time.
        for(int i=0;i<jobs;i++){
                WaitingTime[i]=GanttChart[i]-ArrivalTime[i];
        }

        //Calculating the Response time.
        for(int i=0;i<jobs;i++){
                ResponseTime[i]=GanttChart[i]-ArrivalTime[i];
        }

        //Printing the Calculated values.
        for(int i=0;i<jobs;i++){
                printf("Turn Around Time of Job %d: %d\n",i+1,TurnAroundTime[i]);
                printf("Waiting Time of Job %d: %d\n",i+1,WaitingTime[i]);
                printf("Response Time of Job %d: %d\n",i+1,ResponseTime[i]);
                printf("----------------------------------\n");
                avgTat=avgTat+TurnAroundTime[i];
                avgWt=avgWt+WaitingTime[i];
                avgRt=avgRt+ResponseTime[i];
        }

        //Average of Turn Around time, Waiting time and Response time.
        printf("Average Turn Around Time: %.2f\n",(avgTat/jobs));
        printf("Average Waiting Time: %.2f\n",(avgWt/jobs));
        printf("Average Response Time: %.2f\n",(avgRt/jobs));
        
        return 0;
}