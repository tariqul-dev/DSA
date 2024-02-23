#include <bits/stdc++.h>

using namespace std;

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<int> distance(n, INT_MAX);

    unordered_map<int, vector<pair<int, int>>> adj;

    for (vector<int> &flight : flights)
    {
        int u = flight[0];
        int v = flight[1];
        int price = flight[2];

        adj[u].push_back({v, price});
    }

    // BFS
    queue<pair<int, int>> q;
    q.push({src, 0});
    distance[src] = 0;

    int steps = 0;

    while (!q.empty() && steps <= k)
    {
        int N = q.size();

        while (N--)
        {
            int u = q.front().first;
            int price = q.front().second;

            q.pop();

            for (pair<int, int> &adjNode : adj[u])
            {
                int v = adjNode.first;
                int currentPrice = adjNode.second;

                if (distance[v] > price + currentPrice)
                {
                    distance[v] = price + currentPrice;
                    q.push({v, price + currentPrice});
                }
            }
        }

        steps++;
    }

    return distance[dst] != INT_MAX ? distance[dst] : -1;
}

int main()
{

    int n = 4;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
    int src = 0, dst = 3, k = 1;

    cout << findCheapestPrice(n, flights, src, dst, k) << endl;

    return 0;
}