#include <bits/stdc++.h>

using namespace std;
int inf = 1e7;

class Graph
{
private:
    int numberOfVertex;
    vector<vector<pair<int, int>>> adjList;

public:
    Graph(int numberOfVertex)
    {
        this->numberOfVertex = numberOfVertex;
        adjList.resize(this->numberOfVertex);
    }

    void addEdge(int source, int destination, int weight)
    {
        adjList[source].push_back({destination, weight});
    }

    void print()
    {
        for (int i = 0; i < numberOfVertex; i++)
        {

            cout << i << " -> ";

            for (int j = 0; j < adjList[i].size(); j++)
            {
                cout << "( ";
                cout << adjList[i][j].first << ", " << adjList[i][j].second;
                cout << " ), ";
            }

            cout << endl;
        }
    }

    void dijkstra(int source, int destination)
    {
        vector<int> distance(numberOfVertex, inf);
        vector<int> parent(numberOfVertex, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        distance[source] = 0;
        parent[source] = -1;
        q.push({0, source}); // weight, node

        while (!q.empty())
        {
            auto it = q.top();
            q.pop();

            int nodeWeight = it.first;
            int node = it.second;

            for (auto neighbor : adjList[node])
            {
                int adjNode = neighbor.first;
                int edgeWeight = neighbor.second;

                if (nodeWeight + edgeWeight < distance[adjNode])
                {
                    distance[adjNode] = nodeWeight + edgeWeight;
                    parent[adjNode] = node;
                    q.push({distance[adjNode], adjNode});
                }
                
            }
        }

        for (auto i : distance)
        {
            cout << i << " ";
        }

        cout << endl;

        for (auto p : parent)
        {
            cout << p << " ";
        }

        cout << endl;
        printPath(parent, source, destination);
    }

    void printPath(vector<int> &parent, int src, int des)
    {
        if (src == des)
        {
            cout << src << " ";
            return;
        }

        if (parent[des] == -1)
        {
            cout << "No path found" << endl;
            return;
        }

        printPath(parent, src, parent[des]);

        cout << des << " ";
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

    graph.print();

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