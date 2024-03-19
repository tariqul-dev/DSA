#include <bits/stdc++.h>

using namespace std;

int leastInterval(vector<char> &tasks, int n)
{
    vector<int> freq(26, 0);

    for (auto &ch : tasks)
    {
        freq[ch - 'A']++;
    }

    priority_queue<int> pq;
    int intervalCount = 0;

    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > 0)
        {
            pq.push(freq[i]);
        }
    }

    while (!pq.empty())
    {
        vector<int> temp;

        for (int i = 1; i <= n + 1; i++)
        {

            if (!pq.empty())
            {
                int freqCount = pq.top();
                pq.pop();

                freqCount--;
                temp.push_back(freqCount);
            }
        }

        for (int &t : temp)
        {
            if (t > 0)
            {
                pq.push(t);
            }
        }

        if (pq.empty())
        {
            intervalCount += temp.size();
        }
        else
        {
            intervalCount += n + 1;
        }
    }

    return intervalCount;
}

int main()
{

    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};

    int n = 2;

    cout << leastInterval(tasks, n) << endl;

    return 0;
}