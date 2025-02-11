#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  float s = 0, i = 0;
  while( i <= n){
    s += i;
    i ++;
  }
  cout << s;
  return 0;
}
