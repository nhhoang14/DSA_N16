#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// chia va tri
//O(nlogn)
// tron 2 day con: day 1:[l, m]; day 2: [m+1, r]

void merge(vector<int> &res, int l, int m, int r){
    vector<int> x(res.begin() + l, res.begin() + m + 1);
    vector<int> y(res.begin() + m + 1, res.begin() + r + 1);
    int i = 0, j = 0;
    while (i < x.size() && j < y.size()){
        if(x[i] < y[j]){
            res[l++] = x[i++];
        } else {
            res[l++] = y[j++];
        }
    }
    while(i < x.size()){
		res[l++] = x[i++];
	}
	while(j < y.size()){
		res[l++] = y[j++];
	}
}

void merge_sort(vector<int> &res, int l, int r){
    if(l >= r) return;
    int m = (l + r)/2;
    merge_sort(res, l, m);
    merge_sort(res, m + 1, r);
    merge(res, l, m, r);
}

int main(){
	int n;
        cin >> n;
        vector<int> a(n);
        for(auto &x : a) cin >> x;
        merge_sort(a, 0, n - 1);
        for(auto x : a) cout << x << " ";
        return 0;
}
