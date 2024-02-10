#include <bits/stdc++.h>

using namespace std;

int dp[1000][1000];

bool check(int i, int j, string s)
{

    if (i > j)
        return true;

    if (dp[i][j] != -1){
        return dp[i][j];
    }    

    if (s[i] == s[j])
    {
        return dp[i][j] = check(i + 1, j - 1, s);
    }

    return dp[i][j] = false;
}

int countSubstrings(string s)
{
    int n = s.length();

    int count = 0;

    memset(dp, -1, sizeof(dp));

    for(int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            if (check(i, j, s)){
                count++;
            }
        }
    }

    return count;
}

int main()
{

    string s = "aaa";

    cout << countSubstrings(s) << endl;

    return 0;
}