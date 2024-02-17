#include <bits/stdc++.h>

using namespace std;

int furthestBuilding(vector<int> &heights, int bricks, int ladders)
{
    int n = heights.size();
    priority_queue<int> pq; // max heap

    for (int i = 0; i < n - 1; i++)
    {
        int diff = heights[i + 1] - heights[i];
        if (diff <= 0)
            continue;

        bricks -= diff;
        pq.push(diff); // diff = number of bricks is using

        if (bricks < 0)
        {
            if (ladders == 0)
                return i;

            ladders--;
            bricks += pq.top();
            pq.pop();
        }
    }

    return n - 1;
}

int main()
{

    vector<int> heights = {4, 12, 2, 7, 3, 18, 20, 3, 19};
    int bricks = 10, ladders = 2;

    cout << furthestBuilding(heights, bricks, ladders) << endl;

    return 0;
}