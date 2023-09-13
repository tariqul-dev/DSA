#include <bits/stdc++.h>

using namespace std;

void bfs(unordered_map<int, vector<int>> &graph, int source)
{
    unordered_map<int, bool> visited;
    queue<int> q;
    visited[source] = true;
    q.push(source);

    while (!q.empty())
    {
        source = q.front();
        cout << source << " ";
        q.pop();

        for (auto node : graph[source])
        {
            if (!visited[node])
            {
                visited[node] = true;
                q.push(node);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;














    
    unordered_map<int, vector<int>> graph;

    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (auto nodes : graph)
    {
        cout << nodes.first << " => ";
        for (auto node : nodes.second)
        {
            cout << node << " ";
        }

        cout << endl;
    }
    
    bfs(graph, 3);
    return 0;
}