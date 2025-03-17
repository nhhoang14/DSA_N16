#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int fibonacci_search(vector<int> a, int k){
    int n = a.size();
    int fibom2 = 0, fibom1 = 1;
    int fibom = fibom2 + fibom1;
    while(fibom < n){
        fibom2 = fibom1;
        fibom1 = fibom;
        fibom = fibom2 + fibom1;
    }
    int offset = -1;
    while (fibom > 1){
        int i = min(offset + fibom2, n - 1);
        if(a[i] < k){
            fibom = fibom1;
            fibom1 = fibom2;
            fibom2 = fibom - fibom1;
            offset = i;
        }
        else if(a[i] > k){
            fibom = fibom2;
            fibom1 = fibom1 - fibom2;
            fibom2 = fibom - fibom1;
        }
        else return 1;
    }
    if(fibom2 == 1 && a[offset + 1] == k) return 1;
    return 0;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    bool check = fibonacci_search(a, k);
    if(check) cout << "FOUND";
    else cout << "NOT FOUND";
    return 0;
}
