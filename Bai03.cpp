//MẢNG ĐỐI XỨNG

#include <bits/stdc++.h>
using namespace std;

void testcase(){
  int n;
  cin >> n;
  int a[n];
  for(auto &x : a) cin >> x;
  int gh = n / 2;
  for(int i = 0; i < n; i++){
    if(a[i] != a[n - 1 - i]){
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}

int main(){
  int t;
  cin >> t;
  cin.ignore();
  while(t--){
    testcase();
  }
  return 0;
}
