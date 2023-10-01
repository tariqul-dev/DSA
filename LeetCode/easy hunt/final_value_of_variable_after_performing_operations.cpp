#include <bits/stdc++.h>

using namespace std;

int finalValueAfterOperations(vector<string> &operations)
{
    int x = 0;
    for (auto ele : operations)
        if (ele == "X++" || ele == "++X")
            x++;
        else
            x--;

    return x;
}

int main()
{
    vector<string> operations = {"X++","++X","--X","X--"};

    cout << finalValueAfterOperations(operations) << endl;

    return 0;
}