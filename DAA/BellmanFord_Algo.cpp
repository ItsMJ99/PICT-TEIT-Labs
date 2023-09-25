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
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < ne; j++)
        {
            if (dist[e[j].src] != 9999 && dist[e[j].src] + e[j].d < dist[e[j].dest])
                dist[e[j].dest] = dist[e[j].src] + e[j].d;
        }
    }
    cout << "\n\nShortest distance/cost for each node from source to destination : \n";
    for (int i = 0; i < n; i++)
    {
        cout << s << " to " << i << " = " << dist[i] << endl;
    }
}

int main()
{
    int n, ne, s;
    cout << "Enter the number of Nodes : ";
    cin >> n;
    cout << "Enter the Source Node number : ";
    cin >> s;
    cout << "Enter the number of Edges : ";
    cin >> ne;

    edge e[ne];
    for (int i = 0; i < ne; i++)
    {
        cout << "Enter node 1 number (src) : ";
        cin >> e[i].src;
        cout << "Enter node 2 number (dest) : ";
        cin >> e[i].dest;
        cout << "Enter src to dest cost/distance : ";
        cin >> e[i].d;
    }

    cout << "\n\nCurrent Nodes Linking : " << endl;
    for (int i = 0; i < ne; i++)
    {
        cout << e[i].src << " to " << e[i].dest << " = " << e[i].d << endl;
    }
    bellmanFord(e, n, ne, s);
    return 0;
}