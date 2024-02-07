#include <bits/stdc++.h>

using namespace std;

typedef pair<char, int> P;

string frequencySort(string s)
{
    vector<P> freqArr(123);

    for (char &ch : s)
    {
        int freq = freqArr[ch].second;

        freqArr[ch] = {ch, freq + 1};
    }

    auto lambda = [&](P &p1, P &p2)
    {
        return p1.second > p2.second;
    };

    sort(freqArr.begin(), freqArr.end(), lambda);

    string result = "";

    for (int i = 0; i < 123; i++)
    {
        if (freqArr[i].second > 0)
        {
            char ch = freqArr[i].first;
            int freq = freqArr[i].second;

            string temp = string(freq, ch);

            result += temp;
        }
    }

    return result;
}

int main()
{
    string s = "tree";

    cout << frequencySort(s) << endl;

    return 0;
}