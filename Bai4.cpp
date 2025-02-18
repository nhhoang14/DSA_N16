//PHÂN TÍCH THỪA SỐ NGUYÊN TỐ

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; 
    cin >> t;
    for(int i = 1; i <= t; i++){
        int n;
        cin >> n;
        cout << "Test" << " " << i << ":" << " ";
        for(int j = 2; j <= sqrt(n); j++){
            if(n % j == 0){
                int dem = 0;
                while(n % j == 0){
                    dem++;
                    n /= j;
                }
                cout << j << "(" << dem << ")" << " ";
            }
        }
        if(n > 1){
            cout << n << "(1)";
        }
        cout << endl;
    }
    return 0;
}
