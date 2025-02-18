//ƯỚC SỐ CHUNG LỚN NHẤT VÀ BỘI SỐ CHUNG NHỎ NHẤT

#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  cin.ignore();
  while(t--){
    int a, b;
    cin >> a >> b;
    cout << __gcd(a,b) << " " << lcm(a,b) << endl;
  }
  return 0;
}
