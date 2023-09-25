#include <iostream>
using namespace std;

struct edge
{
    int src;
    int dest;
    int d;
};

void bellmanFord(struct edge e[], int n, int ne, int s)
{
    int dist[n];
    for (int i = 0; i < n; i++)
    {
        if (i == s)
            dist[i] = 0;
        else
            dist[i] = 9999;
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < ne; j++)
        {
            if (dist[e[j].src] != 9999 && dist[e[j].src] + e[j].d < dist[e[j].dest])
            {
                dist[e[j].dest] = dist[e[j].src] + e[j].d;
            }
        }
    }
    cout << "\n\nShortest Distance to each node : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << " = " << dist[i] << endl;
    }
}

int main()
{
    int n, s, ne;
    cout << "Enter number of Nodes : ";
    cin >> n;
    cout << "Enter the Source Node number : ";
    cin >> s;
    cout << "Enter number of edges : ";
    cin >> ne;
    edge e[ne];
    for (int i = 0; i < ne; i++)
    {
        cout << "Enter node 1 : ";
        cin >> e[i].src;
        cout << "Enter node 2 : ";
        cin >> e[i].dest;
        cout << "Enter distance/cost between node 1 and node 2 : ";
        cin >> e[i].d;
    }
    for (int i = 0; i < ne; i++)
    {
        cout << "\n"
             << e[i].src << " -> " << e[i].dest << " = " << e[i].d;
    }
    bellmanFord(e, n, ne, s);
    return 0;
}