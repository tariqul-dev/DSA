#include <bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map<int, vector<int>> adjList;

    // adjList[3].push_back(3);
    // adjList[3].push_back(5);
    // adjList[4].push_back(3);
    // adjList[4].push_back(5);
    // adjList[5].push_back(3);
    // adjList[5].push_back(4);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    

    cout << "inputed" << endl; for (auto neighbour : adjList)
    {
        cout << neighbour.first << " => ";

        for (auto node : neighbour.second)
        {
            cout << node << " ";
        }

        cout << endl;
    }

    // int numberOfEdges;

    // cin >> numberOfEdges;

    // for (int i = 0; i < numberOfEdges; i++)
    // {
    //     int u, v;
    //     cin >> u >> v;
    //     if(adjList[u])
    //         adjList[u].push_back(v);
    // }

    // for (auto list : adjList)
    // {
    //     cout << list.first << "=> ";

    //     for (auto node : list.second)
    //     {
    //         cout << node << " ";
    //     }

    //     cout << endl;
    // }

    return 0;
}