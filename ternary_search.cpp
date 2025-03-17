#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int ternary_search(vector<int> a, int k){
    int l = 0, r = a.size() - 1;
    while (l <= r){
        int m1 = l + (r - l)/3;
        int m2 = r - (r - l)/3;
        if(a[m1] == k || a[m2] ==k) return 1;
        if(a[m1] > k) r = m1 - 1;
        else if(a[m2] < k) l = m2 + 1;
        else{
            l = m1 + 1;
            r = m2 - 1;
        }
    }
    return 0;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    bool check = ternary_search(a, k);
    if(check) cout << "FOUND";
    else cout << "NOT FOUND";
    return 0;
}
