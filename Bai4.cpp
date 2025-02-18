#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; 
    cin >> t;
    for(int i = 1; i <= t; i++){
        int n;
        cin >> n;
        cout << "Test" << " " << i << ":" << " ";
        for(int i = 2; i <= sqrt(n); i++){
            if(n % i == 0){
                int dem = 0;
                while(n % i == 0){
                    dem++;
                    n /= i;
                }
                cout << i << "(" << dem << ")" << " ";
            }
        }
        if(n > 1){
            cout << n << "(1)";
        }
        cout << endl;
    }
    return 0;
}
