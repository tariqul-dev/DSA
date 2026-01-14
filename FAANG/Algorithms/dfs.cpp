#include <iostream>
#include <vector>

using namespace std;

void inputGraph(vector<int> graph[], int E)
{
    for (int i = 1; i <= E; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void printGraph(vector<int> graph[], int V)
{
    for (int i = 1; i <= V; i++)
    {
        cout << i << " -> ";

        for (auto it : graph[i])
        {
            cout << it << " ";
        }

        cout << endl;
    }
}

void dfs(vector<int> graph[], int source, int visited[])
{
    visited[source] = 1;
    cout << source << " ";

    for (auto it : graph[source])
    {
        if (!visited[it])
        {
            dfs(graph, it, visited);
        }
    }
}

int main()
{
    const int V = 5, E = 7;
    vector<int> graph[V + 1];

    inputGraph(graph, E);
    printGraph(graph, V);

    int visited[V + 1] = {0};

    cout << "DFS: ";
    dfs(graph, 3, visited);

    cout << endl;

    return 0;
}

/*

Input edges:
1 2
1 3
2 3
2 4
2 5
3 4
4 5

Total edges:
1 2
1 3

2 1
2 3
2 4
2 5

3 1
3 2
3 4

4 2
4 3
4 5

5 2
5 4


1----2 \
|  / |   5
3----4 /
*/
