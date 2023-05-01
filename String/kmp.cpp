#include <bits/stdc++.h>

using namespace std;

template <class T>
void print_v(vector<T> &vect)
{
    for (auto element : vect)
    {
        cout << element << " ";
    }

    cout << endl;
}

vector<int> createLps(string pattern)
{
    vector<int> arr(pattern.size());

    arr[0] = 0;
    int index = 0, i = 1;

    while (i < pattern.size())
    {
        if (pattern[index] == pattern[i])
            arr[i++] = ++index;

        else if (index != 0)
            index = arr[--index];
        else
            arr[i++] = index;
    }

    return arr;
}

void kmp(string text, string pattern)
{
    vector<int> lps = createLps(pattern);

    print_v(lps);

    int i = 0, j = 0;

    bool isFound = false;

    while (i < text.size())
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }

        if (j == pattern.size())
        {
            isFound = true;
            break;
        }
    }

    if (isFound)
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;
}

int main()
{

    string text = "ababaaab";
    string pattern = "abaa";

    kmp(text, pattern);

    return 0;
}