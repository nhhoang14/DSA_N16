#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int interpolation_search(vector<int> a, int k){
    int l = 0, r = a.size() - 1;
    int pos;
    while (l <= r && k >= a[l] && k <= a[r]){
       pos = l + (((double)(r - l)/(a[r] - a[l]))*(k - a[l]));
       if(a[pos] == k) return 1;
       if(a[pos] > k) r = pos - 1;
       else l = pos + 1;
    }
    return 0;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    bool check = interpolation_search(a, k);
    if(check) cout << "FOUND";
    else cout << "NOT FOUND";
    return 0;
}
