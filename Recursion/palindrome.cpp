#include <bits/stdc++.h>

using namespace std;

bool checkPalindrone(string &s, int i){

    if (i >= s.size() / 2) return true;

    if (s[i] != s[s.size() - i - 1]){
        return false;
    }
    
    return checkPalindrone(s, i + 1);
}

int main(){

    string s;
    cin >> s;

    cout << s << endl;

    cout << checkPalindrone(s, 0) << endl;



    return 0;
}