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
        adjList.resize(this->numberOfVertex);
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
            for (auto neigbhor : adjList[i])
            {
                cout << neigbhor << " ";
            }

            cout << endl;
        }
    }

    void _dfs(int source, vector<bool> &visited)
    {
        visited[source] = true;
        cout << source << " -> ";
        for (auto neighbor : adjList[source])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                _dfs(neighbor, visited);
            }
        }
    }

    void dfs(int source)
    {
        vector<bool> visited(numberOfVertex, false);

        _dfs(source, visited);
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

    graph.print();

    graph.dfs(0);

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