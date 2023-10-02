#include <bits/stdc++.h>

using namespace std;

int mostWordsFound(vector<string> &sentences)
{
    int maxWordCount = 0;

    for (auto sentence : sentences)
    {
        int wordCount = 0;
        for (auto s : sentence)
            if (s == ' ')
                wordCount++;

        wordCount++;
        if (wordCount > maxWordCount)
            maxWordCount = wordCount;
    }

    return maxWordCount;
}

int main()
{

    vector<string> sentences = {"alice and bob love leetcode", "i think so too", "this is great thanks very much"};

    cout << mostWordsFound(sentences) << endl;

    return 0;
}