#include <bits/stdc++.h>

using namespace std;

vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
{
    int maxValue = candies[0];

    for (int i = 1; i < candies.size(); i++)
        if (candies[i] > maxValue)
            maxValue = candies[i];

    vector<bool> result;

    for (auto candy : candies)
        if (candy + extraCandies >= maxValue)
            result.push_back(true);
        else
            result.push_back(false);

    return result;
}

int main()
{
    vector<int> candies = {2, 3, 5, 1, 3};
    int extraCandies = 3;

    for (auto c : kidsWithCandies(candies, extraCandies))
        cout << c << " ";

    cout << endl;

    return 0;
}