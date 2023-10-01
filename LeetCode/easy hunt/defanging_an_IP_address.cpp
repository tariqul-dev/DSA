#include <bits/stdc++.h>

using namespace std;

string defangIPaddr(string address)
{
    string newAddress = "";

    for (char a : address)
    {
        if (a == '.')
        {
            newAddress += "[.]";
            continue;
        }
        newAddress += a;
    }

    return newAddress;
}

int main()
{
    string address = "255.100.50.0";

    cout << defangIPaddr(address) << endl;

    return 0;
}