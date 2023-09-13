#include <bits/stdc++.h>

using namespace std;

int inf = 1e9;

class Graph
{
private:
    int numberOfVertex;
    vector<vector<int>> adjMatrix;
    vector<vector<int>> distance;

public:
    Graph(int numberOfVertex)
    {
        this->numberOfVertex = numberOfVertex;
        adjMatrix.resize(this->numberOfVertex, vector<int>(this->numberOfVertex, inf));
    }

    void print()
    {
        for (int i = 0; i < numberOfVertex; i++)
        {
            for (int j = 0; j < numberOfVertex; j++)
            {
                cout << adjMatrix[i][j] << " ";
            }

            cout << endl;
        }
    }

    void addEdge(int src, int des, int w)
    {
        adjMatrix[src][des] = w;
        if (adjMatrix[src][src] == inf)
            adjMatrix[src][src] = 0;
    }

    void allPairsShortestPath()
    {
        distance = adjMatrix;

        for (int k = 0; k < numberOfVertex; k++)
        {
            for (int i = 0; i < numberOfVertex; i++)
            {
                for (int j = 0; j < numberOfVertex; j++)
                {
                    if (distance[i][k] + distance[k][j] < distance[i][j])
                        distance[i][j] = distance[i][k] + distance[k][j];
                }
                if (distance[k][i] == inf)
                {
                    cout << '#' << " ";
                }
                else
                    cout << distance[k][i] << " ";
            }

            cout << endl;
        }

        cout << endl;

        for (int i = 0; i < numberOfVertex; i++)
        {
            for (int j = 0; j < numberOfVertex; j++)
            {
                if (distance[i][j] == inf)
                {
                    cout << '#' << " ";
                }
                else
                    cout << distance[i][j] << " ";
            }

            cout << endl;
        }

        cout << endl <<  endl;

    }

    vector<int> getPath(int source, int destination)
    {


        if (distance[source][destination] == inf)
        {
            // No path exists
            return {};
        }

        vector<int> path;
        path.push_back(source);

        while (source != destination)
        {
            for (int i = 0; i < numberOfVertex; i++)
            {
                if (i != source && distance[source][destination] == distance[source][i] + adjMatrix[i][destination])
                {
                    source = i;
                    path.push_back(source);
                    break;
                }
            }
        }

        return path;
    }
};

int main()
{
    int n, e;
    cin >> n >> e;

    Graph graph(n);

    for (int i = 0; i < e; i++)
    {
        // cout << i << " ";
        int u, v, w;
        cin >> u >> v >> w;

        graph.addEdge(u, v, w);
    }

    graph.print();

    cout << endl
         << endl;

    graph.allPairsShortestPath();

    vector <int> path = graph.getPath(1, 3);

    for (int p: path){
        cout << p << " -> ";
    } 

    cout << endl;

    return 0;
}

/*
4 7

0 1 3
0 3 7
1 0 8
1 2 2
2 0 5
2 3 1
3 0 2
*/