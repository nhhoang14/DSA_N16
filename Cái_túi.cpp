#include <bits/stdc++.h>
using namespace std;

void qhd(int a[], int c[], int n, int v){
	vector<vector<int>> dp(n + 1, vector<int>(v + 1, 0));
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= v; j++){
			dp[i][j] = dp[i - 1][j]; 
			if(j >= a[i - 1]){
				dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i - 1]] + c[i - 1]);
			}
		}
	}
	cout << dp[n][v] << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, v;
		cin >> n >> v;
		int a[n], c[n];
		for(auto &x : a) cin >> x;
	    for(auto &x : c) cin >> x;
		qhd(a, c, n, v);
	}
	return 0;
}
