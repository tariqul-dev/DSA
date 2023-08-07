#include <bits/stdc++.h>

using namespace std;

void bfs(vector<int> graph[], int source, int vertex)
{

    int visited[vertex] = {0};
    queue<int> q;

    visited[source] = 1;
    q.push(source);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (auto i : graph[node])
        {
            if (!visited[i])
            {
                visited[i] = 1;
                q.push(i);
            }
        }
    }

    cout << endl;
}

int main()
{

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

    o/p: 1 2 6 3 4 7 8 5
    */

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

    bfs(graph, 1, vertex);

    return 0;
}