#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int a[1000];

void quick_sort(int left, int right){
	int i = left, j = right;
	int pivot = (left + right)/2;
	do{
		while(a[i] < a[pivot] && i < right) i++;
		while(a[j] > a[pivot] && j > left) j--;
		if(i <= j){
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}while(i <= j);
	if(left < j) quick_sort(left,j);
	if(i < right) quick_sort(i,right);
}

int main(){	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 0; i < n; i++) cin >> a[i];
		quick_sort(0, n-1);
		for(int i = 0; i < n; i++) cout << a[i] << " ";
		cout << endl;
	}
	return 0;
}
