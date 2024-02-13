#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string &word)
{

    int i = 0, j = word.length() - 1;

    while (i < j)
    {
        if (word[i] != word[j])
            return false;

        i++, j--;
    }

    return true;
}

string firstPalindrome(vector<string> &words)
{
    for (string &word : words)
    {
        if (isPalindrome(word))
        {
            return word;
        }
    }

    return "";
}

int main()
{

    vector<string> words = {"abc", "car", "ada", "racecar", "cool"};

    cout << firstPalindrome(words) << endl;
    return 0;
}