#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int binary_search(vector<int> a, int k){
    int l = 0, r = a.size() - 1;
    while (l <= r){
        int m = (l + r) / 2;
        if(a[m] == k) return 1;
        if(a[m] < k) l = m + 1;
        else r = m - 1;
    }
    return 0;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    bool check = binary_search(a, k);
    if(check) cout << "FOUND";
    else cout << "NOT FOUND";
    return 0;
}