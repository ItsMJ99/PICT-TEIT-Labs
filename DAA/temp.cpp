#include <iostream>
#include <vector>
using namespace std;

struct edges
{
    int src;
    int dest;
    int d;
};

void bellmanford(struct edges e[], int s, int ne, int n)
{
    int dist[n];
    int pred[n];
    for (int i = 0; i < n; i++)
    {
        if (i == s)
        {
            dist[i] = 0;
            pred[i] = -1;
        }
        else
        {
            dist[i] = 9999;
            pred[i] = -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < ne; j++)
        {
            if (dist[e[j].src] != 9999 && dist[e[j].src] + e[j].d < dist[e[j].dest])
            {
                dist[e[j].dest] = dist[e[j].src] + e[j].d;
                pred[e[j].dest] = e[j].src;
            }
        }
    }

    for (int i = 0; i < ne; i++)
    {
        if (dist[e[i].src] != 9999 && dist[e[i].src] + e[i].d < dist[e[i].dest])
        {
            cout << "Negative Cycle Found in the Graph" << endl;
            return;
        }
    }

    cout << "Shortest distance from source to destination node for each node given by user " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << s << " to " << i << " = " << dist[i] << "Path : ";
        vector<int> pathNode;
        int current = i;
        while (current != -1)
        {
            pathNode.push_back(current);
            current = pred[current];
        }
        for (int i = pathNode.size() - 1; i >= 0; i--)
        {
            cout << pathNode[i];
            if (i != 0)
                cout << " -> ";
        }
    }
}

int main()
{
    int n, ne, s;
    cout << "Enter the number of nodes : ";
    cin >> n;
    cout << "\nEnter the number of edges : ";
    cin >> ne;
    cout << "\nEnter the source node : ";
    cin >> s;
    edges e[ne];
    cout << "\nEnter the Source Nodes and Destination along with Cost" << endl;
    for (int i = 0; i < ne; i++)
    {
        cout << "Enter the Source Node number : ";
        cin >> e[i].src;
        cout << "Enter the Destination Node number : ";
        cin >> e[i].dest;
        cout << "Enter the Cost of Source to Destination : ";
        cin >> e[i].d;
    }
    cout << "\nCurrent Nodes Linkage" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Source Node : " << e[i].src << " Destination Node : " << e[i].dest << " Cost : " << e[i].d << endl;
    }
    bellmanford(e, s, ne, n);
    return 0;
}