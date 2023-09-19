#include <bits/stdc++.h>

using namespace std;

vector<int> plusOne(vector<int> &digits)
{
    int n = digits.size();

    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
        {
            digits[i]++;
        }

        if (digits[i] == 10)
        {
            digits[i] = 0;

            if (i != 0)
            {
                digits[i - 1]++;
            }
            else
            {
                digits.push_back(0);
                digits[i] = 1;
            }
        }
    }

    return digits;
}

int main()
{
    // vector<int> digits = {1, 2, 3};
    // vector<int> digits = {4, 3, 2, 1};
    // vector<int> digits = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    vector<int> digits = {9, 9, 9};

    vector<int> result = plusOne(digits);

    for (auto i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}