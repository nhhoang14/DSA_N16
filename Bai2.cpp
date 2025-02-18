//BẮT ĐẦU VÀ KẾT THÚC

#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  cin.ignore();
  while(t--){
    string s;
    cin >> s;
    if(s[0] == s[s.length() - 1]) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}

