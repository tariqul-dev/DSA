#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void calculateSum(vector<int> &candidates, int target, int index, vector<int> output, vector<vector<int>> &result)
    {
        if (index == candidates.size())
        {

            if (target == 0)
                result.push_back(output);

            return;
        }

        if (candidates[index] <= target)
        {
            output.push_back(candidates[index]);
            calculateSum(candidates, target - candidates[index], index, output, result);

            output.pop_back();
        }

        calculateSum(candidates, target, index + 1, output, result);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        calculateSum(candidates, target, 0, vector<int>(), result);

        return result;
    }
};

int main()
{

    vector<int> arr = {2, 3, 6, 7};
    Solution s = Solution();

    vector<vector<int>> result;

    result = s.combinationSum(arr, 7);

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
