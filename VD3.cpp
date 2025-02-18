#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int S = 0;
	for(int i = 0; i <= n; i++){
		S += pow(-1, i + 1) * i;
	}
	cout << S;
	return 0;
}
