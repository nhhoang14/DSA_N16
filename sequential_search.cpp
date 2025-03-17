#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int sequential_search(vector<int> a, int n){
    for(auto x : a){
        if(x == n) return 1;
    }
    return 0;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    bool check = sequential_search(a, k);
    if(check) cout << "FOUND";
    else cout << "NOT FOUND";
    return 0;
}