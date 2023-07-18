#include <bits/stdc++.h>
#include "stack.h"

int main()
{

    // Stack <int> stack = Stack<int>();

    // // for (int i = 0; i < 10; i++)
    // // {
    // //     stack.push(i + 1);
    // // }
    // stack.push(231);
    // stack.push(453);
    // stack.pop();
    // cout << "Size: " << stack.size() << endl;
    // cout << "Empty: " << stack.isEmpty() << endl;

    // int top = stack.topValue();
    // cout << top << endl;
    // cout << "===============================" << endl;

    Stack<pair<int, char>> st;

    st.push(make_pair(1, 'a'));
    st.push(make_pair(2, 'b'));
    st.push(make_pair(3, 'c'));

    cout << "Size: " << st.size() << endl;

    pair<int, char> p = st.pop();
    cout << p.first << "->" << p.second << endl;

    p = st.pop();
    cout << p.first << "->" << p.second << endl;

    p = st.pop();
    cout << p.first << "->" << p.second << endl;

    p = st.pop();
    cout << p.first << "->" << p.second << endl;

    // cout << ss.topValue()<< endl;

    return 0;
}