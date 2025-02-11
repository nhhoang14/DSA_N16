#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  float s = 0, i = 0;
  while( i <= n){
    s += (float)(2*i + 1)/ (2 * i + 2);
    i ++;
  }
  cout << s;
  return 0;
}
