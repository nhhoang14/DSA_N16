//SỐ TĂNG GIẢM

#include <bits/stdc++.h>
using namespace std;

int check(){
  string s;
  cin >> s;
  bool tang = true;
  bool giam = true;
  for(int i = 1; i < s.length(); i++){
    if(s[i] > s[i - 1]) giam = false;
    if(s[i] < s[i - 1]) tang = false;
  }
  return giam || tang;
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
