//MẢNG ĐỐI XỨNG

#include <bits/stdc++.h>
using namespace std;

int check(){
  int n;
  cin >> n;
  int a[n];
  for(auto &x : a) cin >> x;
  int gh = n / 2;
  for(int i = 0; i < n; i++){
    if(a[i] != a[n - 1 - i]) return 0;
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

