#include <bits/stdc++.h>

using namespace std;

int romanToInt(string s)
{
    map<string, int> table;
    table["I"] = 1;
    table["V"] = 5;
    table["X"] = 10;
    table["L"] = 50;
    table["C"] = 100;
    table["D"] = 500;
    table["M"] = 1000;

    table["IV"] = 4;
    table["IX"] = 9;
    table["XL"] = 40;
    table["XC"] = 90;
    table["CD"] = 400;
    table["CM"] = 900;

    int sum = 0;

    for (int i = 0; i < s.size(); i++)
    {
        string current = string(1, s[i]);
        string next = "";

        if (i + 1 < s.size())
        {
            next = string(1, s[i + 1]);
        }

        string comboString = current + next;

        if (table.find(comboString) != table.end())
        {
            sum += table[comboString];
            i++;
        }
        else
        {
            sum += table[current];
        }
    }

    return sum;
}

int main()
{
    string s = "III";

    cout << romanToInt(s) << endl;

    return 0;
}