#include <bits/stdc++.h>

using namespace std;

void bfs(vector<int> adj[], int source, int vertex)
{
    bool visited[vertex] = {false};
    queue<int> q;

    visited[source] = true;
    q.push(source);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (auto i : adj[node])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }

    cout << endl;
}

void dfs(vector<int> adj[], int source, int visited[])
{
    visited[source] = 1;

    cout << source << " ";

    for (auto i : adj[source])
    {
        if (!visited[i])
            dfs(adj, i, visited);
    }
}

int main()
{

    int vertex, edges;
    cin >> vertex >> edges;

    vector<int> graph[vertex + 1];

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i <= vertex; i++)
    {
        cout << i << " -> { ";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << " (" << graph[i][j] << "),";
        }

        cout << " }" << endl;
    }

    cout << endl;

    bfs(graph, 1, vertex);
    cout << endl;
    int visited[vertex + 1] = {0};

    dfs(graph, 1, visited);

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
*/