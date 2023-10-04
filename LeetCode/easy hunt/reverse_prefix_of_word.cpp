#include <bits/stdc++.h>

using namespace std;

void reverseStr(string &word, int i, int j)
{
    while (i < j)
        swap(word[i++], word[j--]);
}

string reversePrefix(string word, char ch)
{
    int start = 0, finish = -1;

    for (int i = 0; i < word.size(); i++)
    {
        if (word[i] == ch)
        {
            finish = i;
            break;
        }
    }

    reverseStr(word, start, finish);

    return word;
}

int main()
{
    string word = "abcd";
    char ch = 'z';

    cout << reversePrefix(word, ch) << endl;

    return 0;
}