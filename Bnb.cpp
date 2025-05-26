#include <bits/stdc++.h>

using namespace std;

const int maxn = 21;
int n, S, cnt, cnt_best, sum, a[maxn], mark[maxn], mark_best[maxn], maxmoney[maxn];

void create_data(){
    cnt_best = n + 1;
    maxmoney[n] = a[n];
    for (int i = n - 1; i >= 0; --i)
        maxmoney[i] = max(maxmoney[i + 1], a[i]);
}

void update_best_solution(){
    if (sum == S && cnt < cnt_best){
        cnt_best = cnt;
        for (int i = 1; i <= n; ++i)
            mark_best[i] = mark[i];
    }
}

void branch_and_bound(int i){
    if (cnt + (S - sum) / maxmoney[i + 1] >= cnt_best) return;
    for (int j = 0; j <= 1; ++j){
        sum = sum + a[i] * j; 
        mark[i] = j;
        cnt += j;
        if (i == n) update_best_solution();
        else if (sum <= S) branch_and_bound(i + 1);
        sum -= a[i] * j;
        cnt -= j;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> S;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    create_data();
    branch_and_bound(1);
    if (cnt_best == n + 1)
        cout << -1;
    else {
        cout << cnt_best << endl;
        for (int i = 1; i <= n; ++i)
            if (mark_best[i])
                cout << a[i] << ' ';
    }
    return 0;
}
