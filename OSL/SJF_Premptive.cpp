#include <stdio.h>
#include <stdbool.h>

struct Process
{
    int pid, at, bt, tat, wt, ct, rt;
    bool completed;
};

void shortest_job_first(struct Process p[], int size)
{
    // Sort processes by bt.
    int currtime = 0, completed = 0, index, i, temp;
    while (completed != size)
    {
        temp = 9999;
        bool found = false;
        // Search for element in ready queue with shortest bt
        for (i = 0; i < size; i++)
        {
            if (!p[i].completed && p[i].at <= currtime && p[i].rt < temp)
            {
                temp = p[i].rt;
                index = i;
            }
        }
        p[index].rt -= 1;
        if (p[index].rt == 0)
        {
            printf("\nProcess %d completed at time %d", p[index].pid, (currtime + 1));
            p[index].completed = true;
            p[index].ct = currtime + 1;
            p[index].tat = p[index].ct - p[index].at;
            p[index].wt = p[index].tat - p[index].bt;
            completed += 1;
        }
        currtime += 1;
    }
}

int main()
{
    int i, n;
    float avg_wt = 0, avg_tat = 0;
    printf("Enter Number of Processes : ");
    scanf("%d", &n);
    struct Process proc[n];
    for (i = 0; i < n; i++)
    {
        printf("\n");
        printf("\nProcess ID : ");
        scanf("%d", &proc[i].pid);
        printf("\nArrival Time : ");
        scanf("%d", &proc[i].at);
        printf("\nBurst Time : ");
        scanf("%d", &proc[i].bt);
        proc[i].completed = false;
        proc[i].rt = proc[i].bt;
    }

    shortest_job_first(proc, n);

    printf("\n\nPID\tAT\tBT\tCT\tTAT\tWT");
    for (i = 0; i < n; i++)
    {
        avg_wt += proc[i].wt;
        avg_tat += proc[i].tat;
        printf("\n%d\t%d\t%d\t%d\t%d\t%d\t", proc[i].pid, proc[i].at, proc[i].bt, proc[i].ct, proc[i].tat, proc[i].wt);
    }
    printf("\n\nAverage Turn Around Time : %f ms", avg_tat / n);
    printf("\n\nAverage Waiting Time : %f ms", avg_wt / n);
    return 0;
}
