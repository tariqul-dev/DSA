#include <bits/stdc++.h>
#include "stack.h"

using namespace std;


void reverseSentance(string sentance){
    string word = "";
    Stack <string>st;

    for (int i = 0; i < sentance.length(); i++)
    {
        if (sentance[i] != ' '){
            word += sentance[i];
        }else{
            cout << word << endl;
            st.push(word);
            word = "";
        }
    }

    cout << word << endl;
    st.push(word);

    while (!st.isEmpty())
    {
        cout << st.pop() << " ";
    }
    cout << endl;
    
}


int main(){

    string sentance = "I am Tariqul";

    reverseSentance(sentance);

    return 0;
}