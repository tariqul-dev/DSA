#include <bits/stdc++.h>

using namespace std;

void print(vector<vector<int>> result)
{
    for (auto r : result)
    {
        for (auto d : r)
            cout << d << " ";
        cout << endl;
    }

    cout << endl;
}

void print(vector<int> result)
{
    for (auto r : result)
        cout << r << " ";

    cout << endl;
}

void calculateSum(vector<int> &candidates, int target, int index, vector<int> &ds, vector<vector<int>> &result, int sum)
{
    if (sum > target || index >= candidates.size())
        return;

    if (sum == target)
    {
        result.push_back(ds);
        return;
    }

    sum += candidates[index];
    ds.push_back(candidates[index]);

    calculateSum(candidates, target, index, ds, result, sum);

    sum -= candidates[index];
    ds.pop_back();

    calculateSum(candidates, target, index + 1, ds, result, sum);
}
// backtraking
void calculateSolution(vector<int> &candidates, int target, int currentIndex, vector<int> &currentAns, vector<vector<int>> &ans, int currentSum)
{
    if (currentSum > target || currentIndex >= candidates.size())
        return; // backtrack

    if (currentSum == target)
    {
        ans.push_back(currentAns); // storing result
        return;                    // backtrack
    }

    for (int i = currentIndex; i < candidates.size(); i++) // trying all possible combination from current index to end of candidates
    {
        currentAns.push_back(candidates[i]); // picking a probable solution
        currentSum += candidates[i];         // adding candidated to sum for checking target sum

        calculateSolution(candidates, target, i, currentAns, ans, currentSum); // trying this solution is success or not

        currentAns.pop_back(); // removing current solution to trying next combination
        currentSum -= candidates[i];
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> result;
    vector<int> ds;

    calculateSolution(candidates, target, 0, ds, result, 0);
    return result;
}

int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = combinationSum(candidates, target);

    print(result);

    return 0;
}