//CHIA HẾT CHO 2

#include <bits/stdc++.h>
using namespace std;

int check(){
  int n, cnt = 0;
  cin >> n;
  while(n % 2 == 0){
    cnt ++;
    n /= 2;
  }
  return cnt;
}

int main(){
  int t;
  cin >> t;
  cin.ignore();
  while(t--){
    cout << check() << endl;
  }
  return 0;
}

