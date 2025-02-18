//PHÉP CỘNG

#include <bits/stdc++.h>
using namespace std;

int main(){
  string s, res = "";
  getline(cin, s);
  stringstream ss(s);
  char word;
  while (ss >> word){
    if(isdigit(word)) res += word;
  }
  int a = res[0] - '0', b = res[1] - '0', c = res[2] - '0';
  if(a + b == c) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
