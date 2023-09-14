#include <bits/stdc++.h>

using namespace std;
int inf = 1e7;

class Graph
{
private:
    int numberOfVertex;
    vector<vector<pair<int, int>>> adj;

public:
    Graph(int numberOfVertex)
    {
        this->numberOfVertex = numberOfVertex;
        adj.resize(this->numberOfVertex);
    }

    void addEdge(int source, int destination, int weight)
    {
        adj[source].push_back({destination, weight});
    }

    void print()
    {
        for (int i = 0; i < numberOfVertex; i++)
        {
            cout << i << " -> ";
            for (int j = 0; j < adj[i].size(); j++)
            {
                cout << "(" << adj[i][j].first << ", " << adj[i][j].second << "), ";
            }

            cout << endl;
        }
    }

    void bellmanFord(int source, int destination)
    {
        vector<int> distance(numberOfVertex, inf);
        vector<int> parent(numberOfVertex, -1);

        distance[source] = 0;
        parent[source] = source;

        for (int i = 0; i < numberOfVertex; i++)
        {
            for (auto neighbor : adj[i])
            {
                int u = i;
                int v = neighbor.first;
                int w = neighbor.second;

                if (distance[u] != inf && distance[u] + w < distance[v])
                {
                    distance[v] = distance[u] + w;
                    parent[v] = u;
                }
            }
        }

        for (auto d : distance)
        {
            cout << d << " ";
        }
        cout << endl;

        printPath(parent, source, destination);

        cout << endl
             << distance[destination] << endl;
    }

    void printPath(vector<int> &parent, int src, int des)
    {
        if (src == des)
        {
            cout << src << " -> ";
            return;
        }
        if (parent[des] == -1)
        {
            cout << "Path not found" << endl;
            return;
        }

        printPath(parent, src, parent[des]);
        cout << des << " -> ";
    }
};

int main()
{
    int n, e;
    cin >> n >> e;

    Graph graph(n);

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        graph.addEdge(u, v, w);
    }

    cout << endl;

    graph.bellmanFord(0, 6);

    return 0;
}

/*
7 10
0 1 6
0 2 5
0 3 5
1 4 -1
2 1 -2
2 4 1
3 2 -2
3 5 -1
4 6 3
5 6 3
*/