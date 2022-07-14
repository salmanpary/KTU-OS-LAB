#include <stdio.h>
void findwaitingtime(int processes[], int n, int bt[], int wt[], int quantum)
{
    int rem_bt[n];

    for (int i = 0; i < n; i++)
    {
        rem_bt[i] = bt[i];
    }
    int t = 0;
    while (1)
    {
        int flag = 1;
        for (int i = 0; i < n; i++)
        {
            if (rem_bt > 0)
            {
                flag = 0;
            }
            if (rem_bt > quantum)
            {
                t += quantum;
                rem_bt[i] = rem_bt[i] - quantum;
            }
            else
            {
                t = t + rem_bt[i];
                wt[i] = t - bt[i];
                rem_bt[i] = 0;
            }
        }

        if (flag == 1)
        {
            break;
        }
    }
}
void findturnaroundtime(int processes[], int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
}
void findavgtime(int processes[], int n, int bursttime[], int quantum)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    findWaitingTime(processes, n, bursttime, wt, quantum);

    // Function to find turn around time for all processes
    findTurnAroundTime(processes, n, bursttime, wt, tat);
    printf("PN\t\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("%d\t\t%d\t%d\t\t%d\n", i + 1, bursttime[i], wt[i], tat[i]);
        printf("Average waiting time= %f", (float)total_wt / (float)n);
        printf("\n Average turn around time= %f", (float)total_tat, (float)n);
    }
}
int main()
{
    int processes[] = {1, 2, 3};
    int n = sizeof processes / sizeof processes[0];
    int bursttime[] = {10, 5, 8};
    int quantum = 2;
    findavgtime(processes, n, bursttime, quantum);
}
