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

    void dijkstra(int source, int destination)
    {
        vector<int> distance(numberOfVertex, inf);
        vector<int> parent(numberOfVertex, -1);
        set<pair<int, int>> s;

        distance[source] = 0;
        parent[source] = source;
        s.insert({0, source});

        while (!s.empty())
        {
            auto it = *(s.begin());
            int node = it.second;
            int dis = it.first;

            s.erase(it);

            for (auto neighbor : adj[node])
            {
                int neighborNode = neighbor.first;
                int edgeWeight = neighbor.second;

                if (dis + edgeWeight < distance[neighborNode])
                {
                    if (distance[neighborNode] != inf)
                        s.erase({distance[neighborNode], neighborNode});

                    distance[neighborNode] = dis + edgeWeight;
                    parent[neighborNode] = node;
                    s.insert({distance[neighborNode], neighborNode});
                }
            }
        }

        for (auto d : distance)
        {
            cout << d << " ";
        }

        cout << endl;

        printPath(parent, source, destination);

        cout << endl;
    }

    void printPath(vector<int> &parent, int src, int des)
    {
        if (src == des)
        {
            cout << src << "->";
            return;
        }

        if (parent[des] == -1)
        {
            cout << "Path not found" << endl;
            return;
        }

        printPath(parent, src, parent[des]);
        cout << des << "->";
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

    graph.dijkstra(0, 5);

    return 0;
}

/*
6 8
0 1 2
0 2 4
1 3 7
2 1 1
2 4 3
3 5 1
4 3 2
4 5 5


*/