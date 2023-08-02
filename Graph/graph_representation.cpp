#include <bits/stdc++.h>

using namespace std;

const int n = 7;

void print(int graph[n][n])
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << graph[i][j] << " ";
        }

        cout << endl;
    }
}

// Adj matrix
void insert(int graph[n][n])
{
    for (int i = 0; i < 9; i++)
    {
        int u, v;

        cin >> u >> v;
        graph[u][v] = graph[v][u] = 1;
    }
}

// Adj list
void insertAsList(vector<vector<int>> &graph, int size)
{
    for (int i = 0; i < size; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void printAsList(vector<vector<int>> graph)
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << " --> ";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << " ";
        }

        cout << endl;
    }
}

int main()
{
    vector<int> graph[n];

    for (int i = 0; i < 9; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " --> ";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}

/*

1 2
1 3
1 4
2 4
3 4
3 5
4 5
4 6
5 6
*/