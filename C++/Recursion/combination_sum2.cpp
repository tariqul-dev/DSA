#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void calculateSum(vector<int> &candidates, int target, int index, vector<vector<int>> &result, vector<int> &output)
    {
        if (target == 0)
        {
            result.push_back(output);
            return;
        }

        for (int i = index; i < candidates.size(); i++)
        {
            if (i > index && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
                break;

            output.push_back(candidates[i]);
            calculateSum(candidates, target - candidates[i], i + 1, result, output);

            output.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> output;

        calculateSum(candidates, target, 0, result, output);

        return result;
    }
};

int main()
{
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    Solution s = Solution();
    vector<vector<int>> result = s.combinationSum2(candidates, 8);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}