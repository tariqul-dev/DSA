#include <bits/stdc++.h>

using namespace std;

int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
{
    int count = 0;
    int index = ruleKey == "type" ? 0 : ruleKey == "color" ? 1
                                                           : 2;

    for (auto item : items)
    {
        if (item[index] == ruleValue)
            count++;
    }

    return count;
}

int main()
{
    vector<vector<string>> items = {
        {"phone", "blue", "pixel"},
        {"computer", "silver", "lenovo"},
        {"phone", "gold", "iphone"},
    };
    string ruleKey = "color", ruleValue = "silver";

    cout << countMatches(items, ruleKey, ruleValue);

    return 0;
}