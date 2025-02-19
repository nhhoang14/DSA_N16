//VÒNG TRÒN

#include <bits/stdc++.h>
using namespace std;

string loc(string s){
    string res = "";
    res.push_back(s[0]);
    for(int i = 1; i < s.length(); i ++){
        int pos = res.length();
        if(s[i] != res[pos - 1]) res.push_back(s[i]);
        else res.pop_back();
    }
    return res;
}

int main(){
    string s;
    cin >> s;
    s = loc(s);
    cout << s;
    return 0;
}
