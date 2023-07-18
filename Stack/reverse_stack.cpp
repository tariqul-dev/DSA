#include <bits/stdc++.h>
#include "stack.h"

using namespace std;

void insertBottom(Stack <int> &st, int stElement){
    if (st.isEmpty()){
        st.push(stElement);
        return;
    }

    int topElement = st.pop();
    cout << "bottom before: " << topElement << endl;

    insertBottom(st, stElement);

    st.push(topElement);
}



void reverseStack(Stack <int> &st){
    if (st.isEmpty()){
        return;
    }

    int topElement = st.pop();

    cout << "reverse before: " << topElement << endl;

    reverseStack(st);    

    insertBottom(st, topElement);
}


int main(){

    Stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    reverseStack(st);

    while (!st.isEmpty())
    {
        cout << st.pop() << endl;
    }
    

    return 0;
}