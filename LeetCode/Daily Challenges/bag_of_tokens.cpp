#include <bits/stdc++.h>

using namespace std;

int bagOfTokensScore(vector<int> &tokens, int power)
{
    int n = tokens.size();
    int i = 0, j = n - 1;
    int maxScore = 0;
    int score = 0;

    sort(tokens.begin(), tokens.end());

    while (i <= j)
    {
        if (power >= tokens[i])
        {
            power -= tokens[i];
            score += 1;
            maxScore = max(maxScore, score);
            i++;
        }
        else if (score >= 1)
        {
            power += tokens[j];
            score -= 1;
            j--;
        }
        else
        {
            return maxScore;
        }
    }

    return maxScore;
}

int main()
{

    vector<int> tokens = {100, 200, 300, 400};
    int power = 200;

    cout << bagOfTokensScore(tokens, power);

    return 0;
}