#include <stdio.h>
#include <stdbool.h>

struct Process
{
    int pid, at, bt, tat, wt, ct, rt, qt;
    bool completed;
};

void sortAt(struct Process p[], int size)
{
    struct Process temp;
    bool swapped = false;
    int i;
    do
    {
        swapped = false;
        for (i = 0; i < size - 1; i++)
        {
            if (p[i].at > p[i + 1].at)
            {
                temp = p[i];
                p[i] = p[i + 1];
                p[i + 1] = temp;
                swapped = true;
            }
        }
    } while (swapped);
}

void roundRobin(struct Process p[], int tq, int size)
{
    int completed = 0, i, temp, current_time = -1, index = 0;
    sortAt(p, size);
    // Set current time to the first arrival time of all processes.
    current_time = p[0].at;
    while (completed != size)
    {
        temp = 9999;
        // Find the process which is not completed but in the queue with the least queue time.
        for (i = 0; i < size; i++)
        {
            if (!p[i].completed && p[i].qt <= current_time && p[i].qt < temp)
            {
                temp = p[i].qt;
                index = i;
            }
        }
        // For the found process, take a decision based on the remaining time.
        if (p[index].rt >= tq)
        {
            p[index].rt -= tq;
            current_time += tq;
            p[index].qt = current_time;
        }
        else
        {
            current_time += p[index].rt;
            p[index].rt = 0;
        }
        // completed = update parameters.
        if (p[index].rt == 0)
        {
            printf("\nProcess %d completed", p[index].pid);
            p[index].completed = true;
            p[index].ct = current_time;
            p[index].tat = p[index].ct - p[index].at;
            p[index].wt = p[index].tat - p[index].bt;
            completed += 1;
        }
    }
}

int main()
{
    int i, tq, n;
    float avg_wt = 0, avg_tat = 0;
    printf("Enter Number of Processes : ");
    scanf("%d", &n);
    printf("\nEnter time quantum/slice : ");
    scanf("%d", &tq);
    struct Process proc[n];
    for (i = 0; i < n; i++)
    {
        printf("\nProcess ID : ");
        scanf("%d", &proc[i].pid);
        printf("\nArrival Time : ");
        scanf("%d", &proc[i].at);
        printf("\nBurst Time : ");
        scanf("%d", &proc[i].bt);
        printf("\n");
        proc[i].completed = false;
        proc[i].qt = proc[i].at;
        proc[i].rt = proc[i].bt;
    }

    roundRobin(proc, tq, n);

    tq = proc[0].at;

    printf("\n\nPID\tAT\tBT\tCT\tTAT\tWT");
    for (i = 0; i < n; i++)
    {
        avg_wt += proc[i].wt;
        avg_tat += proc[i].tat;
        printf("\n%d\t%d\t%d\t%d\t%d\t%d", proc[i].pid, proc[i].at, proc[i].bt, proc[i].ct, proc[i].tat, proc[i].wt);
    }

    // Calculate and print average values after the loop
    printf("\n\nAverage Turn Around Time : %f ms", avg_tat / n);
    printf("\nAverage Waiting Time : %f ms", avg_wt / n);
    printf("\n");
    return (0);
}
