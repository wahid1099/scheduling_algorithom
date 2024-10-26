#include <stdio.h>

#include <stdio.h>

int main()
{
    int n;

    // Input the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n], p[n];
    int isCompleted[n]; // to mark completed processes
    for (int i = 0; i < n; i++)
    {
        isCompleted[i] = 0; // initialize all processes as not completed
    }

    // Input arrival time and burst time for each process
    for (int i = 0; i < n; i++)
    {
        p[i] = i + 1; // process id
        printf("Enter Arrival Time and Burst Time for Process %d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    int currentTime = 0;
    int completed = 0;

    // While not all processes are completed
    while (completed != n)
    {
        int idx = -1;
        int minBurst = 100000; // large number to find the minimum

        // Select the process with the shortest burst time which has arrived
        for (int i = 0; i < n; i++)
        {
            if (at[i] <= currentTime && isCompleted[i] == 0)
            {
                if (bt[i] < minBurst)
                {
                    minBurst = bt[i];
                    idx = i;
                }
            }
        }

        if (idx != -1)
        {
            ct[idx] = currentTime + bt[idx]; // Completion time
            tat[idx] = ct[idx] - at[idx];    // Turnaround time
            wt[idx] = tat[idx] - bt[idx];    // Waiting time
            currentTime = ct[idx];           // Update current time
            isCompleted[idx] = 1;            // Mark the process as completed
            completed++;
        }
        else
        {
            currentTime++; // If no process is available, increment time
        }
    }

    // Output the result
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}