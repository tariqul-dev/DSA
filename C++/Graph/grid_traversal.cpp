#include <bits/stdc++.h>

using namespace std;

class Graph
{
private:
    int row, col;
    vector<vector<int>> maze;

public:
    Graph(int row, int col)
    {
        this->row = row;
        this->col = col;
        maze.resize(row, vector<int>(col, -1));
    }

    void addEdge(int u, int v, int w)
    {
        maze[u][v] = w;
    }

    void print()
    {

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << maze[i][j] << "\t";
            }
            cout << endl;
        }
    }

    bool isInSideMaze(pair<int, int> coord)
    {
        int x = coord.first;
        int y = coord.second;
        return (x >= 0 && x < row) && (y >= 0 && y < col);
    }

    bool isSafe(pair<int, int> coord)
    {
        return maze[coord.first][coord.second] != -1;
    }

    bool isVisited(vector<vector<int>> &visited, pair<int, int> coord)
    {
        return visited[coord.first][coord.second] == 0;
    }

    vector<vector<int>> bfs(pair<int, int> src, pair<int, int> des)
    {
        vector<vector<int>> visited(row, vector<int>(col, 0));
        vector<vector<int>> parent(row, vector<int>(col, -1));

        queue<pair<int, int>> q;

        q.push(src);
        visited[src.first][src.second] = 1;
        parent[src.first][src.second] = 0;

        int dx[] = {0, 0, -1, 1};
        int dy[] = {1, -1, 0, 0};

        while (!q.empty())
        {
            pair<int, int> node = q.front();
            int x = node.first;
            int y = node.second;
            q.pop();

            if (x == des.first && y == des.second)
            {
                return path;
            }

            for (int i = 0; i < 4; i++)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];

                pair<int, int> neighbor = {newX, newY};

                if (isInSideMaze(neighbor) && isSafe(neighbor) && isVisited(visited, neighbor))
                {
                    q.push(neighbor);
                    visited[newX][newY] = 1;
                    parent[newX][newY] = {x, y};
                }
            }
        }
    }
};

int main()
{

    int row, col;
    pair<int, int> source;
    pair<int, int> destination;
    cin >> row >> col;

    Graph graph(row, col);

    for (int i = 0; i < row; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '.')
                graph.addEdge(i, j, 0);

            if (s[j] == 'A')
                source = {i, j};
            if (s[j] == 'B')
                destination = {i, j};
        }
    }

    graph.print();

    vector<pair<int, int>> path = graph.bfs(source, destination);

    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i].first << ", " << path[i].second << endl;
    }

    return 0;
}

/*
5 8
########
#.A#...#
#.##.#B#
#......#
########
*/