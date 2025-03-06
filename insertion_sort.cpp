#include<bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &a, int n){
	for(int i = 1; i < n; i++){
		int pos = i, tmp = a[i];
		while (pos > 0 && a[pos - 1] > tmp){
			a[pos] = a[pos - 1];
			pos --;
		}
		a[pos] = tmp;
	}
}

int main(){	
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &x : a) cin >> x;
	insertion_sort(a, n);
	for(auto x : a) cout << x << " ";
	return 0;
}
