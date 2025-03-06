#include<bits/stdc++.h>
using namespace std;

void selection_sort(vector<int> &a, int n){
	for(int i = 0; i < n - 1; i++){
		int pos = i;
		for(int j = i + 1; j < n; j++)
			if(a[j] < a[pos]) pos = j;
		swap(a[i], a[pos]);
	}
}

int main(){	
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &x : a) cin >> x;
	selection_sort(a, n);
	for(auto x : a) cout << x << " ";
	return 0;
}
