#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int profit = 0;
    int j = 0;

    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[j] < prices[i])
        {
            profit = max(profit, prices[i] - prices[j]);
        }
        else
        {
            j = i;
        }
    }

    return profit;
}

int main()
{
    vector<int> prices = {1, 2, 4, 2, 5, 7, 2, 4, 9, 0, 9};

    cout << maxProfit(prices) << endl;

    return 0;
}