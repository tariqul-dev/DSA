#include <bits/stdc++.h>

using namespace std;

class Graph
{
private:
    int numberOfVertex;
    vector<vector<int>> adjList;

public:
    Graph(int numberOfVertex)
    {
        this->numberOfVertex = numberOfVertex;
        this->adjList.resize(this->numberOfVertex);
    }

    void addEdge(int source, int destination)
    {
        adjList[source].push_back(destination);
        adjList[destination].push_back(source);
    }

    void print()
    {
        for (int i = 0; i < adjList.size(); i++)
        {
            cout << i << " -> ";
            for (auto neighbor : adjList[i])
            {
                cout << neighbor << " ";
            }

            cout << endl;
        }
    }

    vector<int> shortestPath(int source, int destination)
    {
        vector<bool> visited(numberOfVertex, false);
        vector<int> path(numberOfVertex, -1);

        queue<int> q;
        visited[source] = true;
        q.push(source);

        vector<int> dist(numberOfVertex, -1);
        dist[source] = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            if (visited[destination] == true)
            {
                vector<int> p;

                int current = destination;

                while (current != -1)
                {
                    p.push_back(current);
                    current = path[current];
                }

                reverse(p.begin(), p.end());

                return p;
            }

            for (auto neighbor : adjList[node])
            {
                if (!visited[neighbor])
                {

                    dist[neighbor] = dist[node] + 1;
                    visited[neighbor] = true;
                    path[neighbor] = node;
                    q.push(neighbor);
                }
            }
        }

        return {};
    }
};

int main()
{

    int v, e;
    cin >> v >> e;

    Graph graph(v);

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        graph.addEdge(u, v);
    }

    // graph.print();

    cout << endl;

    vector<int> path = graph.shortestPath(0, 5);

    for (int p : path)
    {
        cout << p << " -> ";
    }

    return 0;
}

/*
6 8

0 1
0 2
0 4
1 4
2 3
3 4
3 5
4 5
*/