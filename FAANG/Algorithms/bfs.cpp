#include <iostream>
#include <vector>
#include <queue>

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
            cout << it << ", ";
        }
        cout << endl;
    }
}

void bfs(vector<int> graph[], int source, int V)  {
    int visit[V + 1] = {0};
    queue<int> q;
    visit[source] = 1;
    q.push(source);

    while (!q.empty()){
        int node = q.front(); 
        cout << node << " ";
        q.pop();

        for (auto it: graph[node]){
            if (!visit[it]){
                visit[it] = 1;
                q.push(it);
            }
        }
    }

    cout << endl;
}

int main()
{

    const int V = 5, E = 7;
    vector<int> graph[V + 1];

    inputGraph(graph, E);
    printGraph(graph, V);

    cout << "BFS: ";
    bfs(graph, 5, V);

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
