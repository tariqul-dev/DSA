#include <bits/stdc++.h>

using namespace std;

// tc(n) sc(n)
// int maxDepth(string s)
// {
//     int n = s.length();
//     int depth = 0;

//     stack<char> st;

//     for (int i = 0; i < n; i++)
//     {
//         if (s[i] == '(')
//         {
//             st.push(s[i]);
//             int size = st.size();
//             depth = max(depth, size);
//         }

//         if (s[i] == ')' && !st.empty())
//         {
//             st.pop();
//         }
//     }

//     return depth;
// }


// tc(n) sc(1)
int maxDepth(string s)
{
    int n = s.length();
    int depth = 0;

    int size = 0;

    for(int i = 0; i < n; i++){
        if (s[i] == '('){
            size++;
            depth = max(depth, size);
        }

        if (s[i] == ')'){
            size--;
        }
    }
    
    return depth;
}

int main()
{

    string s = "(1+(2*3)+((8)/4))+1";

    cout << maxDepth(s) << endl;

    return 0;
}