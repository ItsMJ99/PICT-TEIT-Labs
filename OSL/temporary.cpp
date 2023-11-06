#include <iostream>
#define MAX_QUEUE_SIZE 100
using namespace std;

struct Process
{
    int pid, at, bt, ct, tat, wt, rt;
    bool cs;
};

void sjf()
{
    int n, i;
    cout << "Enter the number of processes : ";
    cin >> n;
    Process p[n];
    for (i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        cout << "Enter Process " << i + 1 << " Arrival Time : ";
        cin >> p[i].at;
        cout << "Enter Process " << i + 1 << " Burst Time : ";
        cin >> p[i].bt;
        p[i].rt = p[i].bt;
        p[i].cs = false;
    }
    int curtime = 0, completed = 0;
    cout << "\nGantt Chart" << endl;
    while (completed != n)
    {
        int shortest = -1;
        for (i = 0; i < n; i++)
        {
            if (!p[i].cs && p[i].at <= curtime && (shortest == -1 || p[shortest].rt > p[i].rt))
            {
                shortest = i;
            }
        }
        p[shortest].rt--;
        curtime++;
        cout << "|";
        cout << "P" << p[shortest].pid;
        if (p[shortest].rt == 0)
        {
            completed++;
            p[shortest].cs = true;
            p[shortest].ct = curtime;
        }
    }
    cout << "|\n"
         << endl;
    for (i = 0; i < n; i++)
    {
        cout << "P" << p[i].pid << " Completed at " << p[i].ct << "ms" << endl;
    }

    cout << "\nTable" << endl;
    cout << "PID\tAt\tBT\tCT\tTAT\tWT" << endl;
    double total_tat = 0, total_wt = 0;
    for (i = 0; i < n; i++)
    {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        total_tat += p[i].tat;
        total_wt += p[i].wt;
        cout << p[i].pid << "\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].ct << "\t" << p[i].tat << "\t" << p[i].wt << endl;
    }

    cout << "\nAverage Turn Around Time : " << total_tat / n << endl;
    cout << "Average Waiting Time : " << total_wt / n << endl;
}

void enque(int queue[], int *rear, int pid)
{
    if (*rear == MAX_QUEUE_SIZE - 1)
    {
        cout << "Queue is Full and cannot accept Process " << pid << endl;
    }
    queue[++(*rear)] = pid;
}

int deque(int queue[], int *rear, int *front)
{
    if (*front > *rear)
    {
        cout << "Queue is Empty" << endl;
    }
    return queue[(*front)++];
}

void rr()
{
    int tq, n, completed = 0, i;
    cout << "Enter the number of processes : ";
    cin >> n;
    Process p[n];
    for (i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        cout << "Enter Process " << i + 1 << " Arrival Time : ";
        cin >> p[i].at;
        cout << "Enter Process " << i + 1 << " Burst Time : ";
        cin >> p[i].bt;
        p[i].rt = p[i].bt;
        p[i].ct = 0;
        p[i].cs = false;
    }
    cout << "Enter the Time Quantum : ";
    cin >> tq;
    int curtime = 0;
    int queue[MAX_QUEUE_SIZE], front = 0, rear = -1;
    cout << "Gantt Chart" << endl;
    while (completed != n)
    {
        for (i = 0; i < n; i++)
        {
            if (!p[i].cs && p[i].at <= curtime && p[i].rt > 0)
            {
                if (p[i].rt >= tq)
                {
                    p[i].rt -= tq;
                    curtime += tq;
                }
                else
                {
                    curtime += p[i].rt;
                    p[i].rt = 0;
                }
                cout << "|P" << p[i].pid;
                if (p[i].rt == 0)
                {
                    completed++;
                    p[i].cs = true;
                    p[i].ct = curtime;
                    p[i].tat = p[i].ct - p[i].at;
                    p[i].wt = p[i].tat - p[i].bt;
                }
                else
                {
                    enque(queue, &rear, p[i].pid);
                }
            }
        }
        if (front <= rear)
        {
            int next_process = deque(queue, &rear, &front);
            enque(queue, &rear, next_process);
        }
        else
        {
            curtime++;
        }
    }
    cout << "|\n"
         << endl;

    for (i = 0; i < n; i++)
    {
        cout << "P" << p[i].pid << " Completed at " << p[i].ct << "ms" << endl;
    }

    cout << "\nTable" << endl;
    cout << "PID\tAt\tBT\tCT\tTAT\tWT" << endl;
    double total_tat = 0, total_wt = 0;
    for (i = 0; i < n; i++)
    {
        total_tat += p[i].tat;
        total_wt += p[i].wt;
        cout << p[i].pid << "\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].ct << "\t" << p[i].tat << "\t" << p[i].wt << endl;
    }

    cout << "\nAverage Turn Around Time : " << total_tat / n << endl;
    cout << "Average Waiting Time : " << total_wt / n << endl;
}

int main()
{
    int ch, c = 0;
    while (c == 0)
    {
        cout << "0.Exit\n1.SJF (Premptive)\n2.RR\n";
        cout << "Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 0:
            c = 1;
            break;
        case 1:
            sjf();
            break;
        case 2:
            rr();
            break;
        default:
            cout << "Invalid Input !!!" << endl;
        }
    }
    return 0;
}