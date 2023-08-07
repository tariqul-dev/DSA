#include <bits/stdc++.h>

using namespace std;

void dfs(vector<int> graph[], int visited[], int source)
{
    visited[source] = 1;
    cout << source << " ";

    for (auto i : graph[source])
    {
        if (!visited[i])
        {
            dfs(graph, visited, i);
        }
    }
}

int main()
{

    int vertex, edges;
    cin >> vertex >> edges;

    vector<int> graph[vertex + 1];

    for (int i = 0; i < edges; i++)
    {
        int v, u;
        cin >> v >> u;

        graph[v].push_back(u);
        graph[u].push_back(v);
    }

    for (int i = 0; i < vertex + 1; i++)
    {
        cout << i << " -> { ";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << ", ";
        }
        cout << " }" << endl;
    }

    cout << endl;

    int visited[vertex + 1] = {0};

    dfs(graph, visited, 1);

    return 0;
}

/*
8 8
1 2
1 6
2 3
2 4
4 5
5 7
6 7
6 8

o/p: 1 2 3 4 5 7 6 8
*/