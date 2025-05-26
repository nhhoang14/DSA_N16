#include <bits/stdc++.h>
using namespace std;

int n, x[100];
bool cot[100], xuoi[100], nguoc[100];

void Try(int i){
	for(int j = 1; j <= n; j++){
		if(cot[j] && xuoi[i - j + n] && nguoc[i + j - 1]){
			x[i] = j;
			cot[j] = false;
			xuoi[i - j + n] = false;
			nguoc[i + j - 1] = false;
			if(i == n){
                for(int i = 1; i <= n; i++)
                    cout << "(" << i << "," << x[i] << ")" << " ";
                cout << endl;
			} 
			else Try(i + 1);
			cot[j] = true;
			xuoi[i - j + n] = true;
			nguoc[i + j - 1] = true;
		}
	}
}
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++)
		cot[i] = true;
	for(int i = 1; i <= 2 * n; i++){
		xuoi[i] = true;
		nguoc[i] = true;
	}
	Try(1);
	return 0;
}
