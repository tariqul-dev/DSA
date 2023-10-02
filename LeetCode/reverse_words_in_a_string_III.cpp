#include <bits/stdc++.h>

using namespace std;

void reverseInRange(int low, int high, string &s)
{
    while (low <= high)
        swap(s[low++], s[high--]);
}

string reverseWords(string s)
{
    int low = 0, high = 0;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] != ' ')
            high = i;
        else
        {
            reverseInRange(low, high, s);
            low = i + 1;
        }
    }
    reverseInRange(low, high, s);

    return s;
}

int main()
{

    string s = "Let's take LeetCode contest";

    cout << reverseWords(s) << endl;

    return 0;
}