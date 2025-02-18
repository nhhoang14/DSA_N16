//SỐ TĂNG GIẢM

#include <bits/stdc++.h>
using namespace std;

int check(){
  string s;
  cin >> s;
  for(int i = 0; i < s.length() - 2; i++){
    if(s[i] > s[i + 1] && s[i + 1] < s[i + 2])return 0;
    else if (s[i] < s[i + 1] && s[i + 1] > s[i + 2])return 0;
  }
  return 1;
}

int main(){
  int t;
  cin >> t;
  cin.ignore();
  while(t--){
    if(check()) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
