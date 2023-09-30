#include <bits/stdc++.h>

using namespace std;

int lengthOfLastWord(string s)
{
    int index = s.size() - 1;
    int len = 0;

    while (index >= 0 && s[index] == ' ')
        index--;

    while (index >= 0 && s[index] != ' ')
        index--, len++;


    return len;
}

int main()
{
    string s = "luffy is still joyboy";

    cout << lengthOfLastWord(s) << endl;

    return 0;
}