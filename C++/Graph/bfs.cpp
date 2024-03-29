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
        adjList.resize(numberOfVertex);
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

            for (int j = 0; j < adjList[i].size(); j++)
            {
                cout << adjList[i][j] << " ";
            }

            cout << endl;
        }
    }

    void bfs(int source)
    {
        vector<bool> visited(numberOfVertex, false);

        visited[source] = true;
        queue<int> q;
        q.push(source);

        while (!q.empty())
        {
            int data = q.front();
            q.pop();

            cout << data << " -> ";

            for (auto neighbor : adjList[data])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

int main()
{
    int n, e;

    cin >> n >> e;

    Graph graph = Graph(n);

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        graph.addEdge(u, v);
    }

    graph.print();

    graph.bfs(5);

    return 0;
}

/*
v e
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