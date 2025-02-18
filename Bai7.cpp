//CHUẨN HÓA 1

#include <bits/stdc++.h>
using namespace std;

void chuanhoa(string &s){
  s[0] = toupper(s[0]);
  for(int i = 1; i < s.length(); i++){
    s[i] = tolower(s[i]);
  }
}

int main(){
  int t;
  cin >> t;
  cin.ignore();
  while(t--){
    string s, res = "";
    getline(cin,s);
    stringstream ss(s);
    string word;
    while (ss >> word){
      chuanhoa(word);
      res += word + " ";
    }
    res.pop_back();
    cout << res << endl;
  }
  return 0;
}

