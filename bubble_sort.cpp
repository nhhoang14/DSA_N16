#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// sap xep noi bot, neu so 1 lon hon so 2 -> swap 1 voi 2
//O(n^2)

void bubble_sort(int a[], int n){
	for(int i = 0; i < n - 1; i++)
		for(int j = 0; j < n - i - 1; j++)
			if(a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
}

int main(){
	int a[10000], n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	bubble_sort(a, n);
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}
